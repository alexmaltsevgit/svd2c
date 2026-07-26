/**
 * @file stm32f103_svd_mapping.h
 * @brief Сгенерированный заголовочный файл с привязкой к тегам CMSIS-SVD.
 * 
 * Исходные данные SVD:
 * <device>
 *   <name>STM32F103</name>
 *   <version>1.4</version>
 *   <description>ARM Cortex-M3 microcontroller</description>
 *   <addressUnitBits>8</addressUnitBits>
 *   <width>32</width>
 *   <size>32</size>
 *   <resetValue>0x00000000</resetValue>
 */

#ifndef _STM32F103_SVD_MAPPING_H_
#define _STM32F103_SVD_MAPPING_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* =================================================================================================== */
/* ================      СТРУКТУРЫ ПЕРИФЕРИИ (ИЗ <groupName> И <register>)            ================ */
/* =================================================================================================== */

/**
 * В SVD несколько периферийных устройств (GPIOA, GPIOB, GPIOC) могут иметь общий тег:
 * <groupName>GPIO</groupName>
 * В таком случае генератор создает единый тип `GPIO_TypeDef`.
 * 
 * Внутри структуры располагаются регистры, описанные в:
 * <registers>
 *   <register>
 */
typedef struct {
    /**
     * <register>
     *   <name>CRL</name>
     *   <description>Port configuration register low</description>
     *   <addressOffset>0x00</addressOffset>
     *   <size>32</size>
     *   <access>read-write</access>
     * </register>
     */
    volatile uint32_t CRL;

    /**
     * <register>
     *   <name>CRH</name>
     *   <addressOffset>0x04</addressOffset>
     * </register>
     */
    volatile uint32_t CRH;

    /**
     * <register>
     *   <name>IDR</name>
     *   <addressOffset>0x08</addressOffset>
     *   <access>read-only</access> <!-- Для read-only можно было бы добавить const, но в CMSIS обычно пишут просто volatile -->
     * </register>
     */
    volatile uint32_t IDR;

    /**
     * <register>
     *   <name>ODR</name>
     *   <addressOffset>0x0C</addressOffset>
     * </register>
     */
    volatile uint32_t ODR;

    /**
     * <register>
     *   <name>BSRR</name>
     *   <addressOffset>0x10</addressOffset>
     * </register>
     */
    volatile uint32_t BSRR;

    /**
     * Пример вычисления Padding (пустот в памяти).
     * Если следующий регистр имеет <addressOffset>0x18, а BSRR был на 0x10 и занимает 4 байта,
     * то адрес 0x14 пустует. Компилятор Zig должен вставить заглушку:
     */
    volatile uint32_t RESERVED0; /* Сгенерировано автоматически для компенсации разрыва между 0x10+4 и 0x18 */

    /**
     * <register>
     *   <name>LCKR</name>
     *   <addressOffset>0x18</addressOffset>
     * </register>
     */
    volatile uint32_t LCKR;

} GPIO_TypeDef;


/* =================================================================================================== */
/* ================      БАЗОВЫЕ АДРЕСА ПЕРИФЕРИИ (ИЗ <peripheral>)                   ================ */
/* =================================================================================================== */

/**
 * Из корневого тега конкретной периферии:
 * <peripheral>
 *   <name>GPIOA</name>
 *   <baseAddress>0x40010800</baseAddress>
 *   <groupName>GPIO</groupName>
 * </peripheral>
 */
#define GPIOA_BASE            (0x40010800UL)
#define GPIOA                 ((GPIO_TypeDef *)GPIOA_BASE)

/**
 * <peripheral>
 *   <name>GPIOB</name>
 *   <baseAddress>0x40010C00</baseAddress>
 *   <groupName>GPIO</groupName>
 * </peripheral>
 */
#define GPIOB_BASE            (0x40010C00UL)
#define GPIOB                 ((GPIO_TypeDef *)GPIOB_BASE)


/* =================================================================================================== */
/* ================      БИТОВЫЕ ПОЛЯ (ИЗ <field> внутри <register>)                  ================ */
/* =================================================================================================== */

/**
 * Описание битовых полей в SVD:
 * <register> (CRL) -> <fields> -> <field>
 * 
 *   <field>
 *     <name>MODE0</name>
 *     <description>Port x mode bits (y= 0 .. 7)</description>
 *     <bitOffset>0</bitOffset>
 *     <bitWidth>2</bitWidth>
 *   </field>
 */
#define GPIO_CRL_MODE0_Pos       (0U)                                        /* Из <bitOffset>0</bitOffset> */
#define GPIO_CRL_MODE0_Msk       (0x3UL << GPIO_CRL_MODE0_Pos)               /* Вычисляется как: ((1 << <bitWidth>) - 1) << <bitOffset> */
#define GPIO_CRL_MODE0           GPIO_CRL_MODE0_Msk                          /* Общая маска по стандарту CMSIS */

/**
 *   <field>
 *     <name>CNF0</name>
 *     <bitOffset>2</bitOffset>
 *     <bitWidth>2</bitWidth>
 *   </field>
 */
#define GPIO_CRL_CNF0_Pos        (2U)
#define GPIO_CRL_CNF0_Msk        (0x3UL << GPIO_CRL_CNF0_Pos)
#define GPIO_CRL_CNF0            GPIO_CRL_CNF0_Msk


/* =================================================================================================== */
/* ================      ПЕРЕЧИСЛЕНИЯ (ИЗ <enumeratedValues>)                         ================ */
/* =================================================================================================== */

/**
 * Внутри тега <field> могут быть предопределенные значения:
 * <enumeratedValues>
 *   <enumeratedValue>
 *     <name>Input</name>
 *     <value>0</value>
 *   </enumeratedValue>
 *   <enumeratedValue>
 *     <name>Output_10MHz</name>
 *     <value>1</value>
 *   </enumeratedValue>
 * </enumeratedValues>
 */
#define GPIO_CRL_MODE0_Input         (0x0UL) /* Из <value>0</value> */
#define GPIO_CRL_MODE0_Output_10MHz  (0x1UL) /* Из <value>1</value> */
#define GPIO_CRL_MODE0_Output_2MHz   (0x2UL)
#define GPIO_CRL_MODE0_Output_50MHz  (0x3UL)


/* =================================================================================================== */
/* ================      КАСТОМНЫЕ ИНЛАЙН-ФУНКЦИИ (Генерируются на основе <field>)   ================ */
/* =================================================================================================== */

/**
 * Генератор на Zig берет имя периферии (GPIO), имя регистра (CRL),
 * имя поля (MODE0) и собирает удобную обертку.
 */

/**
 * @brief Установить значение поля MODE0
 * @param gpio Указатель на структуру GPIO (например, GPIOA)
 * @param val Значение для записи (желательно использовать макросы GPIO_CRL_MODE0_xxx)
 */
static inline void GPIO_CRL_MODE0_SET(GPIO_TypeDef *gpio, uint32_t val) {
    /* Сбрасываем старые биты (через ~Msk) и ставим новые, защитив их маской 0x3 (вычисленной из <bitWidth>) */
    gpio->CRL = (gpio->CRL & ~GPIO_CRL_MODE0_Msk) | ((val & 0x3UL) << GPIO_CRL_MODE0_Pos);
}

/**
 * @brief Прочитать текущее значение поля MODE0
 * @param gpio Указатель на структуру GPIO
 * @return Значение поля (от 0 до 3)
 */
static inline uint32_t GPIO_CRL_MODE0_GET(GPIO_TypeDef *gpio) {
    return (gpio->CRL & GPIO_CRL_MODE0_Msk) >> GPIO_CRL_MODE0_Pos;
}

#ifdef __cplusplus
}
#endif

#endif /* _STM32F103_SVD_MAPPING_H_ */
