use std::{
    collections::{HashMap, HashSet},
    env,
    fs::File,
    io::{BufWriter, Write},
    path::Path,
};

use quick_xml::{events::Event, reader::Reader};
use strfmt::strfmt;

struct Device {
    name: String,
}

#[derive(Default, Clone)]
struct PeripheralGroup {
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
    address_offset: String,
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
}

enum TranspilerContext {
    Awaiting,
    Device,
    Cpu,
    Peripherals,
    PeripheralGroup,
    Register,
    Field,
}

struct Writer {
    output: BufWriter<File>,
    ready_groups: HashSet<String>,
    templates_cache: HashMap<String, String>,
}

impl Writer {
    fn open(path: &str) -> Self {
        Self {
            output: BufWriter::new(
                File::create(path)
                    .expect(format!("Error on opening file for output: {}", path).as_str()),
            ),
            ready_groups: HashSet::new(),
            templates_cache: HashMap::new(),
        }
    }

    fn load_template(&mut self, name: &str) -> String {
        match self.templates_cache.get(name) {
            Some(t) => t.clone(),
            None => {
                let t = std::fs::read_to_string(format!("templates/{}", name))
                    .expect("Error on reading template");
                t
            }
        }
    }

    fn w_opening(&mut self, device_name: &str) {
        let t = self.load_template("opening.h");

        self.output
            .write_all(&t.replace("{name}", device_name).into_bytes())
            .expect("Write error");
    }

    fn w_peripheral(&mut self, peripheral: &PeripheralGroup) {
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

    fn w_new_peripheral(&mut self, peripheral: &PeripheralGroup) {
        let t = self.load_template("new_peripheral.h");

        let registers = self.make_registers(&peripheral.registers);

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
    }

    fn w_existing_peripheral(&mut self, peripheral: &PeripheralGroup) {
        let t = self.load_template("existing_peripheral.h");

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
        let t = self.load_template("register.h");
        let mut out = String::with_capacity(t.capacity() * registers.len());

        for reg in registers {
            let size_bits = reg.size_bits.to_string();

            let mut vars = HashMap::new();
            vars.insert("description".to_string(), reg.description.as_str());
            vars.insert("size_bits".to_string(), &size_bits);
            vars.insert("name".to_string(), reg.name.as_str());

            out.push_str(&strfmt(&t, &vars).unwrap());
        }

        out
    }

    fn w_ending(&mut self) {
        let t = self.load_template("ending.h");

        self.output.write_all(&t.into_bytes()).expect("Write error");
    }
}

struct Parser {
    context: TranspilerContext,
    field_name: String,

    device: Device,

    peripheral_groups: HashMap<String, PeripheralGroup>,

    new_peripheral: Option<PeripheralGroup>,
    new_register: Option<Register>,
    new_field: Option<Field>,
}

impl Parser {
    fn new() -> Self {
        Parser {
            context: TranspilerContext::Awaiting,
            field_name: String::default(),
            device: Device {
                name: "Unknown".into(),
            },
            peripheral_groups: HashMap::new(),
            new_peripheral: None,
            new_register: None,
            new_field: None,
        }
    }

    fn commit_new_peripheral(&mut self) {
        let p = self
            .new_peripheral
            .as_ref()
            .expect("Tried to write peripheral in invalid state");

        if let Some(gp) = &p.group_name
            && !self.peripheral_groups.contains_key(gp)
        {
            self.peripheral_groups.insert(gp.to_string(), p.clone());
        }

        self.new_peripheral = None;
        self.new_register = None;
        self.new_field = None;
    }

    fn commit_new_register(&mut self) {
        self.new_peripheral
            .as_mut()
            .expect("Tried to commit Register outside of Peripheral")
            .registers
            .push(
                self.new_register
                    .as_ref()
                    .expect("Tried to commit Register in invalid state")
                    .clone(),
            );

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
}

fn main() {
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

    let mut writer = Writer::open(output_file_path);

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

                        let group_name = event
                            .try_get_attribute("derivedFrom")
                            .expect("Attribute error")
                            .map(|attr| {
                                std::str::from_utf8(attr.value.as_ref())
                                    .expect("derivedFrom is not UTF-8")
                                    .to_owned()
                            });

                        parser.new_peripheral = Some(PeripheralGroup {
                            group_name,
                            ..Default::default()
                        });
                    }

                    b"register" => {
                        parser.context = TranspilerContext::Register;
                        parser.new_register = Some(Register::default());
                    }

                    b"field" => {
                        parser.context = TranspilerContext::Field;
                        parser.new_field = Some(Field::default());
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
                _ => (),
            },

            Ok(Event::Text(event)) => {
                let text = event.decode().unwrap().into_owned();
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

                    "group_name" => match parser.context {
                        TranspilerContext::PeripheralGroup => {
                            parser
                                .new_peripheral
                                .as_mut()
                                .expect("'group_name' found outside of Peripheral")
                                .group_name = Some(text)
                        }
                        _ => (),
                    },

                    "address_offset" => match parser.context {
                        TranspilerContext::Register => {
                            parser
                                .new_register
                                .as_mut()
                                .expect("'address_offset' found outside of Register")
                                .address_offset = text
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
                                u8::from_str_radix(text.strip_prefix("0x").unwrap_or(&text), 16)
                                    .expect("Could not parse size")
                        }
                        _ => (),
                    },

                    "reset_value" => match parser.context {
                        TranspilerContext::Register => {
                            parser
                                .new_register
                                .as_mut()
                                .expect("'reset_value' found outside of Register")
                                .reset_value = text
                        }
                        _ => (),
                    },

                    "bit_offset" => match parser.context {
                        TranspilerContext::Register => {
                            parser
                                .new_field
                                .as_mut()
                                .expect("'bit_offset' found outside of Field")
                                .bit_offset =
                                text.parse::<u16>().expect("Could not parse bitOffset")
                        }
                        _ => (),
                    },

                    "bit_width" => match parser.context {
                        TranspilerContext::Register => {
                            parser
                                .new_field
                                .as_mut()
                                .expect("'bit_width' found outside of Field")
                                .bit_width = text.parse::<u8>().expect("Could not parse bitWidth")
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
}
