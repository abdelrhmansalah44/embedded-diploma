/*
 * stm32f013x8.h
 *
 *  Created on: Sep 18, 2023
 *      Author: abdalrahman salah
 */

#ifndef INC_STM32F013X6_H_
#define INC_STM32F013X6_H_

#include "stdlib.h"
#include "stdint.h"
#include "stdio.h"
//=========================================================================================

//base addresses for stm32 memories
#define FLASH_MEM  							0x08000000UL
#define SRAM_MEM							0x20000000UL
#define PERIPHERALS_MEM 					0x40000000UL
#define SYTEM_MEMORY						0x1FFFF000UL
#define CORTEX_INTERNAL_PERIPHERALS 		0xE0000000UL

//=========================================================================================


//base addresses for bus peripherals

//AHB SYSTEM BUS
#define RCC_BASE								0x40021000UL

//APB2 SYSTEM BUS
#define  GPIOA_BASE  						0x40010800UL
#define  GPIOB_BASE 						0x40010C00UL
#define  GPIOC_BASE  						0x40011000UL
#define  GPIOD_BASE  						0x40011400UL
#define  GPIOE_BASE  						0x40011800UL


#define AFIO_BASE 							0x40010000UL
#define EXTI_BASE							0x40010400UL


//=========================================================================================

//PERIPHERAL REGISTERS

//GPIOx registers

typedef struct{

	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;

}GPIOx_typedef;


//AFIO registers

typedef struct{

	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	uint32_t RESERVED0;
	volatile uint32_t MAPR2;

}AFIO_typedef;


//EXTI registers

typedef struct{


	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;

}EXTI_typedef;



//RCC registers

typedef struct{

	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t AHBSTR;
	volatile uint32_t CFGR2;

}RCC_typedef;

//=========================================================================================


//PERIPHERALS INSTANT

#define GPIOA   ((GPIOx_typedef*)GPIOA_BASE)
#define GPIOB   ((GPIOx_typedef*)GPIOB_BASE)
#define GPIOC   ((GPIOx_typedef*)GPIOC_BASE)
#define GPIOD   ((GPIOx_typedef*)GPIOD_BASE)
#define GPIOE   ((GPIOx_typedef*)GPIOE_BASE)

#define AFIO    ((AFIO_typedef *)AFIO_BASE)

#define RCC     ((RCC_typedef *)RCC_BASE)

#define EXTI    ((EXTI_typedef *)EXTI_BASE)

//=========================================================================================

//CLOCK ENABLE MACROS     **note: this macros is optional to be used as all the RCC registers are declared before in RCC_typedef**

#define  RCC_GPIOA_CLOCK_ENABLE  		(RCC->APB2ENR |=(1<<2))
#define  RCC_GPIOB_CLOCK_ENABLE  		(RCC->APB2ENR |=(1<<3))
#define  RCC_GPIOC_CLOCK_ENABLE  		(RCC->APB2ENR |=(1<<4))
#define  RCC_GPIOD_CLOCK_ENABLE  		(RCC->APB2ENR |=(1<<5))
#define  RCC_GPIOE_CLOCK_ENABLE  		(RCC->APB2ENR |=(1<<6))

#define  RCC_AFIO_ENABLE	    		(RCC->APB2ENR|=(1<<0))




#endif /* INC_STM32F013X6_H_ */
