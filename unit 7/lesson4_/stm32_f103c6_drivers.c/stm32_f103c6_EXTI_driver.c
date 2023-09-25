/*
 * stm32_f103c6_EXTI_driver.c
 *
 *  Created on: Sep 23, 2023
 *      Author: abdalrahman salah
 */

#include "stm32_f103c6_EXTI_driver.h"
#include "stm32_f103c6_gpio_driver.h"

#define AFIO_EXTI_GPIO_SELECTOR(X)  ((X==GPIOA)?0:\
									(X==GPIOB)? 1:\
									(X==GPIOC)? 2:\
									(X==GPIOD)? 3:0)

//******************************************************
//               GLOBAL VARIABLES
//******************************************************

void (*GP_IRQ_CallBack[15])(void);

void NVIC_EXTI_ENABLE(uint8_t IRQ) {
	switch (IRQ) {

	case EXTI0:
		NVIC_IRQ6_EXTI0_Enable();
		break;
	case EXTI1:
		NVIC_IRQ7_EXTI1_Enable();
		break;
	case EXTI2:
		NVIC_IRQ8_EXTI2_Enable();
		break;
	case EXTI3:
		NVIC_IRQ9_EXTI3_Enable();
		break;

	case EXTI4:
		NVIC_IRQ10_EXTI4_Enable();
		break;
	case EXTI5:
	case EXTI6:
	case EXTI7:
	case EXTI8:
	case EXTI9:
		NVIC_IRQ23_EXTI5_9_Enable();
		break;

	case EXTI10:
	case EXTI11:
	case EXTI12:
	case EXTI13:
	case EXTI14:
	case EXTI15:
		NVIC_IRQ40_EXTI10_15_Enable();
		break;

	default:
		break;

	}

}

void NVIC_EXTI_DISABLE(uint8_t IRQ) {
	switch (IRQ) {

	case EXTI0:
		NVIC_IRQ6_EXTI0_Disable();
		break;
	case EXTI1:
		NVIC_IRQ7_EXTI1_Disable();
		break;
	case EXTI2:
		NVIC_IRQ8_EXTI2_Disable();
		break;
	case EXTI3:
		NVIC_IRQ9_EXTI3_Disable();
		break;

	case EXTI4:
		NVIC_IRQ10_EXTI4_Disable();
		break;
	case EXTI5:
	case EXTI6:
	case EXTI7:
	case EXTI8:
	case EXTI9:
		NVIC_IRQ23_EXTI5_9_Disable();
		break;

	case EXTI10:
	case EXTI11:
	case EXTI12:
	case EXTI13:
	case EXTI14:
	case EXTI15:
		NVIC_IRQ40_EXTI10_15_Disable();
		break;

	default:
		break;

	}

}

static void update(EXTI_PINCONFIG *EXTI_pinconfig) {


	// 1- configure the pin as AFIO floating input
	GPIO_CONFIGURATION g_pin_config;
	g_pin_config.GPIO_PIN_MODE = GPIO_FLOATING_INPUT;
	g_pin_config.GPIO_PIN_NUMBER = EXTI_pinconfig->EXTI_PIN.GPIO_PIN;
	MCAL_GPIO_INIT(EXTI_pinconfig->EXTI_PIN.GPIO_PORT, &g_pin_config);

	//2-
	uint8_t AFIO_EXTI_index = (EXTI_pinconfig->EXTI_PIN.EXTI_LINE) / 4;
	uint8_t AFIO_EXTI_position = ((EXTI_pinconfig->EXTI_PIN.EXTI_LINE) % 4) * 4;
	AFIO->EXTICR[AFIO_EXTI_index] &= ~(0xf << AFIO_EXTI_position);
	AFIO->EXTICR[AFIO_EXTI_index] |=((AFIO_EXTI_GPIO_SELECTOR(EXTI_pinconfig->EXTI_PIN.GPIO_PORT) & 0X0F)<< AFIO_EXTI_position);
	//3 - //trigger case rising or falling or both

	EXTI->FTSR &= ~(1 << EXTI_pinconfig->EXTI_PIN.EXTI_LINE);
	EXTI->RTSR &= ~(1 << EXTI_pinconfig->EXTI_PIN.EXTI_LINE);

	if (EXTI_pinconfig->trigger_case == trigger_rise) {
		EXTI->RTSR |= EXTI_pinconfig->EXTI_PIN.GPIO_PIN;
	}

	else if (EXTI_pinconfig->trigger_case == trigger_fall) {
		EXTI->FTSR |= (EXTI_pinconfig->EXTI_PIN.GPIO_PIN);

	}

	else if (EXTI_pinconfig->trigger_case == trigger_fall_rise) {
		EXTI->FTSR |= (EXTI_pinconfig->EXTI_PIN.GPIO_PIN);
		EXTI->RTSR |= EXTI_pinconfig->EXTI_PIN.GPIO_PIN;

	}
	else{

	}

//4- IRQ HANDLING CALL-BACK
	GP_IRQ_CallBack[EXTI_pinconfig->EXTI_PIN.EXTI_LINE] =
			EXTI_pinconfig->P_IRQ_CallBack;

	if (EXTI_pinconfig->IRQ_enable == EXTI_PIN_ENABLE) {
		EXTI->IMR |= EXTI_pinconfig->EXTI_PIN.GPIO_PIN;
		NVIC_EXTI_ENABLE(EXTI_pinconfig->EXTI_PIN.EXTI_LINE);

	}

	else if (EXTI_pinconfig->IRQ_enable == EXTI_PIN_DISABLE) {
		EXTI->IMR &= ~(EXTI_pinconfig->EXTI_PIN.GPIO_PIN);
		NVIC_EXTI_ENABLE(EXTI_pinconfig->EXTI_PIN.EXTI_LINE);

	}

	else {

	}

}

void MCAL_EXTI_GPIO_INIT(EXTI_PINCONFIG *EXTI_pinconfig) {
	update(EXTI_pinconfig);
}
void MCAL_EXTI_DEINIT(void) {
	EXTI->IMR = 0X00000000;
	EXTI->EMR = 0X00000000;
	EXTI->RTSR = 0X00000000;
	EXTI->FTSR = 0X00000000;
	EXTI->SWIER = 0X00000000;
	EXTI->PR = 0XFFFFFFFF;

// WE MUST DISABLE THE NVIC
	NVIC_IRQ6_EXTI0_Disable();
	NVIC_IRQ7_EXTI1_Disable();
	NVIC_IRQ8_EXTI2_Disable();
	NVIC_IRQ9_EXTI3_Disable();
	NVIC_IRQ10_EXTI4_Disable();
	NVIC_IRQ23_EXTI5_9_Disable();
	NVIC_IRQ40_EXTI10_15_Disable();

}
void MCAL_EXTI_UPDATE(EXTI_PINCONFIG *EXTI_pinconfig) {

	update(EXTI_pinconfig);

}

void EXTI0_IRQHandler() {
	EXTI->PR |= (1 << 0);
	GP_IRQ_CallBack[0]();

}

void EXTI1_IRQHandler() {
	EXTI->PR |= (1 << 1);
	GP_IRQ_CallBack[1]();

}

void EXTI2_IRQHandler() {
	EXTI->PR |= (1 << 2);
	GP_IRQ_CallBack[2]();

}

void EXTI3_IRQHandler() {
	EXTI->PR |= (1 << 3);
	GP_IRQ_CallBack[3]();

}

void EXTI4_IRQHandler() {
	EXTI->PR |= (1 << 4);
	GP_IRQ_CallBack[4]();

}

void EXTI9_5_IRQHandler() {
	if (EXTI->PR & (1 << 5)) {
		EXTI->PR |= (1 << 5);
		GP_IRQ_CallBack[5]();
	}
	if (EXTI->PR & (1 << 6)) {
		EXTI->PR |= (1 << 6);
		GP_IRQ_CallBack[6]();
	}
	if (EXTI->PR & (1 << 7)) {
		EXTI->PR |= (1 << 7);
		GP_IRQ_CallBack[7]();
	}
	if (EXTI->PR & (1 << 8)) {
		EXTI->PR |= (1 << 8);
		GP_IRQ_CallBack[8]();
	}
	if (EXTI->PR & (1 << 9)) {
		EXTI->PR |= (1 << 9);
		GP_IRQ_CallBack[9]();
	}

}

void EXTI15_10_IRQHandler() {

	if (EXTI->PR & (1 << 10)) {
		EXTI->PR |= (1 << 10);
		GP_IRQ_CallBack[10]();
	}
	if (EXTI->PR & (1 << 11)) {
		EXTI->PR |= (1 << 11);
		GP_IRQ_CallBack[11]();
	}
	if (EXTI->PR & (1 << 12)) {
		EXTI->PR |= (1 << 12);
		GP_IRQ_CallBack[12]();
	}
	if (EXTI->PR & (1 << 13)) {
		EXTI->PR |= (1 << 13);
		GP_IRQ_CallBack[13]();
	}
	if (EXTI->PR & (1 << 14)) {
		EXTI->PR |= (1 << 14);
		GP_IRQ_CallBack[14]();
	}
	if (EXTI->PR & (1 << 15)) {
		EXTI->PR |= (1 << 15);
		GP_IRQ_CallBack[15]();
	}
}

