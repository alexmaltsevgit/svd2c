#ifndef _STM32F103_SVD_MAPPING_H_
#define _STM32F103_SVD_MAPPING_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif
/*
 * FSMC global interrupt
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

} FSMC_Typedef

#define FSMC_BASE            (0xA0000000)
#define FSMC                 ((FSMC_TypeDef*)FSMC_BASE)
/*
 * PVD through EXTI line detection
        interrupt
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

} PVD_Typedef

#define PVD_BASE            (0x40007000)
#define PVD                 ((PVD_TypeDef*)PVD_BASE)
/*
 * RCC global interrupt
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

} RCC_Typedef

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

} GPIOA_Typedef

#define GPIOA_BASE            (0x40010800)
#define GPIOA                 ((GPIOA_TypeDef*)GPIOA_BASE)
/*
 * 
 */
typedef struct {

} GPIOA_Typedef

#define GPIOB_BASE            (0x40010C00)
#define GPIOB                 ((GPIOA_TypeDef*)GPIOB_BASE)
#define GPIOC_BASE            (0x40011000)
#define GPIOC                 ((GPIOA_TypeDef *)GPIOC_BASE)
#define GPIOD_BASE            (0x40011400)
#define GPIOD                 ((GPIOA_TypeDef *)GPIOD_BASE)
#define GPIOE_BASE            (0x40011800)
#define GPIOE                 ((GPIOA_TypeDef *)GPIOE_BASE)
#define GPIOF_BASE            (0x40011C00)
#define GPIOF                 ((GPIOA_TypeDef *)GPIOF_BASE)
#define GPIOG_BASE            (0x40012000)
#define GPIOG                 ((GPIOA_TypeDef *)GPIOG_BASE)
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

} AFIO_Typedef

#define AFIO_BASE            (0x40010000)
#define AFIO                 ((AFIO_TypeDef*)AFIO_BASE)
/*
 * EXTI Line[15:10] interrupts
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

} EXTI15_10_Typedef

#define EXTI15_10_BASE            (0x40010400)
#define EXTI15_10                 ((EXTI15_10_TypeDef*)EXTI15_10_BASE)
/*
 * DMA1 Channel7 global interrupt
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

} DMA1_Channel7_Typedef

#define DMA1_Channel7_BASE            (0x40020000)
#define DMA1_Channel7                 ((DMA1_Channel7_TypeDef*)DMA1_Channel7_BASE)
/*
 * DMA2 Channel4 and DMA2 Channel5 global
        interrupt
 */
typedef struct {

} DMA1_Typedef

#define DMA2_Channel4_5_BASE            (0x40020400)
#define DMA2_Channel4_5                 ((DMA1_TypeDef*)DMA2_Channel4_5_BASE)
/*
 * SDIO global interrupt
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

} SDIO_Typedef

#define SDIO_BASE            (0x40018000)
#define SDIO                 ((SDIO_TypeDef*)SDIO_BASE)
/*
 * RTC Alarms through EXTI line
        interrupt
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

} RTCAlarm_Typedef

#define RTCAlarm_BASE            (0x40002800)
#define RTCAlarm                 ((RTCAlarm_TypeDef*)RTCAlarm_BASE)
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

} BKP_Typedef

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

} IWDG_Typedef

#define IWDG_BASE            (0x40003000)
#define IWDG                 ((IWDG_TypeDef*)IWDG_BASE)
/*
 * Window Watchdog interrupt
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

} WWDG_Typedef

#define WWDG_BASE            (0x40002C00)
#define WWDG                 ((WWDG_TypeDef*)WWDG_BASE)
/*
 * TIM1 Capture Compare interrupt
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

} TIM1_CC_Typedef

#define TIM1_CC_BASE            (0x40012C00)
#define TIM1_CC                 ((TIM1_CC_TypeDef*)TIM1_CC_BASE)
/*
 * TIM8 Capture Compare interrupt
 */
typedef struct {

} TIM1_Typedef

#define TIM8_CC_BASE            (0x40013400)
#define TIM8_CC                 ((TIM1_TypeDef*)TIM8_CC_BASE)
/*
 * TIM2 global interrupt
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
    * capture/compare mode register 1 (output
          mode)
    */
    volatile uint32_t CCMR1_Output;
    /**
    * capture/compare mode register 1 (input
          mode)
    */
    volatile uint32_t CCMR1_Input;
    /**
    * capture/compare mode register 2 (output
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

} TIM2_Typedef

#define TIM2_BASE            (0x40000000)
#define TIM2                 ((TIM2_TypeDef*)TIM2_BASE)
/*
 * TIM3 global interrupt
 */
typedef struct {

} TIM2_Typedef

#define TIM3_BASE            (0x40000400)
#define TIM3                 ((TIM2_TypeDef*)TIM3_BASE)
#define TIM4_BASE            (0x40000800)
#define TIM4                 ((TIM2_TypeDef *)TIM4_BASE)
#define TIM5_BASE            (0x40000C00)
#define TIM5                 ((TIM2_TypeDef *)TIM5_BASE)
/*
 * General purpose timer
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
    * capture/compare mode register 1 (output
          mode)
    */
    volatile uint32_t CCMR1_Output;
    /**
    * capture/compare mode register 1 (input
          mode)
    */
    volatile uint32_t CCMR1_Input;
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

} TIM9_Typedef

#define TIM9_BASE            (0x40014C00)
#define TIM9                 ((TIM9_TypeDef*)TIM9_BASE)
/*
 * 
 */
typedef struct {

} TIM9_Typedef

#define TIM12_BASE            (0x40001800)
#define TIM12                 ((TIM9_TypeDef*)TIM12_BASE)
/*
 * TIM1 Update interrupt
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
    * capture/compare mode register (input
          mode)
    */
    volatile uint32_t CCMR1_Input;
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

} TIM1_UP_Typedef

#define TIM1_UP_BASE            (0x40015000)
#define TIM1_UP                 ((TIM1_UP_TypeDef*)TIM1_UP_BASE)
/*
 * TIM1 Trigger and Commutation
        interrupts
 */
typedef struct {

} TIM10_Typedef

#define TIM1_TRG_COM_BASE            (0x40015400)
#define TIM1_TRG_COM                 ((TIM10_TypeDef*)TIM1_TRG_COM_BASE)
#define TIM13_BASE            (0x40001C00)
#define TIM13                 ((TIM10_TypeDef *)TIM13_BASE)
#define TIM14_BASE            (0x40002000)
#define TIM14                 ((TIM10_TypeDef *)TIM14_BASE)
/*
 * TIM6 global interrupt
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

} TIM6_Typedef

#define TIM6_BASE            (0x40001000)
#define TIM6                 ((TIM6_TypeDef*)TIM6_BASE)
/*
 * TIM7 global interrupt
 */
typedef struct {

} TIM6_Typedef

#define TIM7_BASE            (0x40001400)
#define TIM7                 ((TIM6_TypeDef*)TIM7_BASE)
/*
 * I2C1 error interrupt
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

} I2C1_ER_Typedef

#define I2C1_ER_BASE            (0x40005400)
#define I2C1_ER                 ((I2C1_ER_TypeDef*)I2C1_ER_BASE)
/*
 * I2C2 error interrupt
 */
typedef struct {

} I2C1_Typedef

#define I2C2_ER_BASE            (0x40005800)
#define I2C2_ER                 ((I2C1_TypeDef*)I2C2_ER_BASE)
/*
 * SPI1 global interrupt
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

} SPI1_Typedef

#define SPI1_BASE            (0x40013000)
#define SPI1                 ((SPI1_TypeDef*)SPI1_BASE)
/*
 * SPI2 global interrupt
 */
typedef struct {

} SPI1_Typedef

#define SPI2_BASE            (0x40003800)
#define SPI2                 ((SPI1_TypeDef*)SPI2_BASE)
#define SPI3_BASE            (0x40003C00)
#define SPI3                 ((SPI1_TypeDef *)SPI3_BASE)
/*
 * USART1 global interrupt
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

} USART1_Typedef

#define USART1_BASE            (0x40013800)
#define USART1                 ((USART1_TypeDef*)USART1_BASE)
/*
 * USART2 global interrupt
 */
typedef struct {

} USART1_Typedef

#define USART2_BASE            (0x40004400)
#define USART2                 ((USART1_TypeDef*)USART2_BASE)
#define USART3_BASE            (0x40004800)
#define USART3                 ((USART1_TypeDef *)USART3_BASE)
/*
 * ADC1 and ADC2 global interrupt
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

} ADC1_2_Typedef

#define ADC1_2_BASE            (0x40012400)
#define ADC1_2                 ((ADC1_2_TypeDef*)ADC1_2_BASE)
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

} ADC2_Typedef

#define ADC2_BASE            (0x40012800)
#define ADC2                 ((ADC2_TypeDef*)ADC2_BASE)
/*
 * ADC3 global interrupt
 */
typedef struct {

} ADC2_Typedef

#define ADC3_BASE            (0x40013C00)
#define ADC3                 ((ADC2_TypeDef*)ADC3_BASE)
/*
 * CAN SCE interrupt
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

} CAN_SCE_Typedef

#define CAN_SCE_BASE            (0x40006400)
#define CAN_SCE                 ((CAN_SCE_TypeDef*)CAN_SCE_BASE)
/*
 * 
 */
typedef struct {

} CAN1_Typedef

#define CAN2_BASE            (0x40006800)
#define CAN2                 ((CAN1_TypeDef*)CAN2_BASE)
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

} DAC_Typedef

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

} DBG_Typedef

#define DBG_BASE            (0xE0042000)
#define DBG                 ((DBG_TypeDef*)DBG_BASE)
/*
 * UART4 global interrupt
 */
typedef struct {
    /**
    * UART4_SR
    */
    volatile uint32_t SR;
    /**
    * UART4_DR
    */
    volatile uint32_t DR;
    /**
    * UART4_BRR
    */
    volatile uint32_t BRR;
    /**
    * UART4_CR1
    */
    volatile uint32_t CR1;
    /**
    * UART4_CR2
    */
    volatile uint32_t CR2;
    /**
    * UART4_CR3
    */
    volatile uint32_t CR3;

} UART4_Typedef

#define UART4_BASE            (0x40004C00)
#define UART4                 ((UART4_TypeDef*)UART4_BASE)
/*
 * UART5 global interrupt
 */
typedef struct {
    /**
    * UART4_SR
    */
    volatile uint32_t SR;
    /**
    * UART4_DR
    */
    volatile uint32_t DR;
    /**
    * UART4_BRR
    */
    volatile uint32_t BRR;
    /**
    * UART4_CR1
    */
    volatile uint32_t CR1;
    /**
    * UART4_CR2
    */
    volatile uint32_t CR2;
    /**
    * UART4_CR3
    */
    volatile uint32_t CR3;

} UART5_Typedef

#define UART5_BASE            (0x40005000)
#define UART5                 ((UART5_TypeDef*)UART5_BASE)
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

} CRC_Typedef

#define CRC_BASE            (0x40023000)
#define CRC                 ((CRC_TypeDef*)CRC_BASE)
/*
 * Flash global interrupt
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

} FLASH_Typedef

#define FLASH_BASE            (0x40022000)
#define FLASH                 ((FLASH_TypeDef*)FLASH_BASE)
/*
 * USB Low Priority or CAN RX0
        interrupts
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

} USB_LP_CAN_RX0_Typedef

#define USB_LP_CAN_RX0_BASE            (0x40005C00)
#define USB_LP_CAN_RX0                 ((USB_LP_CAN_RX0_TypeDef*)USB_LP_CAN_RX0_BASE)
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

} OTG_FS_DEVICE_Typedef

#define OTG_FS_DEVICE_BASE            (0x50000800)
#define OTG_FS_DEVICE                 ((OTG_FS_DEVICE_TypeDef*)OTG_FS_DEVICE_BASE)
/*
 * USB on the go full speed
 */
typedef struct {
    /**
    * OTG_FS control and status register
          (OTG_FS_GOTGCTL)
    */
    volatile uint32_t FS_GOTGCTL;
    /**
    * OTG_FS interrupt register
          (OTG_FS_GOTGINT)
    */
    volatile uint32_t FS_GOTGINT;
    /**
    * OTG_FS AHB configuration register
          (OTG_FS_GAHBCFG)
    */
    volatile uint32_t FS_GAHBCFG;
    /**
    * OTG_FS USB configuration register
          (OTG_FS_GUSBCFG)
    */
    volatile uint32_t FS_GUSBCFG;
    /**
    * OTG_FS reset register
          (OTG_FS_GRSTCTL)
    */
    volatile uint32_t FS_GRSTCTL;
    /**
    * OTG_FS core interrupt register
          (OTG_FS_GINTSTS)
    */
    volatile uint32_t FS_GINTSTS;
    /**
    * OTG_FS interrupt mask register
          (OTG_FS_GINTMSK)
    */
    volatile uint32_t FS_GINTMSK;
    /**
    * OTG_FS Receive status debug read(Device
          mode)
    */
    volatile uint32_t FS_GRXSTSR_Device;
    /**
    * OTG_FS Receive status debug read(Host
          mode)
    */
    volatile uint32_t FS_GRXSTSR_Host;
    /**
    * OTG_FS Receive FIFO size register
          (OTG_FS_GRXFSIZ)
    */
    volatile uint32_t FS_GRXFSIZ;
    /**
    * OTG_FS non-periodic transmit FIFO size
          register (Device mode)
    */
    volatile uint32_t FS_GNPTXFSIZ_Device;
    /**
    * OTG_FS non-periodic transmit FIFO size
          register (Host mode)
    */
    volatile uint32_t FS_GNPTXFSIZ_Host;
    /**
    * OTG_FS non-periodic transmit FIFO/queue
          status register (OTG_FS_GNPTXSTS)
    */
    volatile uint32_t FS_GNPTXSTS;
    /**
    * OTG_FS general core configuration register
          (OTG_FS_GCCFG)
    */
    volatile uint32_t FS_GCCFG;
    /**
    * core ID register
    */
    volatile uint32_t FS_CID;
    /**
    * OTG_FS Host periodic transmit FIFO size
          register (OTG_FS_HPTXFSIZ)
    */
    volatile uint32_t FS_HPTXFSIZ;
    /**
    * OTG_FS device IN endpoint transmit FIFO size
          register (OTG_FS_DIEPTXF2)
    */
    volatile uint32_t FS_DIEPTXF1;
    /**
    * OTG_FS device IN endpoint transmit FIFO size
          register (OTG_FS_DIEPTXF3)
    */
    volatile uint32_t FS_DIEPTXF2;
    /**
    * OTG_FS device IN endpoint transmit FIFO size
          register (OTG_FS_DIEPTXF4)
    */
    volatile uint32_t FS_DIEPTXF3;

} OTG_FS_GLOBAL_Typedef

#define OTG_FS_GLOBAL_BASE            (0x50000000)
#define OTG_FS_GLOBAL                 ((OTG_FS_GLOBAL_TypeDef*)OTG_FS_GLOBAL_BASE)
/*
 * USB on the go full speed
 */
typedef struct {
    /**
    * OTG_FS host configuration register
          (OTG_FS_HCFG)
    */
    volatile uint32_t FS_HCFG;
    /**
    * OTG_FS Host frame interval
          register
    */
    volatile uint32_t HFIR;
    /**
    * OTG_FS host frame number/frame time
          remaining register (OTG_FS_HFNUM)
    */
    volatile uint32_t FS_HFNUM;
    /**
    * OTG_FS_Host periodic transmit FIFO/queue
          status register (OTG_FS_HPTXSTS)
    */
    volatile uint32_t FS_HPTXSTS;
    /**
    * OTG_FS Host all channels interrupt
          register
    */
    volatile uint32_t HAINT;
    /**
    * OTG_FS host all channels interrupt mask
          register
    */
    volatile uint32_t HAINTMSK;
    /**
    * OTG_FS host port control and status register
          (OTG_FS_HPRT)
    */
    volatile uint32_t FS_HPRT;
    /**
    * OTG_FS host channel-0 characteristics
          register (OTG_FS_HCCHAR0)
    */
    volatile uint32_t FS_HCCHAR0;
    /**
    * OTG_FS host channel-1 characteristics
          register (OTG_FS_HCCHAR1)
    */
    volatile uint32_t FS_HCCHAR1;
    /**
    * OTG_FS host channel-2 characteristics
          register (OTG_FS_HCCHAR2)
    */
    volatile uint32_t FS_HCCHAR2;
    /**
    * OTG_FS host channel-3 characteristics
          register (OTG_FS_HCCHAR3)
    */
    volatile uint32_t FS_HCCHAR3;
    /**
    * OTG_FS host channel-4 characteristics
          register (OTG_FS_HCCHAR4)
    */
    volatile uint32_t FS_HCCHAR4;
    /**
    * OTG_FS host channel-5 characteristics
          register (OTG_FS_HCCHAR5)
    */
    volatile uint32_t FS_HCCHAR5;
    /**
    * OTG_FS host channel-6 characteristics
          register (OTG_FS_HCCHAR6)
    */
    volatile uint32_t FS_HCCHAR6;
    /**
    * OTG_FS host channel-7 characteristics
          register (OTG_FS_HCCHAR7)
    */
    volatile uint32_t FS_HCCHAR7;
    /**
    * OTG_FS host channel-0 interrupt register
          (OTG_FS_HCINT0)
    */
    volatile uint32_t FS_HCINT0;
    /**
    * OTG_FS host channel-1 interrupt register
          (OTG_FS_HCINT1)
    */
    volatile uint32_t FS_HCINT1;
    /**
    * OTG_FS host channel-2 interrupt register
          (OTG_FS_HCINT2)
    */
    volatile uint32_t FS_HCINT2;
    /**
    * OTG_FS host channel-3 interrupt register
          (OTG_FS_HCINT3)
    */
    volatile uint32_t FS_HCINT3;
    /**
    * OTG_FS host channel-4 interrupt register
          (OTG_FS_HCINT4)
    */
    volatile uint32_t FS_HCINT4;
    /**
    * OTG_FS host channel-5 interrupt register
          (OTG_FS_HCINT5)
    */
    volatile uint32_t FS_HCINT5;
    /**
    * OTG_FS host channel-6 interrupt register
          (OTG_FS_HCINT6)
    */
    volatile uint32_t FS_HCINT6;
    /**
    * OTG_FS host channel-7 interrupt register
          (OTG_FS_HCINT7)
    */
    volatile uint32_t FS_HCINT7;
    /**
    * OTG_FS host channel-0 mask register
          (OTG_FS_HCINTMSK0)
    */
    volatile uint32_t FS_HCINTMSK0;
    /**
    * OTG_FS host channel-1 mask register
          (OTG_FS_HCINTMSK1)
    */
    volatile uint32_t FS_HCINTMSK1;
    /**
    * OTG_FS host channel-2 mask register
          (OTG_FS_HCINTMSK2)
    */
    volatile uint32_t FS_HCINTMSK2;
    /**
    * OTG_FS host channel-3 mask register
          (OTG_FS_HCINTMSK3)
    */
    volatile uint32_t FS_HCINTMSK3;
    /**
    * OTG_FS host channel-4 mask register
          (OTG_FS_HCINTMSK4)
    */
    volatile uint32_t FS_HCINTMSK4;
    /**
    * OTG_FS host channel-5 mask register
          (OTG_FS_HCINTMSK5)
    */
    volatile uint32_t FS_HCINTMSK5;
    /**
    * OTG_FS host channel-6 mask register
          (OTG_FS_HCINTMSK6)
    */
    volatile uint32_t FS_HCINTMSK6;
    /**
    * OTG_FS host channel-7 mask register
          (OTG_FS_HCINTMSK7)
    */
    volatile uint32_t FS_HCINTMSK7;
    /**
    * OTG_FS host channel-0 transfer size
          register
    */
    volatile uint32_t FS_HCTSIZ0;
    /**
    * OTG_FS host channel-1 transfer size
          register
    */
    volatile uint32_t FS_HCTSIZ1;
    /**
    * OTG_FS host channel-2 transfer size
          register
    */
    volatile uint32_t FS_HCTSIZ2;
    /**
    * OTG_FS host channel-3 transfer size
          register
    */
    volatile uint32_t FS_HCTSIZ3;
    /**
    * OTG_FS host channel-x transfer size
          register
    */
    volatile uint32_t FS_HCTSIZ4;
    /**
    * OTG_FS host channel-5 transfer size
          register
    */
    volatile uint32_t FS_HCTSIZ5;
    /**
    * OTG_FS host channel-6 transfer size
          register
    */
    volatile uint32_t FS_HCTSIZ6;
    /**
    * OTG_FS host channel-7 transfer size
          register
    */
    volatile uint32_t FS_HCTSIZ7;

} OTG_FS_HOST_Typedef

#define OTG_FS_HOST_BASE            (0x50000400)
#define OTG_FS_HOST                 ((OTG_FS_HOST_TypeDef*)OTG_FS_HOST_BASE)
/*
 * USB on the go full speed
 */
typedef struct {
    /**
    * OTG_FS power and clock gating control
          register
    */
    volatile uint32_t FS_PCGCCTL;

} OTG_FS_PWRCLK_Typedef

#define OTG_FS_PWRCLK_BASE            (0x50000E00)
#define OTG_FS_PWRCLK                 ((OTG_FS_PWRCLK_TypeDef*)OTG_FS_PWRCLK_BASE)
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

} ETHERNET_MMC_Typedef

#define ETHERNET_MMC_BASE            (0x40028100)
#define ETHERNET_MMC                 ((ETHERNET_MMC_TypeDef*)ETHERNET_MMC_BASE)
/*
 * Ethernet: media access control
 */
typedef struct {
    /**
    * Ethernet MAC configuration register
          (ETH_MACCR)
    */
    volatile uint32_t MACCR;
    /**
    * Ethernet MAC frame filter register
          (ETH_MACCFFR)
    */
    volatile uint32_t MACFFR;
    /**
    * Ethernet MAC hash table high
          register
    */
    volatile uint32_t MACHTHR;
    /**
    * Ethernet MAC hash table low
          register
    */
    volatile uint32_t MACHTLR;
    /**
    * Ethernet MAC MII address register
          (ETH_MACMIIAR)
    */
    volatile uint32_t MACMIIAR;
    /**
    * Ethernet MAC MII data register
          (ETH_MACMIIDR)
    */
    volatile uint32_t MACMIIDR;
    /**
    * Ethernet MAC flow control register
          (ETH_MACFCR)
    */
    volatile uint32_t MACFCR;
    /**
    * Ethernet MAC VLAN tag register
          (ETH_MACVLANTR)
    */
    volatile uint32_t MACVLANTR;
    /**
    * Ethernet MAC remote wakeup frame filter
          register (ETH_MACRWUFFR)
    */
    volatile uint32_t MACRWUFFR;
    /**
    * Ethernet MAC PMT control and status register
          (ETH_MACPMTCSR)
    */
    volatile uint32_t MACPMTCSR;
    /**
    * Ethernet MAC interrupt status register
          (ETH_MACSR)
    */
    volatile uint32_t MACSR;
    /**
    * Ethernet MAC interrupt mask register
          (ETH_MACIMR)
    */
    volatile uint32_t MACIMR;
    /**
    * Ethernet MAC address 0 high register
          (ETH_MACA0HR)
    */
    volatile uint32_t MACA0HR;
    /**
    * Ethernet MAC address 0 low
          register
    */
    volatile uint32_t MACA0LR;
    /**
    * Ethernet MAC address 1 high register
          (ETH_MACA1HR)
    */
    volatile uint32_t MACA1HR;
    /**
    * Ethernet MAC address1 low
          register
    */
    volatile uint32_t MACA1LR;
    /**
    * Ethernet MAC address 2 high register
          (ETH_MACA2HR)
    */
    volatile uint32_t MACA2HR;
    /**
    * Ethernet MAC address 2 low
          register
    */
    volatile uint32_t MACA2LR;
    /**
    * Ethernet MAC address 3 high register
          (ETH_MACA3HR)
    */
    volatile uint32_t MACA3HR;
    /**
    * Ethernet MAC address 3 low
          register
    */
    volatile uint32_t MACA3LR;

} ETHERNET_MAC_Typedef

#define ETHERNET_MAC_BASE            (0x40028000)
#define ETHERNET_MAC                 ((ETHERNET_MAC_TypeDef*)ETHERNET_MAC_BASE)
/*
 * Ethernet: Precision time protocol
 */
typedef struct {
    /**
    * Ethernet PTP time stamp control register
          (ETH_PTPTSCR)
    */
    volatile uint32_t PTPTSCR;
    /**
    * Ethernet PTP subsecond increment
          register
    */
    volatile uint32_t PTPSSIR;
    /**
    * Ethernet PTP time stamp high
          register
    */
    volatile uint32_t PTPTSHR;
    /**
    * Ethernet PTP time stamp low register
          (ETH_PTPTSLR)
    */
    volatile uint32_t PTPTSLR;
    /**
    * Ethernet PTP time stamp high update
          register
    */
    volatile uint32_t PTPTSHUR;
    /**
    * Ethernet PTP time stamp low update register
          (ETH_PTPTSLUR)
    */
    volatile uint32_t PTPTSLUR;
    /**
    * Ethernet PTP time stamp addend
          register
    */
    volatile uint32_t PTPTSAR;
    /**
    * Ethernet PTP target time high
          register
    */
    volatile uint32_t PTPTTHR;
    /**
    * Ethernet PTP target time low
          register
    */
    volatile uint32_t PTPTTLR;

} ETHERNET_PTP_Typedef

#define ETHERNET_PTP_BASE            (0x40028700)
#define ETHERNET_PTP                 ((ETHERNET_PTP_TypeDef*)ETHERNET_PTP_BASE)
/*
 * Ethernet: DMA controller operation
 */
typedef struct {
    /**
    * Ethernet DMA bus mode register
    */
    volatile uint32_t DMABMR;
    /**
    * Ethernet DMA transmit poll demand
          register
    */
    volatile uint32_t DMATPDR;
    /**
    * EHERNET DMA receive poll demand
          register
    */
    volatile uint32_t DMARPDR;
    /**
    * Ethernet DMA receive descriptor list address
          register
    */
    volatile uint32_t DMARDLAR;
    /**
    * Ethernet DMA transmit descriptor list
          address register
    */
    volatile uint32_t DMATDLAR;
    /**
    * Ethernet DMA status register
    */
    volatile uint32_t DMASR;
    /**
    * Ethernet DMA operation mode
          register
    */
    volatile uint32_t DMAOMR;
    /**
    * Ethernet DMA interrupt enable
          register
    */
    volatile uint32_t DMAIER;
    /**
    * Ethernet DMA missed frame and buffer
          overflow counter register
    */
    volatile uint32_t DMAMFBOCR;
    /**
    * Ethernet DMA current host transmit
          descriptor register
    */
    volatile uint32_t DMACHTDR;
    /**
    * Ethernet DMA current host receive descriptor
          register
    */
    volatile uint32_t DMACHRDR;
    /**
    * Ethernet DMA current host transmit buffer
          address register
    */
    volatile uint32_t DMACHTBAR;
    /**
    * Ethernet DMA current host receive buffer
          address register
    */
    volatile uint32_t DMACHRBAR;

} ETHERNET_DMA_Typedef

#define ETHERNET_DMA_BASE            (0x40029000)
#define ETHERNET_DMA                 ((ETHERNET_DMA_TypeDef*)ETHERNET_DMA_BASE)
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

} NVIC_Typedef

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

} MPU_Typedef

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

} SCB_ACTRL_Typedef

#define SCB_ACTRL_BASE            (0xE000E008)
#define SCB_ACTRL                 ((SCB_ACTRL_TypeDef*)SCB_ACTRL_BASE)
/*
 * Nested vectored interrupt
      controller
 */
typedef struct {
    /**
    * Software trigger interrupt
          register
    */
    volatile uint32_t STIR;

} NVIC_STIR_Typedef

#define NVIC_STIR_BASE            (0xE000EF00)
#define NVIC_STIR                 ((NVIC_STIR_TypeDef*)NVIC_STIR_BASE)
/*
 * System control block
 */
typedef struct {
    /**
    * CPUID base register
    */
    volatile uint32_t CPUID;
    /**
    * Interrupt control and state
          register
    */
    volatile uint32_t ICSR;
    /**
    * Vector table offset register
    */
    volatile uint32_t VTOR;
    /**
    * Application interrupt and reset control
          register
    */
    volatile uint32_t AIRCR;
    /**
    * System control register
    */
    volatile uint32_t SCR;
    /**
    * Configuration and control
          register
    */
    volatile uint32_t CCR;
    /**
    * System handler priority
          registers
    */
    volatile uint32_t SHPR1;
    /**
    * System handler priority
          registers
    */
    volatile uint32_t SHPR2;
    /**
    * System handler priority
          registers
    */
    volatile uint32_t SHPR3;
    /**
    * System handler control and state
          register
    */
    volatile uint32_t SHCRS;
    /**
    * Configurable fault status
          register
    */
    volatile uint32_t CFSR_UFSR_BFSR_MMFSR;
    /**
    * Hard fault status register
    */
    volatile uint32_t HFSR;
    /**
    * Memory management fault address
          register
    */
    volatile uint32_t MMFAR;
    /**
    * Bus fault address register
    */
    volatile uint32_t BFAR;

} SCB_Typedef

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

} STK_Typedef

#define STK_BASE            (0xE000E010)
#define STK                 ((STK_TypeDef*)STK_BASE)

#ifdef __cplusplus
}
#endif

#endif
