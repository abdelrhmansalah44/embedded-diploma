/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

//GPIO
#define GPIO_BASE 0x40010800
#define GPIOA_CRH *(volatile unsigned int *)(GPIO_BASE + 0x04)
#define GPIOA_ODR *(volatile unsigned int *)(GPIO_BASE + 0x0C)
#define GPIOA_CRL *(volatile unsigned int *)(GPIO_BASE + 0x00)


//RCC
#define RCC_BASE 0x40021000
#define RCC_APB2ENR *(volatile unsigned int *)(RCC_BASE+0x18)


//EXTI
#define EXTI_BASE 0x40010400
#define EXTI_RTSR *(volatile unsigned int *)(EXTI_BASE+0x08)
#define EXTI_IMR  *(volatile unsigned int *)(EXTI_BASE+0x00)
#define EXTI_PR  *(volatile unsigned int *)(EXTI_BASE+0x14)

//AFIO
#define AFIO_BASE 0x40010000
#define AFIO_EXTICR1 *(volatile unsigned int *)(AFIO_BASE+0x08)


//NVIC

#define NVIC_EXTI0 *(volatile unsigned int *)(0XE000E100)
void GPIO_init()
{
	GPIOA_CRH &= 0xff0fffff;
	GPIOA_CRH |= 0x00200000;
	GPIOA_CRL |=(1<<2);
}

void clock_init()
{
//	Bit 2 IOPAEN: I/O port A clock enable
//	Set and cleared by software.
//	0: I/O port A clock disabled
//	1:I/O port A clock enabled

	RCC_APB2ENR |= (1<<2);
	RCC_APB2ENR |= (1<<0);
}

int main(void)
{

	GPIO_init();
	clock_init();

	AFIO_EXTICR1 =0;


//	Bits 19:0 MRx: Interrupt Mask on line x
//	0: Interrupt request from Line x is masked
//	1: Interrupt request from Line x is not masked
//	Note: Bit 19 is used in connectivity line devices only and is reserved otherwise.
	EXTI_IMR |=(1<<0);


//	Bits 19:0 TRx: Rising trigger event configuration bit of line x
//	0: Rising trigger disabled (for Event and Interrupt) for input line
//	1: Rising trigger enabled (for Event and Interrupt) for input line.
//	Note: Bit 19 is used in connectivity line devices only and is reserved otherwise.
	EXTI_RTSR |=(1<<0);

//enable NVIC IRQ6
	NVIC_EXTI0 |=(1<<6);

	while(1);
}



void EXTI0_IRQHandler ()
{
	GPIOA_ODR ^=(1<<13);

//	Bits 19:0 PRx: Pending bit
//	0: No trigger request occurred
//	1: selected trigger request occurred
//	This bit is set when the selected edge event arrives on the external interrupt line. This bit is
//	cleared by writing a ‘1’ into the bit.
//	Note: Bit 19 is used in connectivity line devices only and is reserved otherwise.
	EXTI_PR |=(1<<0);

}
