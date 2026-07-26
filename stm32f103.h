#ifndef _STM32F103_SVD_MAPPING_H_
#define _STM32F103_SVD_MAPPING_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Flexible static memory controller
 */
typedef struct {
    /**
    * SRAM/NOR-Flash chip-select control register
          1
    */
    volatile uint32_t BCR1;
    /**
    * SRAM/NOR-Flash chip-select timing register
          1
    */
    volatile uint32_t BTR1;
    /**
    * SRAM/NOR-Flash chip-select control register
          2
    */
    volatile uint32_t BCR2;
    /**
    * SRAM/NOR-Flash chip-select timing register
          2
    */
    volatile uint32_t BTR2;
    /**
    * SRAM/NOR-Flash chip-select control register
          3
    */
    volatile uint32_t BCR3;
    /**
    * SRAM/NOR-Flash chip-select timing register
          3
    */
    volatile uint32_t BTR3;
    /**
    * SRAM/NOR-Flash chip-select control register
          4
    */
    volatile uint32_t BCR4;
    /**
    * SRAM/NOR-Flash chip-select timing register
          4
    */
    volatile uint32_t BTR4;
    /**
    * PC Card/NAND Flash control register
          2
    */
    volatile uint32_t PCR2;
    /**
    * FIFO status and interrupt register
          2
    */
    volatile uint32_t SR2;
    /**
    * Common memory space timing register
          2
    */
    volatile uint32_t PMEM2;
    /**
    * Attribute memory space timing register
          2
    */
    volatile uint32_t PATT2;
    /**
    * ECC result register 2
    */
    volatile uint32_t ECCR2;
    /**
    * PC Card/NAND Flash control register
          3
    */
    volatile uint32_t PCR3;
    /**
    * FIFO status and interrupt register
          3
    */
    volatile uint32_t SR3;
    /**
    * Common memory space timing register
          3
    */
    volatile uint32_t PMEM3;
    /**
    * Attribute memory space timing register
          3
    */
    volatile uint32_t PATT3;
    /**
    * ECC result register 3
    */
    volatile uint32_t ECCR3;
    /**
    * PC Card/NAND Flash control register
          4
    */
    volatile uint32_t PCR4;
    /**
    * FIFO status and interrupt register
          4
    */
    volatile uint32_t SR4;
    /**
    * Common memory space timing register
          4
    */
    volatile uint32_t PMEM4;
    /**
    * Attribute memory space timing register
          4
    */
    volatile uint32_t PATT4;
    /**
    * I/O space timing register 4
    */
    volatile uint32_t PIO4;
    /**
    * SRAM/NOR-Flash write timing registers
          1
    */
    volatile uint32_t BWTR1;
    /**
    * SRAM/NOR-Flash write timing registers
          2
    */
    volatile uint32_t BWTR2;
    /**
    * SRAM/NOR-Flash write timing registers
          3
    */
    volatile uint32_t BWTR3;
    /**
    * SRAM/NOR-Flash write timing registers
          4
    */
    volatile uint32_t BWTR4;

} FSMC_Typedef;

#define FSMC_BASE            (0xA0000000)
#define FSMC                 ((FSMC_TypeDef*)FSMC_BASE)

/*
 * Power control
 */
typedef struct {
    /**
    * Power control register
          (PWR_CR)
    */
    volatile uint32_t CR;
    /**
    * Power control register
          (PWR_CR)
    */
    volatile uint32_t CSR;

} PWR_Typedef;

#define PWR_BASE            (0x40007000)
#define PWR                 ((PWR_TypeDef*)PWR_BASE)

/*
 * Reset and clock control
 */
typedef struct {
    /**
    * Clock control register
    */
    volatile uint32_t CR;
    /**
    * Clock configuration register
          (RCC_CFGR)
    */
    volatile uint32_t CFGR;
    /**
    * Clock interrupt register
          (RCC_CIR)
    */
    volatile uint32_t CIR;
    /**
    * APB2 peripheral reset register
          (RCC_APB2RSTR)
    */
    volatile uint32_t APB2RSTR;
    /**
    * APB1 peripheral reset register
          (RCC_APB1RSTR)
    */
    volatile uint32_t APB1RSTR;
    /**
    * AHB Peripheral Clock enable register
          (RCC_AHBENR)
    */
    volatile uint32_t AHBENR;
    /**
    * APB2 peripheral clock enable register
          (RCC_APB2ENR)
    */
    volatile uint32_t APB2ENR;
    /**
    * APB1 peripheral clock enable register
          (RCC_APB1ENR)
    */
    volatile uint32_t APB1ENR;
    /**
    * Backup domain control register
          (RCC_BDCR)
    */
    volatile uint32_t BDCR;
    /**
    * Control/status register
          (RCC_CSR)
    */
    volatile uint32_t CSR;

} RCC_Typedef;

#define RCC_BASE            (0x40021000)
#define RCC                 ((RCC_TypeDef*)RCC_BASE)

/*
 * General purpose I/O
 */
typedef struct {
    /**
    * Port configuration register low
          (GPIOn_CRL)
    */
    volatile uint32_t CRL;
    /**
    * Port configuration register high
          (GPIOn_CRL)
    */
    volatile uint32_t CRH;
    /**
    * Port input data register
          (GPIOn_IDR)
    */
    volatile uint32_t IDR;
    /**
    * Port output data register
          (GPIOn_ODR)
    */
    volatile uint32_t ODR;
    /**
    * Port bit set/reset register
          (GPIOn_BSRR)
    */
    volatile uint32_t BSRR;
    /**
    * Port bit reset register
          (GPIOn_BRR)
    */
    volatile uint32_t BRR;
    /**
    * Port configuration lock
          register
    */
    volatile uint32_t LCKR;

} GPIO_Typedef;

#define GPIOA_BASE            (0x40010800)
#define GPIOA                 ((GPIO_TypeDef*)GPIOA_BASE)

#define GPIOB_BASE            (0x40010C00)
#define GPIOB                 ((GPIO_TypeDef*)GPIOB_BASE)

#define GPIOC_BASE            (0x40011000)
#define GPIOC                 ((GPIO_TypeDef*)GPIOC_BASE)

#define GPIOD_BASE            (0x40011400)
#define GPIOD                 ((GPIO_TypeDef*)GPIOD_BASE)

#define GPIOE_BASE            (0x40011800)
#define GPIOE                 ((GPIO_TypeDef*)GPIOE_BASE)

#define GPIOF_BASE            (0x40011C00)
#define GPIOF                 ((GPIO_TypeDef*)GPIOF_BASE)

#define GPIOG_BASE            (0x40012000)
#define GPIOG                 ((GPIO_TypeDef*)GPIOG_BASE)

/*
 * Alternate function I/O
 */
typedef struct {
    /**
    * Event Control Register
          (AFIO_EVCR)
    */
    volatile uint32_t EVCR;
    /**
    * AF remap and debug I/O configuration
          register (AFIO_MAPR)
    */
    volatile uint32_t MAPR;
    /**
    * External interrupt configuration register 1
          (AFIO_EXTICR1)
    */
    volatile uint32_t EXTICR1;
    /**
    * External interrupt configuration register 2
          (AFIO_EXTICR2)
    */
    volatile uint32_t EXTICR2;
    /**
    * External interrupt configuration register 3
          (AFIO_EXTICR3)
    */
    volatile uint32_t EXTICR3;
    /**
    * External interrupt configuration register 4
          (AFIO_EXTICR4)
    */
    volatile uint32_t EXTICR4;
    /**
    * AF remap and debug I/O configuration
          register
    */
    volatile uint32_t MAPR2;

} AFIO_Typedef;

#define AFIO_BASE            (0x40010000)
#define AFIO                 ((AFIO_TypeDef*)AFIO_BASE)

/*
 * EXTI
 */
typedef struct {
    /**
    * Interrupt mask register
          (EXTI_IMR)
    */
    volatile uint32_t IMR;
    /**
    * Event mask register (EXTI_EMR)
    */
    volatile uint32_t EMR;
    /**
    * Rising Trigger selection register
          (EXTI_RTSR)
    */
    volatile uint32_t RTSR;
    /**
    * Falling Trigger selection register
          (EXTI_FTSR)
    */
    volatile uint32_t FTSR;
    /**
    * Software interrupt event register
          (EXTI_SWIER)
    */
    volatile uint32_t SWIER;
    /**
    * Pending register (EXTI_PR)
    */
    volatile uint32_t PR;

} EXTI_Typedef;

#define EXTI_BASE            (0x40010400)
#define EXTI                 ((EXTI_TypeDef*)EXTI_BASE)

/*
 * DMA controller
 */
typedef struct {
    /**
    * DMA interrupt status register
          (DMA_ISR)
    */
    volatile uint32_t ISR;
    /**
    * DMA interrupt flag clear register
          (DMA_IFCR)
    */
    volatile uint32_t IFCR;
    /**
    * DMA channel configuration register
          (DMA_CCR)
    */
    volatile uint32_t CCR1;
    /**
    * DMA channel 1 number of data
          register
    */
    volatile uint32_t CNDTR1;
    /**
    * DMA channel 1 peripheral address
          register
    */
    volatile uint32_t CPAR1;
    /**
    * DMA channel 1 memory address
          register
    */
    volatile uint32_t CMAR1;
    /**
    * DMA channel configuration register
          (DMA_CCR)
    */
    volatile uint32_t CCR2;
    /**
    * DMA channel 2 number of data
          register
    */
    volatile uint32_t CNDTR2;
    /**
    * DMA channel 2 peripheral address
          register
    */
    volatile uint32_t CPAR2;
    /**
    * DMA channel 2 memory address
          register
    */
    volatile uint32_t CMAR2;
    /**
    * DMA channel configuration register
          (DMA_CCR)
    */
    volatile uint32_t CCR3;
    /**
    * DMA channel 3 number of data
          register
    */
    volatile uint32_t CNDTR3;
    /**
    * DMA channel 3 peripheral address
          register
    */
    volatile uint32_t CPAR3;
    /**
    * DMA channel 3 memory address
          register
    */
    volatile uint32_t CMAR3;
    /**
    * DMA channel configuration register
          (DMA_CCR)
    */
    volatile uint32_t CCR4;
    /**
    * DMA channel 4 number of data
          register
    */
    volatile uint32_t CNDTR4;
    /**
    * DMA channel 4 peripheral address
          register
    */
    volatile uint32_t CPAR4;
    /**
    * DMA channel 4 memory address
          register
    */
    volatile uint32_t CMAR4;
    /**
    * DMA channel configuration register
          (DMA_CCR)
    */
    volatile uint32_t CCR5;
    /**
    * DMA channel 5 number of data
          register
    */
    volatile uint32_t CNDTR5;
    /**
    * DMA channel 5 peripheral address
          register
    */
    volatile uint32_t CPAR5;
    /**
    * DMA channel 5 memory address
          register
    */
    volatile uint32_t CMAR5;
    /**
    * DMA channel configuration register
          (DMA_CCR)
    */
    volatile uint32_t CCR6;
    /**
    * DMA channel 6 number of data
          register
    */
    volatile uint32_t CNDTR6;
    /**
    * DMA channel 6 peripheral address
          register
    */
    volatile uint32_t CPAR6;
    /**
    * DMA channel 6 memory address
          register
    */
    volatile uint32_t CMAR6;
    /**
    * DMA channel configuration register
          (DMA_CCR)
    */
    volatile uint32_t CCR7;
    /**
    * DMA channel 7 number of data
          register
    */
    volatile uint32_t CNDTR7;
    /**
    * DMA channel 7 peripheral address
          register
    */
    volatile uint32_t CPAR7;
    /**
    * DMA channel 7 memory address
          register
    */
    volatile uint32_t CMAR7;

} DMA_Typedef;

#define DMA1_BASE            (0x40020000)
#define DMA1                 ((DMA_TypeDef*)DMA1_BASE)

#define DMA2_BASE            (0x40020400)
#define DMA2                 ((DMA_TypeDef*)DMA2_BASE)

/*
 * Secure digital input/output
      interface
 */
typedef struct {
    /**
    * Bits 1:0 = PWRCTRL: Power supply control
          bits
    */
    volatile uint32_t POWER;
    /**
    * SDI clock control register
          (SDIO_CLKCR)
    */
    volatile uint32_t CLKCR;
    /**
    * Bits 31:0 = : Command argument
    */
    volatile uint32_t ARG;
    /**
    * SDIO command register
          (SDIO_CMD)
    */
    volatile uint32_t CMD;
    /**
    * SDIO command register
    */
    volatile uint32_t RESPCMD;
    /**
    * Bits 31:0 = CARDSTATUS1
    */
    volatile uint32_t RESPI1;
    /**
    * Bits 31:0 = CARDSTATUS2
    */
    volatile uint32_t RESP2;
    /**
    * Bits 31:0 = CARDSTATUS3
    */
    volatile uint32_t RESP3;
    /**
    * Bits 31:0 = CARDSTATUS4
    */
    volatile uint32_t RESP4;
    /**
    * Bits 31:0 = DATATIME: Data timeout
          period
    */
    volatile uint32_t DTIMER;
    /**
    * Bits 24:0 = DATALENGTH: Data length
          value
    */
    volatile uint32_t DLEN;
    /**
    * SDIO data control register
          (SDIO_DCTRL)
    */
    volatile uint32_t DCTRL;
    /**
    * Bits 24:0 = DATACOUNT: Data count
          value
    */
    volatile uint32_t DCOUNT;
    /**
    * SDIO status register
          (SDIO_STA)
    */
    volatile uint32_t STA;
    /**
    * SDIO interrupt clear register
          (SDIO_ICR)
    */
    volatile uint32_t ICR;
    /**
    * SDIO mask register (SDIO_MASK)
    */
    volatile uint32_t MASK;
    /**
    * Bits 23:0 = FIFOCOUNT: Remaining number of
          words to be written to or read from the
          FIFO
    */
    volatile uint32_t FIFOCNT;
    /**
    * bits 31:0 = FIFOData: Receive and transmit
          FIFO data
    */
    volatile uint32_t FIFO;

} SDIO_Typedef;

#define SDIO_BASE            (0x40018000)
#define SDIO                 ((SDIO_TypeDef*)SDIO_BASE)

/*
 * Real time clock
 */
typedef struct {
    /**
    * RTC Control Register High
    */
    volatile uint32_t CRH;
    /**
    * RTC Control Register Low
    */
    volatile uint32_t CRL;
    /**
    * RTC Prescaler Load Register
          High
    */
    volatile uint32_t PRLH;
    /**
    * RTC Prescaler Load Register
          Low
    */
    volatile uint32_t PRLL;
    /**
    * RTC Prescaler Divider Register
          High
    */
    volatile uint32_t DIVH;
    /**
    * RTC Prescaler Divider Register
          Low
    */
    volatile uint32_t DIVL;
    /**
    * RTC Counter Register High
    */
    volatile uint32_t CNTH;
    /**
    * RTC Counter Register Low
    */
    volatile uint32_t CNTL;
    /**
    * RTC Alarm Register High
    */
    volatile uint32_t ALRH;
    /**
    * RTC Alarm Register Low
    */
    volatile uint32_t ALRL;

} RTC_Typedef;

#define RTC_BASE            (0x40002800)
#define RTC                 ((RTC_TypeDef*)RTC_BASE)

/*
 * Backup registers
 */
typedef struct {
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR1;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR2;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR3;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR4;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR5;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR6;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR7;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR8;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR9;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR10;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR11;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR12;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR13;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR14;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR15;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR16;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR17;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR18;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR19;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR20;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR21;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR22;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR23;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR24;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR25;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR26;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR27;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR28;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR29;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR30;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR31;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR32;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR33;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR34;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR35;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR36;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR37;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR38;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR39;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR40;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR41;
    /**
    * Backup data register (BKP_DR)
    */
    volatile uint32_t DR42;
    /**
    * RTC clock calibration register
          (BKP_RTCCR)
    */
    volatile uint32_t RTCCR;
    /**
    * Backup control register
          (BKP_CR)
    */
    volatile uint32_t CR;
    /**
    * BKP_CSR control/status register
          (BKP_CSR)
    */
    volatile uint32_t CSR;

} BKP_Typedef;

#define BKP_BASE            (0x40006C00)
#define BKP                 ((BKP_TypeDef*)BKP_BASE)

/*
 * Independent watchdog
 */
typedef struct {
    /**
    * Key register (IWDG_KR)
    */
    volatile uint32_t KR;
    /**
    * Prescaler register (IWDG_PR)
    */
    volatile uint32_t PR;
    /**
    * Reload register (IWDG_RLR)
    */
    volatile uint32_t RLR;
    /**
    * Status register (IWDG_SR)
    */
    volatile uint32_t SR;

} IWDG_Typedef;

#define IWDG_BASE            (0x40003000)
#define IWDG                 ((IWDG_TypeDef*)IWDG_BASE)

/*
 * Window watchdog
 */
typedef struct {
    /**
    * Control register (WWDG_CR)
    */
    volatile uint32_t CR;
    /**
    * Configuration register
          (WWDG_CFR)
    */
    volatile uint32_t CFR;
    /**
    * Status register (WWDG_SR)
    */
    volatile uint32_t SR;

} WWDG_Typedef;

#define WWDG_BASE            (0x40002C00)
#define WWDG                 ((WWDG_TypeDef*)WWDG_BASE)

/*
 * Advanced timer
 */
typedef struct {
    /**
    * control register 1
    */
    volatile uint32_t CR1;
    /**
    * control register 2
    */
    volatile uint32_t CR2;
    /**
    * slave mode control register
    */
    volatile uint32_t SMCR;
    /**
    * DMA/Interrupt enable register
    */
    volatile uint32_t DIER;
    /**
    * status register
    */
    volatile uint32_t SR;
    /**
    * event generation register
    */
    volatile uint32_t EGR;
    /**
    * capture/compare mode register (output
          mode)
    */
    volatile uint32_t CCMR1_Output;
    /**
    * capture/compare mode register 1 (input
          mode)
    */
    volatile uint32_t CCMR1_Input;
    /**
    * capture/compare mode register (output
          mode)
    */
    volatile uint32_t CCMR2_Output;
    /**
    * capture/compare mode register 2 (input
          mode)
    */
    volatile uint32_t CCMR2_Input;
    /**
    * capture/compare enable
          register
    */
    volatile uint32_t CCER;
    /**
    * counter
    */
    volatile uint32_t CNT;
    /**
    * prescaler
    */
    volatile uint32_t PSC;
    /**
    * auto-reload register
    */
    volatile uint32_t ARR;
    /**
    * capture/compare register 1
    */
    volatile uint32_t CCR1;
    /**
    * capture/compare register 2
    */
    volatile uint32_t CCR2;
    /**
    * capture/compare register 3
    */
    volatile uint32_t CCR3;
    /**
    * capture/compare register 4
    */
    volatile uint32_t CCR4;
    /**
    * DMA control register
    */
    volatile uint32_t DCR;
    /**
    * DMA address for full transfer
    */
    volatile uint32_t DMAR;
    /**
    * repetition counter register
    */
    volatile uint32_t RCR;
    /**
    * break and dead-time register
    */
    volatile uint32_t BDTR;

} TIM_Typedef;

#define TIM1_BASE            (0x40012C00)
#define TIM1                 ((TIM_TypeDef*)TIM1_BASE)

#define TIM8_BASE            (0x40013400)
#define TIM8                 ((TIM_TypeDef*)TIM8_BASE)

#define TIM2_BASE            (0x40000000)
#define TIM2                 ((TIM_TypeDef*)TIM2_BASE)

#define TIM3_BASE            (0x40000400)
#define TIM3                 ((TIM_TypeDef*)TIM3_BASE)

#define TIM4_BASE            (0x40000800)
#define TIM4                 ((TIM_TypeDef*)TIM4_BASE)

#define TIM5_BASE            (0x40000C00)
#define TIM5                 ((TIM_TypeDef*)TIM5_BASE)

#define TIM9_BASE            (0x40014C00)
#define TIM9                 ((TIM_TypeDef*)TIM9_BASE)

#define TIM12_BASE            (0x40001800)
#define TIM12                 ((TIM_TypeDef*)TIM12_BASE)

#define TIM10_BASE            (0x40015000)
#define TIM10                 ((TIM_TypeDef*)TIM10_BASE)

#define TIM11_BASE            (0x40015400)
#define TIM11                 ((TIM_TypeDef*)TIM11_BASE)

#define TIM13_BASE            (0x40001C00)
#define TIM13                 ((TIM_TypeDef*)TIM13_BASE)

#define TIM14_BASE            (0x40002000)
#define TIM14                 ((TIM_TypeDef*)TIM14_BASE)

#define TIM6_BASE            (0x40001000)
#define TIM6                 ((TIM_TypeDef*)TIM6_BASE)

#define TIM7_BASE            (0x40001400)
#define TIM7                 ((TIM_TypeDef*)TIM7_BASE)

/*
 * Inter integrated circuit
 */
typedef struct {
    /**
    * Control register 1
    */
    volatile uint32_t CR1;
    /**
    * Control register 2
    */
    volatile uint32_t CR2;
    /**
    * Own address register 1
    */
    volatile uint32_t OAR1;
    /**
    * Own address register 2
    */
    volatile uint32_t OAR2;
    /**
    * Data register
    */
    volatile uint32_t DR;
    /**
    * Status register 1
    */
    volatile uint32_t SR1;
    /**
    * Status register 2
    */
    volatile uint32_t SR2;
    /**
    * Clock control register
    */
    volatile uint32_t CCR;
    /**
    * TRISE register
    */
    volatile uint32_t TRISE;

} I2C_Typedef;

#define I2C1_BASE            (0x40005400)
#define I2C1                 ((I2C_TypeDef*)I2C1_BASE)

#define I2C2_BASE            (0x40005800)
#define I2C2                 ((I2C_TypeDef*)I2C2_BASE)

/*
 * Serial peripheral interface
 */
typedef struct {
    /**
    * control register 1
    */
    volatile uint32_t CR1;
    /**
    * control register 2
    */
    volatile uint32_t CR2;
    /**
    * status register
    */
    volatile uint32_t SR;
    /**
    * data register
    */
    volatile uint32_t DR;
    /**
    * CRC polynomial register
    */
    volatile uint32_t CRCPR;
    /**
    * RX CRC register
    */
    volatile uint32_t RXCRCR;
    /**
    * TX CRC register
    */
    volatile uint32_t TXCRCR;
    /**
    * I2S configuration register
    */
    volatile uint32_t I2SCFGR;
    /**
    * I2S prescaler register
    */
    volatile uint32_t I2SPR;

} SPI_Typedef;

#define SPI1_BASE            (0x40013000)
#define SPI1                 ((SPI_TypeDef*)SPI1_BASE)

#define SPI2_BASE            (0x40003800)
#define SPI2                 ((SPI_TypeDef*)SPI2_BASE)

#define SPI3_BASE            (0x40003C00)
#define SPI3                 ((SPI_TypeDef*)SPI3_BASE)

/*
 * Universal synchronous asynchronous receiver
      transmitter
 */
typedef struct {
    /**
    * Status register
    */
    volatile uint32_t SR;
    /**
    * Data register
    */
    volatile uint32_t DR;
    /**
    * Baud rate register
    */
    volatile uint32_t BRR;
    /**
    * Control register 1
    */
    volatile uint32_t CR1;
    /**
    * Control register 2
    */
    volatile uint32_t CR2;
    /**
    * Control register 3
    */
    volatile uint32_t CR3;
    /**
    * Guard time and prescaler
          register
    */
    volatile uint32_t GTPR;

} USART_Typedef;

#define USART1_BASE            (0x40013800)
#define USART1                 ((USART_TypeDef*)USART1_BASE)

#define USART2_BASE            (0x40004400)
#define USART2                 ((USART_TypeDef*)USART2_BASE)

#define USART3_BASE            (0x40004800)
#define USART3                 ((USART_TypeDef*)USART3_BASE)

/*
 * Analog to digital converter
 */
typedef struct {
    /**
    * status register
    */
    volatile uint32_t SR;
    /**
    * control register 1
    */
    volatile uint32_t CR1;
    /**
    * control register 2
    */
    volatile uint32_t CR2;
    /**
    * sample time register 1
    */
    volatile uint32_t SMPR1;
    /**
    * sample time register 2
    */
    volatile uint32_t SMPR2;
    /**
    * injected channel data offset register
          x
    */
    volatile uint32_t JOFR1;
    /**
    * injected channel data offset register
          x
    */
    volatile uint32_t JOFR2;
    /**
    * injected channel data offset register
          x
    */
    volatile uint32_t JOFR3;
    /**
    * injected channel data offset register
          x
    */
    volatile uint32_t JOFR4;
    /**
    * watchdog higher threshold
          register
    */
    volatile uint32_t HTR;
    /**
    * watchdog lower threshold
          register
    */
    volatile uint32_t LTR;
    /**
    * regular sequence register 1
    */
    volatile uint32_t SQR1;
    /**
    * regular sequence register 2
    */
    volatile uint32_t SQR2;
    /**
    * regular sequence register 3
    */
    volatile uint32_t SQR3;
    /**
    * injected sequence register
    */
    volatile uint32_t JSQR;
    /**
    * injected data register x
    */
    volatile uint32_t JDR1;
    /**
    * injected data register x
    */
    volatile uint32_t JDR2;
    /**
    * injected data register x
    */
    volatile uint32_t JDR3;
    /**
    * injected data register x
    */
    volatile uint32_t JDR4;
    /**
    * regular data register
    */
    volatile uint32_t DR;

} ADC_Typedef;

#define ADC1_BASE            (0x40012400)
#define ADC1                 ((ADC_TypeDef*)ADC1_BASE)

#define ADC2_BASE            (0x40012800)
#define ADC2                 ((ADC_TypeDef*)ADC2_BASE)

#define ADC3_BASE            (0x40013C00)
#define ADC3                 ((ADC_TypeDef*)ADC3_BASE)

/*
 * Controller area network
 */
typedef struct {
    /**
    * CAN_MCR
    */
    volatile uint32_t CAN_MCR;
    /**
    * CAN_MSR
    */
    volatile uint32_t CAN_MSR;
    /**
    * CAN_TSR
    */
    volatile uint32_t CAN_TSR;
    /**
    * CAN_RF0R
    */
    volatile uint32_t CAN_RF0R;
    /**
    * CAN_RF1R
    */
    volatile uint32_t CAN_RF1R;
    /**
    * CAN_IER
    */
    volatile uint32_t CAN_IER;
    /**
    * CAN_ESR
    */
    volatile uint32_t CAN_ESR;
    /**
    * CAN_BTR
    */
    volatile uint32_t CAN_BTR;
    /**
    * CAN_TI0R
    */
    volatile uint32_t CAN_TI0R;
    /**
    * CAN_TDT0R
    */
    volatile uint32_t CAN_TDT0R;
    /**
    * CAN_TDL0R
    */
    volatile uint32_t CAN_TDL0R;
    /**
    * CAN_TDH0R
    */
    volatile uint32_t CAN_TDH0R;
    /**
    * CAN_TI1R
    */
    volatile uint32_t CAN_TI1R;
    /**
    * CAN_TDT1R
    */
    volatile uint32_t CAN_TDT1R;
    /**
    * CAN_TDL1R
    */
    volatile uint32_t CAN_TDL1R;
    /**
    * CAN_TDH1R
    */
    volatile uint32_t CAN_TDH1R;
    /**
    * CAN_TI2R
    */
    volatile uint32_t CAN_TI2R;
    /**
    * CAN_TDT2R
    */
    volatile uint32_t CAN_TDT2R;
    /**
    * CAN_TDL2R
    */
    volatile uint32_t CAN_TDL2R;
    /**
    * CAN_TDH2R
    */
    volatile uint32_t CAN_TDH2R;
    /**
    * CAN_RI0R
    */
    volatile uint32_t CAN_RI0R;
    /**
    * CAN_RDT0R
    */
    volatile uint32_t CAN_RDT0R;
    /**
    * CAN_RDL0R
    */
    volatile uint32_t CAN_RDL0R;
    /**
    * CAN_RDH0R
    */
    volatile uint32_t CAN_RDH0R;
    /**
    * CAN_RI1R
    */
    volatile uint32_t CAN_RI1R;
    /**
    * CAN_RDT1R
    */
    volatile uint32_t CAN_RDT1R;
    /**
    * CAN_RDL1R
    */
    volatile uint32_t CAN_RDL1R;
    /**
    * CAN_RDH1R
    */
    volatile uint32_t CAN_RDH1R;
    /**
    * CAN_FMR
    */
    volatile uint32_t CAN_FMR;
    /**
    * CAN_FM1R
    */
    volatile uint32_t CAN_FM1R;
    /**
    * CAN_FS1R
    */
    volatile uint32_t CAN_FS1R;
    /**
    * CAN_FFA1R
    */
    volatile uint32_t CAN_FFA1R;
    /**
    * CAN_FA1R
    */
    volatile uint32_t CAN_FA1R;
    /**
    * Filter bank 0 register 1
    */
    volatile uint32_t F0R1;
    /**
    * Filter bank 0 register 2
    */
    volatile uint32_t F0R2;
    /**
    * Filter bank 1 register 1
    */
    volatile uint32_t F1R1;
    /**
    * Filter bank 1 register 2
    */
    volatile uint32_t F1R2;
    /**
    * Filter bank 2 register 1
    */
    volatile uint32_t F2R1;
    /**
    * Filter bank 2 register 2
    */
    volatile uint32_t F2R2;
    /**
    * Filter bank 3 register 1
    */
    volatile uint32_t F3R1;
    /**
    * Filter bank 3 register 2
    */
    volatile uint32_t F3R2;
    /**
    * Filter bank 4 register 1
    */
    volatile uint32_t F4R1;
    /**
    * Filter bank 4 register 2
    */
    volatile uint32_t F4R2;
    /**
    * Filter bank 5 register 1
    */
    volatile uint32_t F5R1;
    /**
    * Filter bank 5 register 2
    */
    volatile uint32_t F5R2;
    /**
    * Filter bank 6 register 1
    */
    volatile uint32_t F6R1;
    /**
    * Filter bank 6 register 2
    */
    volatile uint32_t F6R2;
    /**
    * Filter bank 7 register 1
    */
    volatile uint32_t F7R1;
    /**
    * Filter bank 7 register 2
    */
    volatile uint32_t F7R2;
    /**
    * Filter bank 8 register 1
    */
    volatile uint32_t F8R1;
    /**
    * Filter bank 8 register 2
    */
    volatile uint32_t F8R2;
    /**
    * Filter bank 9 register 1
    */
    volatile uint32_t F9R1;
    /**
    * Filter bank 9 register 2
    */
    volatile uint32_t F9R2;
    /**
    * Filter bank 10 register 1
    */
    volatile uint32_t F10R1;
    /**
    * Filter bank 10 register 2
    */
    volatile uint32_t F10R2;
    /**
    * Filter bank 11 register 1
    */
    volatile uint32_t F11R1;
    /**
    * Filter bank 11 register 2
    */
    volatile uint32_t F11R2;
    /**
    * Filter bank 4 register 1
    */
    volatile uint32_t F12R1;
    /**
    * Filter bank 12 register 2
    */
    volatile uint32_t F12R2;
    /**
    * Filter bank 13 register 1
    */
    volatile uint32_t F13R1;
    /**
    * Filter bank 13 register 2
    */
    volatile uint32_t F13R2;

} CAN_Typedef;

#define CAN1_BASE            (0x40006400)
#define CAN1                 ((CAN_TypeDef*)CAN1_BASE)

#define CAN2_BASE            (0x40006800)
#define CAN2                 ((CAN_TypeDef*)CAN2_BASE)

/*
 * Digital to analog converter
 */
typedef struct {
    /**
    * Control register (DAC_CR)
    */
    volatile uint32_t CR;
    /**
    * DAC software trigger register
          (DAC_SWTRIGR)
    */
    volatile uint32_t SWTRIGR;
    /**
    * DAC channel1 12-bit right-aligned data
          holding register(DAC_DHR12R1)
    */
    volatile uint32_t DHR12R1;
    /**
    * DAC channel1 12-bit left aligned data
          holding register (DAC_DHR12L1)
    */
    volatile uint32_t DHR12L1;
    /**
    * DAC channel1 8-bit right aligned data
          holding register (DAC_DHR8R1)
    */
    volatile uint32_t DHR8R1;
    /**
    * DAC channel2 12-bit right aligned data
          holding register (DAC_DHR12R2)
    */
    volatile uint32_t DHR12R2;
    /**
    * DAC channel2 12-bit left aligned data
          holding register (DAC_DHR12L2)
    */
    volatile uint32_t DHR12L2;
    /**
    * DAC channel2 8-bit right-aligned data
          holding register (DAC_DHR8R2)
    */
    volatile uint32_t DHR8R2;
    /**
    * Dual DAC 12-bit right-aligned data holding
          register (DAC_DHR12RD), Bits 31:28 Reserved, Bits 15:12
          Reserved
    */
    volatile uint32_t DHR12RD;
    /**
    * DUAL DAC 12-bit left aligned data holding
          register (DAC_DHR12LD), Bits 19:16 Reserved, Bits 3:0
          Reserved
    */
    volatile uint32_t DHR12LD;
    /**
    * DUAL DAC 8-bit right aligned data holding
          register (DAC_DHR8RD), Bits 31:16 Reserved
    */
    volatile uint32_t DHR8RD;
    /**
    * DAC channel1 data output register
          (DAC_DOR1)
    */
    volatile uint32_t DOR1;
    /**
    * DAC channel2 data output register
          (DAC_DOR2)
    */
    volatile uint32_t DOR2;

} DAC_Typedef;

#define DAC_BASE            (0x40007400)
#define DAC                 ((DAC_TypeDef*)DAC_BASE)

/*
 * Debug support
 */
typedef struct {
    /**
    * DBGMCU_IDCODE
    */
    volatile uint32_t IDCODE;
    /**
    * DBGMCU_CR
    */
    volatile uint32_t CR;

} DBG_Typedef;

#define DBG_BASE            (0xE0042000)
#define DBG                 ((DBG_TypeDef*)DBG_BASE)

#define UART4_BASE            (0x40004C00)
#define UART4                 ((USART_TypeDef*)UART4_BASE)

#define UART5_BASE            (0x40005000)
#define UART5                 ((USART_TypeDef*)UART5_BASE)

/*
 * CRC calculation unit
 */
typedef struct {
    /**
    * Data register
    */
    volatile uint32_t DR;
    /**
    * Independent Data register
    */
    volatile uint32_t IDR;
    /**
    * Control register
    */
    volatile uint32_t CR;

} CRC_Typedef;

#define CRC_BASE            (0x40023000)
#define CRC                 ((CRC_TypeDef*)CRC_BASE)

/*
 * FLASH
 */
typedef struct {
    /**
    * Flash access control register
    */
    volatile uint32_t ACR;
    /**
    * Flash key register
    */
    volatile uint32_t KEYR;
    /**
    * Flash option key register
    */
    volatile uint32_t OPTKEYR;
    /**
    * Status register
    */
    volatile uint32_t SR;
    /**
    * Control register
    */
    volatile uint32_t CR;
    /**
    * Flash address register
    */
    volatile uint32_t AR;
    /**
    * Option byte register
    */
    volatile uint32_t OBR;
    /**
    * Write protection register
    */
    volatile uint32_t WRPR;

} FLASH_Typedef;

#define FLASH_BASE            (0x40022000)
#define FLASH                 ((FLASH_TypeDef*)FLASH_BASE)

/*
 * Universal serial bus full-speed device
      interface
 */
typedef struct {
    /**
    * endpoint 0 register
    */
    volatile uint32_t EP0R;
    /**
    * endpoint 1 register
    */
    volatile uint32_t EP1R;
    /**
    * endpoint 2 register
    */
    volatile uint32_t EP2R;
    /**
    * endpoint 3 register
    */
    volatile uint32_t EP3R;
    /**
    * endpoint 4 register
    */
    volatile uint32_t EP4R;
    /**
    * endpoint 5 register
    */
    volatile uint32_t EP5R;
    /**
    * endpoint 6 register
    */
    volatile uint32_t EP6R;
    /**
    * endpoint 7 register
    */
    volatile uint32_t EP7R;
    /**
    * control register
    */
    volatile uint32_t CNTR;
    /**
    * interrupt status register
    */
    volatile uint32_t ISTR;
    /**
    * frame number register
    */
    volatile uint32_t FNR;
    /**
    * device address
    */
    volatile uint32_t DADDR;
    /**
    * Buffer table address
    */
    volatile uint32_t BTABLE;

} USB_Typedef;

#define USB_BASE            (0x40005C00)
#define USB                 ((USB_TypeDef*)USB_BASE)

/*
 * USB on the go full speed
 */
typedef struct {
    /**
    * OTG_FS device configuration register
          (OTG_FS_DCFG)
    */
    volatile uint32_t FS_DCFG;
    /**
    * OTG_FS device control register
          (OTG_FS_DCTL)
    */
    volatile uint32_t FS_DCTL;
    /**
    * OTG_FS device status register
          (OTG_FS_DSTS)
    */
    volatile uint32_t FS_DSTS;
    /**
    * OTG_FS device IN endpoint common interrupt
          mask register (OTG_FS_DIEPMSK)
    */
    volatile uint32_t FS_DIEPMSK;
    /**
    * OTG_FS device OUT endpoint common interrupt
          mask register (OTG_FS_DOEPMSK)
    */
    volatile uint32_t FS_DOEPMSK;
    /**
    * OTG_FS device all endpoints interrupt
          register (OTG_FS_DAINT)
    */
    volatile uint32_t FS_DAINT;
    /**
    * OTG_FS all endpoints interrupt mask register
          (OTG_FS_DAINTMSK)
    */
    volatile uint32_t FS_DAINTMSK;
    /**
    * OTG_FS device VBUS discharge time
          register
    */
    volatile uint32_t DVBUSDIS;
    /**
    * OTG_FS device VBUS pulsing time
          register
    */
    volatile uint32_t DVBUSPULSE;
    /**
    * OTG_FS device IN endpoint FIFO empty
          interrupt mask register
    */
    volatile uint32_t DIEPEMPMSK;
    /**
    * OTG_FS device control IN endpoint 0 control
          register (OTG_FS_DIEPCTL0)
    */
    volatile uint32_t FS_DIEPCTL0;
    /**
    * OTG device endpoint-1 control
          register
    */
    volatile uint32_t DIEPCTL1;
    /**
    * OTG device endpoint-2 control
          register
    */
    volatile uint32_t DIEPCTL2;
    /**
    * OTG device endpoint-3 control
          register
    */
    volatile uint32_t DIEPCTL3;
    /**
    * device endpoint-0 control
          register
    */
    volatile uint32_t DOEPCTL0;
    /**
    * device endpoint-1 control
          register
    */
    volatile uint32_t DOEPCTL1;
    /**
    * device endpoint-2 control
          register
    */
    volatile uint32_t DOEPCTL2;
    /**
    * device endpoint-3 control
          register
    */
    volatile uint32_t DOEPCTL3;
    /**
    * device endpoint-x interrupt
          register
    */
    volatile uint32_t DIEPINT0;
    /**
    * device endpoint-1 interrupt
          register
    */
    volatile uint32_t DIEPINT1;
    /**
    * device endpoint-2 interrupt
          register
    */
    volatile uint32_t DIEPINT2;
    /**
    * device endpoint-3 interrupt
          register
    */
    volatile uint32_t DIEPINT3;
    /**
    * device endpoint-0 interrupt
          register
    */
    volatile uint32_t DOEPINT0;
    /**
    * device endpoint-1 interrupt
          register
    */
    volatile uint32_t DOEPINT1;
    /**
    * device endpoint-2 interrupt
          register
    */
    volatile uint32_t DOEPINT2;
    /**
    * device endpoint-3 interrupt
          register
    */
    volatile uint32_t DOEPINT3;
    /**
    * device endpoint-0 transfer size
          register
    */
    volatile uint32_t DIEPTSIZ0;
    /**
    * device OUT endpoint-0 transfer size
          register
    */
    volatile uint32_t DOEPTSIZ0;
    /**
    * device endpoint-1 transfer size
          register
    */
    volatile uint32_t DIEPTSIZ1;
    /**
    * device endpoint-2 transfer size
          register
    */
    volatile uint32_t DIEPTSIZ2;
    /**
    * device endpoint-3 transfer size
          register
    */
    volatile uint32_t DIEPTSIZ3;
    /**
    * OTG_FS device IN endpoint transmit FIFO
          status register
    */
    volatile uint32_t DTXFSTS0;
    /**
    * OTG_FS device IN endpoint transmit FIFO
          status register
    */
    volatile uint32_t DTXFSTS1;
    /**
    * OTG_FS device IN endpoint transmit FIFO
          status register
    */
    volatile uint32_t DTXFSTS2;
    /**
    * OTG_FS device IN endpoint transmit FIFO
          status register
    */
    volatile uint32_t DTXFSTS3;
    /**
    * device OUT endpoint-1 transfer size
          register
    */
    volatile uint32_t DOEPTSIZ1;
    /**
    * device OUT endpoint-2 transfer size
          register
    */
    volatile uint32_t DOEPTSIZ2;
    /**
    * device OUT endpoint-3 transfer size
          register
    */
    volatile uint32_t DOEPTSIZ3;

} USB_OTG_FS_Typedef;

#define OTG_FS_DEVICE_BASE            (0x50000800)
#define OTG_FS_DEVICE                 ((USB_OTG_FS_TypeDef*)OTG_FS_DEVICE_BASE)

#define OTG_FS_GLOBAL_BASE            (0x50000000)
#define OTG_FS_GLOBAL                 ((USB_OTG_FS_TypeDef*)OTG_FS_GLOBAL_BASE)

#define OTG_FS_HOST_BASE            (0x50000400)
#define OTG_FS_HOST                 ((USB_OTG_FS_TypeDef*)OTG_FS_HOST_BASE)

#define OTG_FS_PWRCLK_BASE            (0x50000E00)
#define OTG_FS_PWRCLK                 ((USB_OTG_FS_TypeDef*)OTG_FS_PWRCLK_BASE)

/*
 * Ethernet: MAC management counters
 */
typedef struct {
    /**
    * Ethernet MMC control register
          (ETH_MMCCR)
    */
    volatile uint32_t MMCCR;
    /**
    * Ethernet MMC receive interrupt register
          (ETH_MMCRIR)
    */
    volatile uint32_t MMCRIR;
    /**
    * Ethernet MMC transmit interrupt register
          (ETH_MMCTIR)
    */
    volatile uint32_t MMCTIR;
    /**
    * Ethernet MMC receive interrupt mask register
          (ETH_MMCRIMR)
    */
    volatile uint32_t MMCRIMR;
    /**
    * Ethernet MMC transmit interrupt mask
          register (ETH_MMCTIMR)
    */
    volatile uint32_t MMCTIMR;
    /**
    * Ethernet MMC transmitted good frames after a
          single collision counter
    */
    volatile uint32_t MMCTGFSCCR;
    /**
    * Ethernet MMC transmitted good frames after
          more than a single collision
    */
    volatile uint32_t MMCTGFMSCCR;
    /**
    * Ethernet MMC transmitted good frames counter
          register
    */
    volatile uint32_t MMCTGFCR;
    /**
    * Ethernet MMC received frames with CRC error
          counter register
    */
    volatile uint32_t MMCRFCECR;
    /**
    * Ethernet MMC received frames with alignment
          error counter register
    */
    volatile uint32_t MMCRFAECR;
    /**
    * MMC received good unicast frames counter
          register
    */
    volatile uint32_t MMCRGUFCR;

} ETHERNET_Typedef;

#define ETHERNET_MMC_BASE            (0x40028100)
#define ETHERNET_MMC                 ((ETHERNET_TypeDef*)ETHERNET_MMC_BASE)

#define ETHERNET_MAC_BASE            (0x40028000)
#define ETHERNET_MAC                 ((ETHERNET_TypeDef*)ETHERNET_MAC_BASE)

#define ETHERNET_PTP_BASE            (0x40028700)
#define ETHERNET_PTP                 ((ETHERNET_TypeDef*)ETHERNET_PTP_BASE)

#define ETHERNET_DMA_BASE            (0x40029000)
#define ETHERNET_DMA                 ((ETHERNET_TypeDef*)ETHERNET_DMA_BASE)

/*
 * Nested Vectored Interrupt
      Controller
 */
typedef struct {
    /**
    * Interrupt Set-Enable Register
    */
    volatile uint32_t ISER0;
    /**
    * Interrupt Set-Enable Register
    */
    volatile uint32_t ISER1;
    /**
    * Interrupt Clear-Enable
          Register
    */
    volatile uint32_t ICER0;
    /**
    * Interrupt Clear-Enable
          Register
    */
    volatile uint32_t ICER1;
    /**
    * Interrupt Set-Pending Register
    */
    volatile uint32_t ISPR0;
    /**
    * Interrupt Set-Pending Register
    */
    volatile uint32_t ISPR1;
    /**
    * Interrupt Clear-Pending
          Register
    */
    volatile uint32_t ICPR0;
    /**
    * Interrupt Clear-Pending
          Register
    */
    volatile uint32_t ICPR1;
    /**
    * Interrupt Active Bit Register
    */
    volatile uint32_t IABR0;
    /**
    * Interrupt Active Bit Register
    */
    volatile uint32_t IABR1;
    /**
    * Interrupt Priority Register
    */
    volatile uint32_t IPR0;
    /**
    * Interrupt Priority Register
    */
    volatile uint32_t IPR1;
    /**
    * Interrupt Priority Register
    */
    volatile uint32_t IPR2;
    /**
    * Interrupt Priority Register
    */
    volatile uint32_t IPR3;
    /**
    * Interrupt Priority Register
    */
    volatile uint32_t IPR4;
    /**
    * Interrupt Priority Register
    */
    volatile uint32_t IPR5;
    /**
    * Interrupt Priority Register
    */
    volatile uint32_t IPR6;
    /**
    * Interrupt Priority Register
    */
    volatile uint32_t IPR7;
    /**
    * Interrupt Priority Register
    */
    volatile uint32_t IPR8;
    /**
    * Interrupt Priority Register
    */
    volatile uint32_t IPR9;
    /**
    * Interrupt Priority Register
    */
    volatile uint32_t IPR10;
    /**
    * Interrupt Priority Register
    */
    volatile uint32_t IPR11;
    /**
    * Interrupt Priority Register
    */
    volatile uint32_t IPR12;
    /**
    * Interrupt Priority Register
    */
    volatile uint32_t IPR13;
    /**
    * Interrupt Priority Register
    */
    volatile uint32_t IPR14;

} NVIC_Typedef;

#define NVIC_BASE            (0xE000E100)
#define NVIC                 ((NVIC_TypeDef*)NVIC_BASE)

/*
 * Memory protection unit
 */
typedef struct {
    /**
    * MPU type register
    */
    volatile uint32_t MPU_TYPER;
    /**
    * MPU control register
    */
    volatile uint32_t MPU_CTRL;
    /**
    * MPU region number register
    */
    volatile uint32_t MPU_RNR;
    /**
    * MPU region base address
          register
    */
    volatile uint32_t MPU_RBAR;
    /**
    * MPU region attribute and size
          register
    */
    volatile uint32_t MPU_RASR;

} MPU_Typedef;

#define MPU_BASE            (0xE000ED90)
#define MPU                 ((MPU_TypeDef*)MPU_BASE)

/*
 * System control block ACTLR
 */
typedef struct {
    /**
    * Auxiliary control register
    */
    volatile uint32_t ACTRL;

} SCB_Typedef;

#define SCB_ACTRL_BASE            (0xE000E008)
#define SCB_ACTRL                 ((SCB_TypeDef*)SCB_ACTRL_BASE)

#define NVIC_STIR_BASE            (0xE000EF00)
#define NVIC_STIR                 ((NVIC_TypeDef*)NVIC_STIR_BASE)

#define SCB_BASE            (0xE000ED00)
#define SCB                 ((SCB_TypeDef*)SCB_BASE)

/*
 * SysTick timer
 */
typedef struct {
    /**
    * SysTick control and status
          register
    */
    volatile uint32_t CTRL;
    /**
    * SysTick reload value register
    */
    volatile uint32_t LOAD_;
    /**
    * SysTick current value register
    */
    volatile uint32_t VAL;
    /**
    * SysTick calibration value
          register
    */
    volatile uint32_t CALIB;

} STK_Typedef;

#define STK_BASE            (0xE000E010)
#define STK                 ((STK_TypeDef*)STK_BASE)

#ifdef __cplusplus
}
#endif

#endif
