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
#define NVIC_BASE							0xE000E100UL

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

//**********************************************************************
//						EXTI_VECTOR TABLE
//**********************************************************************


#define EXTI0_IRQ      6
#define EXTI1_IRQ      7
#define EXTI2_IRQ      8
#define EXTI3_IRQ      9
#define EXTI4_IRQ      10
#define EXTI5_IRQ      23
#define EXTI6_IRQ      23
#define EXTI7_IRQ      23
#define EXTI8_IRQ      23
#define EXTI9_IRQ      23
#define EXTI10_IRQ     40
#define EXTI11_IRQ     40
#define EXTI12_IRQ     40
#define EXTI13_IRQ     40
#define EXTI14_IRQ     40
#define EXTI15_IRQ     40

//========================================================================================


//**********************************************************************
//						NVIC_ENABLE_DISABLE_OPERATION
//**********************************************************************

#define NVIC_IRQ6_EXTI0_Enable()		(NVIC_ISER0 |= (1<<6))
#define NVIC_IRQ7_EXTI1_Enable()		(NVIC_ISER0 |= (1<<7))
#define NVIC_IRQ8_EXTI2_Enable()		(NVIC_ISER0 |= (1<<8))
#define NVIC_IRQ9_EXTI3_Enable()		(NVIC_ISER0 |= (1<<9))
#define NVIC_IRQ10_EXTI4_Enable()		(NVIC_ISER0 |= (1<<10))
#define NVIC_IRQ23_EXTI5_9_Enable()		(NVIC_ISER0 |= (1<<23))
#define NVIC_IRQ40_EXTI10_15_Enable()	(NVIC_ISER1 |= (1<<8))


#define NVIC_IRQ6_EXTI0_Disable()		(NVIC_ICER0 |= (1<<6))
#define NVIC_IRQ7_EXTI1_Disable()		(NVIC_ICER0 |= (1<<7))
#define NVIC_IRQ8_EXTI2_Disable()		(NVIC_ICER0 |= (1<<8))
#define NVIC_IRQ9_EXTI3_Disable()		(NVIC_ICER0 |= (1<<9))
#define NVIC_IRQ10_EXTI4_Disable()		(NVIC_ICER0 |= (1<<10))
#define NVIC_IRQ23_EXTI5_9_Disable()	(NVIC_ICER0 |= (1<<23))
#define NVIC_IRQ40_EXTI10_15_Disable()	(NVIC_ICER1 |= (1<<8))

//========================================================================================

//**********************************************************************
//					NVIC ENABLE AND DISABLE REGISTERS
//**********************************************************************



#define NVIC_ISER0    *(volatile unsigned int*)(NVIC_BASE+ 0x000)
#define NVIC_ISER1    *(volatile unsigned int*)(NVIC_BASE+ 0x004)
#define NVIC_ISER2    *(volatile unsigned int*)(NVIC_BASE+ 0x008)
#define NVIC_ICER0    *(volatile unsigned int*)(NVIC_BASE+ 0x080)
#define NVIC_ICER1    *(volatile unsigned int*)(NVIC_BASE+ 0x084)
#define NVIC_ICER2    *(volatile unsigned int*)(NVIC_BASE+ 0x088)

//=========================================================================================






//*******************************************************
//				PERIPHERAL REGISTERS
//*******************************************************


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
	volatile uint32_t EXTICR[4];

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
