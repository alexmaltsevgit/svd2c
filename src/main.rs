use std::{
    collections::{HashMap, HashSet},
    env,
    fs::{self, File},
    io::{BufWriter, Write},
    path::Path,
};

use quick_xml::{events::Event, reader::Reader};
use strfmt::strfmt;

struct Device {
    name: String,
}

#[derive(Default, Clone)]
struct Peripheral {
    name: String,
    description: String,
    base_address: String,
    group_name: Option<String>,
    registers: Vec<Register>,
}

#[derive(Default, Clone)]
struct Register {
    name: String,
    description: String,
    address_offset: u32,
    alternate_register: Option<String>,
    size_bits: u8,
    reset_value: String,
    fields: Vec<Field>,
}

#[derive(Default, Clone)]
struct Field {
    name: String,
    description: String,
    bit_offset: u16,
    bit_width: u8,
    enum_values: Vec<EnumValue>,
}

#[derive(Default, Clone)]
struct EnumValue {
    name: String,
    description: String,
    value: u32,
}

enum TranspilerContext {
    Awaiting,
    Device,
    Cpu,
    Peripherals,
    PeripheralGroup,
    Interrupt,
    Register,
    Field,
    Enum,
    EnumValue,
}

struct Writer {
    output: BufWriter<File>,
    ready_groups: HashSet<String>,
}

impl Writer {
    fn open(path: &str) -> std::io::Result<Self> {
        let path = Path::new(path);

        if let Some(parent) = path.parent() {
            fs::create_dir_all(parent)?;
        }

        Ok(Self {
            output: BufWriter::new(
                File::create(path).expect(
                    format!(
                        "Error on opening file for output: {}",
                        path.to_string_lossy()
                    )
                    .as_str(),
                ),
            ),
            ready_groups: HashSet::new(),
        })
    }

    fn w_opening(&mut self, device_name: &str) {
        let t = include_str!("../templates/opening.h");

        self.output
            .write_all(&t.replace("{name}", device_name).into_bytes())
            .expect("Write error");
    }

    fn w_peripheral(&mut self, peripheral: &Peripheral) {
        let Some(gp) = peripheral.group_name.clone() else {
            return self.w_new_peripheral(peripheral);
        };

        if self.ready_groups.contains(&gp) {
            self.w_existing_peripheral(peripheral);
        } else {
            self.w_new_peripheral(peripheral);
            self.ready_groups.insert(gp);
        }
    }

    fn w_new_peripheral(&mut self, peripheral: &Peripheral) {
        let t = include_str!("../templates/new_peripheral.h");

        let registers = self.make_registers(&peripheral.registers);

        let mut all_fields = String::with_capacity(peripheral.registers.len() * 64);
        for reg in peripheral.registers.iter() {
            let fields = self.make_fields(
                &peripheral
                    .group_name
                    .clone()
                    .unwrap_or(peripheral.name.clone()),
                &reg.name,
                &reg.fields,
            );
            all_fields.push_str(fields.as_str());
        }

        let mut vars = HashMap::new();
        vars.insert("name".to_string(), peripheral.name.as_str());
        vars.insert("base_address".to_string(), peripheral.base_address.as_str());
        vars.insert("description".to_string(), peripheral.description.as_str());
        vars.insert("registers".to_string(), &registers);
        vars.insert(
            "group_name".to_string(),
            peripheral.group_name.as_ref().unwrap_or(&peripheral.name),
        );

        self.output
            .write_all(&strfmt(&t, &vars).unwrap().into_bytes())
            .expect("Write error");

        self.w_asserts(
            peripheral.group_name.as_ref().unwrap_or(&peripheral.name),
            &peripheral.registers,
        );

        self.output
            .write_all(all_fields.as_bytes())
            .expect("Write error");
    }

    fn w_existing_peripheral(&mut self, peripheral: &Peripheral) {
        let t = include_str!("../templates/existing_peripheral.h");

        let mut vars = HashMap::new();
        vars.insert("name".to_string(), peripheral.name.as_str());
        vars.insert("base_address".to_string(), peripheral.base_address.as_str());
        vars.insert(
            "group_name".to_string(),
            peripheral.group_name.as_ref().unwrap(),
        );

        self.output
            .write_all(&strfmt(&t, &vars).unwrap().into_bytes())
            .expect("Write error");
    }

    fn make_registers(&mut self, registers: &[Register]) -> String {
        let t = include_str!("../templates/register.h");
        let mut out = String::with_capacity(registers.len() * 64);

        let mut fillers: Vec<(isize, u32)> = Vec::new();

        for (idx, w) in registers.windows(2).enumerate() {
            // when first register needs __RESERVED padding before
            if idx == 0 && w[0].address_offset > 0 {
                fillers.push((-1, w[0].address_offset));
            }

            if let Some(_) = &w[1].alternate_register {
                continue;
            }

            let size_bytes = w[0].size_bits as u32 / 8;
            let diff = w[1].address_offset - w[0].address_offset - size_bytes;

            if diff == 0 {
                continue;
            }

            if diff % size_bytes != 0 {
                panic!("Error in reservation fillers computation");
            }
            fillers.push((idx as isize, diff / size_bytes));
        }

        let mut fillers_n = 0;
        for (idx, reg) in registers.iter().enumerate() {
            if let Some(_) = reg.alternate_register {
                continue;
            }

            let size_bits = reg.size_bits.to_string();

            // zero filler
            if let Some(filler) = fillers.get(0)
                && filler.0 == -1
                && idx == 0
            {
                self.buff_register_filler(
                    &mut out,
                    &8.to_string(),
                    &fillers_n.to_string(),
                    filler.1,
                );
                fillers_n += 1;
            }

            let mut vars = HashMap::new();
            vars.insert("description".to_string(), reg.description.as_str());
            vars.insert("size_bits".to_string(), &size_bits);
            vars.insert("name".to_string(), reg.name.as_str());

            out.push_str(&strfmt(&t, &vars).unwrap());

            for filler in fillers.iter() {
                if filler.0 != idx as isize {
                    continue;
                }

                self.buff_register_filler(&mut out, &size_bits, &fillers_n.to_string(), filler.1);
                fillers_n += 1;
            }
        }

        out
    }

    fn make_enum_values(
        &mut self,
        group_name: &str,
        register_name: &str,
        field_name: &str,
        enum_values: &[EnumValue],
    ) -> String {
        let t = include_str!("../templates/enumerated_value.h");
        let mut out = String::with_capacity(enum_values.len() * 64);

        for v in enum_values {
            let value_str = format!("0x{:x}", v.value);

            let mut vars = HashMap::new();
            vars.insert("description".to_string(), v.description.as_str());
            vars.insert("group_name".to_string(), group_name);
            vars.insert("register".to_string(), register_name);
            vars.insert("field".to_string(), field_name);
            vars.insert("name".to_string(), &v.name);
            vars.insert("value".to_string(), &value_str);

            out.push_str(&strfmt(&t, &vars).unwrap());
        }

        out
    }

    fn buff_register_filler(&mut self, out: &mut String, size_bits: &str, n: &str, count: u32) {
        let count_string = count.to_string();

        let reserved_one_t = include_str!("../templates/reserved_one.h");
        let reserved_many_t = include_str!("../templates/reserved_many.h");

        let t = if count == 1 {
            reserved_one_t
        } else {
            reserved_many_t
        };

        let mut vars = HashMap::new();
        vars.insert("size_bits".to_string(), size_bits);
        vars.insert("n".to_string(), n);
        vars.insert("count".to_string(), &count_string);

        out.push_str(&strfmt(&t, &vars).unwrap());
    }

    fn w_asserts(&mut self, group_name: &str, registers: &[Register]) {
        let t = include_str!("../templates/assert.h");
        let mut out = String::with_capacity(registers.len() * 64);

        for reg in registers.iter() {
            if let Some(_) = reg.alternate_register {
                continue;
            }

            let offset = format!("0x{:x}", reg.address_offset);

            let mut vars = HashMap::new();
            vars.insert("group_name".to_string(), group_name);
            vars.insert("register".to_string(), &reg.name);
            vars.insert("offset".to_string(), offset.as_str());

            out.push_str(&strfmt(&t, &vars).unwrap());
        }

        self.output.write_all(out.as_bytes()).expect("Write error");
    }

    fn make_fields(&mut self, group_name: &str, register_name: &str, fields: &[Field]) -> String {
        let mut out = String::with_capacity(fields.len() * 64);

        let reserved_one_t = include_str!("../templates/field.h");
        let reserved_many_t = include_str!("../templates/field_enumerated.h");

        for field in fields.iter() {
            let t = if field.enum_values.is_empty() {
                reserved_one_t
            } else {
                reserved_many_t
            };

            let offset = field.bit_offset.to_string();
            let width = format!("0x{:x}", (1u64 << field.bit_width) - 1);

            let enum_values =
                self.make_enum_values(group_name, register_name, &field.name, &field.enum_values);

            let mut vars = HashMap::new();
            vars.insert("description".to_string(), field.description.as_str());
            vars.insert("group_name".to_string(), group_name);
            vars.insert("register_name".to_string(), register_name);
            vars.insert("field_name".to_string(), field.name.as_str());
            vars.insert("offset".to_string(), offset.as_str());
            vars.insert("width".to_string(), width.as_str());
            vars.insert("enum".to_string(), &enum_values);

            out.push_str(&strfmt(&t, &vars).unwrap());
        }

        out
    }

    fn w_ending(&mut self) {
        let t = include_str!("../templates/ending.h");

        self.output.write_all(t.as_bytes()).expect("Write error");
    }
}

struct Parser {
    context: TranspilerContext,
    field_name: String,

    device: Device,

    derivers: HashMap<String, Peripheral>,

    new_peripheral: Option<Peripheral>,
    new_register: Option<Register>,
    new_field: Option<Field>,
    new_enum_value: Option<EnumValue>,
}

impl Parser {
    fn new() -> Self {
        Parser {
            context: TranspilerContext::Awaiting,
            field_name: String::default(),
            device: Device {
                name: "Unknown".into(),
            },
            derivers: HashMap::new(),
            new_peripheral: None,
            new_register: None,
            new_field: None,
            new_enum_value: None,
        }
    }

    fn commit_new_peripheral(&mut self) {
        let p = self
            .new_peripheral
            .as_ref()
            .expect("Tried to write peripheral in invalid state");

        if !self.derivers.contains_key(&p.name) {
            self.derivers.insert(p.name.to_string(), p.clone());
        }

        self.new_peripheral = None;
        self.new_register = None;
        self.new_field = None;
    }

    fn commit_new_register(&mut self) {
        let p = self
            .new_peripheral
            .as_mut()
            .expect("Tried to commit Register outside of Peripheral");

        p.registers.push(
            self.new_register
                .as_ref()
                .expect("Tried to commit Register in invalid state")
                .clone(),
        );

        p.registers.sort_by_key(|i| i.address_offset);

        self.new_register = None;
        self.new_field = None;
    }

    fn commit_new_field(&mut self) {
        self.new_register
            .as_mut()
            .expect("Tried to commit Field outside of Register")
            .fields
            .push(
                self.new_field
                    .as_ref()
                    .expect("Tried to commit Field in invalid state")
                    .clone(),
            );

        self.new_field = None;
    }

    fn commit_new_enum_value(&mut self) {
        self.new_field
            .as_mut()
            .expect("Tried to commit EnumValue outside of Field")
            .enum_values
            .push(
                self.new_enum_value
                    .as_ref()
                    .expect("Tried to commit EnumValue in invalid state")
                    .clone(),
            );

        self.new_enum_value = None;
    }
}

fn main() -> std::io::Result<()> {
    let args: Vec<String> = env::args().collect();

    let input_file_path = args
        .get(1)
        .expect("Provide input file path as 1st argument")
        .as_str();

    let input_filename = Path::new(input_file_path)
        .file_stem()
        .expect("Filename not found")
        .to_str()
        .expect("Filename decoding failure (utf-8)");

    let default_output_filename = &format!("{}.h", input_filename.to_lowercase());
    let output_file_path = args.get(2).unwrap_or(default_output_filename).as_str();

    let mut writer = Writer::open(output_file_path)?;

    let mut reader = Reader::from_file(input_file_path)
        .expect(format!("Error on opening file for input: {}", input_file_path).as_str());

    reader.config_mut().trim_text(true);

    let mut buf = Vec::new();

    let mut parser = Parser::new();

    loop {
        match reader.read_event_into(&mut buf) {
            Err(e) => panic!("Error at position {}: {:?}", reader.error_position(), e),

            Ok(Event::Start(event)) => {
                let event_name = event.name();

                parser.field_name = std::str::from_utf8(event_name.as_ref())
                    .expect("Field name is not utf-8")
                    .to_owned();

                match event_name.as_ref() {
                    b"device" => {
                        parser.context = TranspilerContext::Device;
                    }

                    b"cpu" => {
                        parser.context = TranspilerContext::Cpu;
                    }

                    b"peripherals" => {
                        parser.context = TranspilerContext::Peripherals;
                        writer.w_opening(&parser.device.name);
                    }

                    b"peripheral" => {
                        parser.context = TranspilerContext::PeripheralGroup;

                        let deriver_name = event
                            .try_get_attribute("derivedFrom")
                            .expect("Attribute error")
                            .map(|attr| {
                                std::str::from_utf8(attr.value.as_ref())
                                    .expect("derivedFrom is not UTF-8")
                                    .to_owned()
                            });

                        parser.new_peripheral = Some(
                            deriver_name
                                .as_ref()
                                .and_then(|dn| parser.derivers.get(dn))
                                .cloned()
                                .unwrap_or_default(),
                        );
                    }

                    b"interrupt" => {
                        parser.context = TranspilerContext::Interrupt;
                    }

                    b"register" => {
                        parser.context = TranspilerContext::Register;
                        parser.new_register = Some(Register::default());
                    }

                    b"field" => {
                        parser.context = TranspilerContext::Field;
                        parser.new_field = Some(Field::default());
                    }

                    b"enumeratedValues" => {
                        parser.context = TranspilerContext::Enum;
                    }

                    b"enumeratedValue" => {
                        parser.context = TranspilerContext::EnumValue;
                        parser.new_enum_value = Some(EnumValue::default());
                    }

                    _ => (),
                }
            }

            Ok(Event::End(event)) => match event.name().as_ref() {
                b"device" => writer.w_ending(),
                b"peripheral" => {
                    writer.w_peripheral(parser.new_peripheral.as_ref().unwrap());
                    parser.commit_new_peripheral()
                }
                b"register" => parser.commit_new_register(),
                b"field" => parser.commit_new_field(),
                b"enumeratedValue" => parser.commit_new_enum_value(),
                _ => (),
            },

            Ok(Event::Text(event)) => {
                let text = event.decode().unwrap().into_owned();
                let is_hex = text.starts_with("0x");
                let radix = if is_hex { 16 } else { 10 };

                match parser.field_name.as_str() {
                    "name" => match parser.context {
                        TranspilerContext::Device => parser.device.name = text,

                        TranspilerContext::PeripheralGroup => {
                            parser
                                .new_peripheral
                                .as_mut()
                                .expect("'name' found outside of Peripheral")
                                .name = text
                        }
                        TranspilerContext::Register => {
                            parser
                                .new_register
                                .as_mut()
                                .expect("'name' found outside of Register")
                                .name = text
                        }
                        TranspilerContext::Field => {
                            parser
                                .new_field
                                .as_mut()
                                .expect("'name' found outside of Field")
                                .name = text
                        }
                        TranspilerContext::EnumValue => {
                            parser
                                .new_enum_value
                                .as_mut()
                                .expect("'name' found outside of EnumValue")
                                .name = text
                        }
                        _ => (),
                    },

                    "description" => match parser.context {
                        TranspilerContext::PeripheralGroup => {
                            parser
                                .new_peripheral
                                .as_mut()
                                .expect("'description' found outside of Peripheral")
                                .description = text
                        }
                        TranspilerContext::Register => {
                            parser
                                .new_register
                                .as_mut()
                                .expect("'description' found outside of Register")
                                .description = text
                        }
                        TranspilerContext::Field => {
                            parser
                                .new_field
                                .as_mut()
                                .expect("'description' found outside of Field")
                                .description = text
                        }
                        TranspilerContext::EnumValue => {
                            parser
                                .new_enum_value
                                .as_mut()
                                .expect("'name' found outside of EnumValue")
                                .description = text
                        }
                        _ => (),
                    },

                    "baseAddress" => match parser.context {
                        TranspilerContext::PeripheralGroup => {
                            parser
                                .new_peripheral
                                .as_mut()
                                .expect("'base_address' found outside of Peripheral")
                                .base_address = text
                        }
                        _ => (),
                    },

                    "groupName" => match parser.context {
                        TranspilerContext::PeripheralGroup => {
                            parser
                                .new_peripheral
                                .as_mut()
                                .expect("'group_name' found outside of Peripheral")
                                .group_name = Some(text)
                        }
                        _ => (),
                    },

                    "addressOffset" => match parser.context {
                        TranspilerContext::Register => {
                            parser
                                .new_register
                                .as_mut()
                                .expect("'address_offset' found outside of Register")
                                .address_offset =
                                u32::from_str_radix(text.strip_prefix("0x").unwrap_or(&text), radix)
                                    .expect("Could not parse size")
                        }
                        _ => (),
                    },

                    "size" => match parser.context {
                        TranspilerContext::Register => {
                            parser
                                .new_register
                                .as_mut()
                                .expect("'size' found outside of Register")
                                .size_bits =
                                u8::from_str_radix(text.strip_prefix("0x").unwrap_or(&text), radix)
                                    .expect("Could not parse size")
                        }
                        _ => (),
                    },

                    "resetValue" => match parser.context {
                        TranspilerContext::Register => {
                            parser
                                .new_register
                                .as_mut()
                                .expect("'reset_value' found outside of Register")
                                .reset_value = text
                        }
                        _ => (),
                    },

                    "alternateRegister" => match parser.context {
                        TranspilerContext::Register => {
                            parser
                                .new_register
                                .as_mut()
                                .expect("'alternate_register' found outside of Register")
                                .alternate_register = Some(text)
                        }
                        _ => (),
                    },

                    "bitOffset" => match parser.context {
                        TranspilerContext::Field => {
                            parser
                                .new_field
                                .as_mut()
                                .expect("'bit_offset' found outside of Field")
                                .bit_offset =
                                text.parse::<u16>().expect("Could not parse bitOffset")
                        }
                        _ => (),
                    },

                    "bitWidth" => match parser.context {
                        TranspilerContext::Field => {
                            parser
                                .new_field
                                .as_mut()
                                .expect("'bit_width' found outside of Field")
                                .bit_width = text.parse::<u8>().expect("Could not parse bitWidth")
                        }
                        _ => (),
                    },

                    "value" => match parser.context {
                        TranspilerContext::EnumValue => {
                            parser
                                .new_enum_value
                                .as_mut()
                                .expect("'value' found outside of EnumValue")
                                .value = u32::from_str_radix(
                                text.strip_prefix("0x").unwrap_or(&text),
                                radix,
                            )
                            .expect("Could not parse value");
                        }
                        _ => (),
                    },

                    _ => (),
                }
            }

            Ok(Event::Eof) => break,

            _ => (),
        }
    }

    return Ok(());
}
