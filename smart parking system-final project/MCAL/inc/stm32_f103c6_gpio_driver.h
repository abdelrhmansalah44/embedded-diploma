
/*
 * stm32_f103c6_gpio_driver.h
 *
 *  Created on: Sep 18, 2023
 *      Author: abdalrahman salah
 */

#ifndef INC_STM32_F103C6_GPIO_DRIVER_H_
#define INC_STM32_F103C6_GPIO_DRIVER_H_


#include "stm32f013x6.h"

//*******************************************************************
//                    User type definitions
//*******************************************************************
typedef struct{


	volatile uint16_t GPIO_PIN_NUMBER; // **note: to be able to specify the pin number look into (pin number reference) which can be found in this file**

	volatile uint16_t GPIO_PIN_MODE; // **note: to be able to select the pin number look into (pin mode reference) which can be found in this file**

	volatile uint16_t GPIO_OUTPUT_SPEED; //  **note: to be able to select the pin number look into (pin output speed reference) which can be found in this file**


}GPIO_CONFIGURATION;

//==================================================================================================
//==================================================================================================




//****************************************************************************
//                     MACROS configuration references
//****************************************************************************


//************************
//-> pin number reference
//************************

#define GPIO_PIN0 		((uint16_t)0x0001) 	//pin0
#define GPIO_PIN1 		((uint16_t)0x0002) 	//pin1
#define GPIO_PIN2 		((uint16_t)0x0004) 	//pin2
#define GPIO_PIN3 		((uint16_t)0x0008) 	//pin3
#define GPIO_PIN4 		((uint16_t)0x0010) 	//pin4
#define GPIO_PIN5 		((uint16_t)0x0020) 	//pin5
#define GPIO_PIN6 		((uint16_t)0x0040) 	//pin6
#define GPIO_PIN7 		((uint16_t)0x0080) 	//pin7
#define GPIO_PIN8 		((uint16_t)0x0100) 	//pin8
#define GPIO_PIN9 		((uint16_t)0x0200) 	//pin9
#define GPIO_PIN10 		((uint16_t)0x0400) 	//pin10
#define GPIO_PIN11 		((uint16_t)0x0800) 	//pin11
#define GPIO_PIN12		((uint16_t)0x1000) 	//pin12
#define GPIO_PIN13		((uint16_t)0x2000) 	//pin13
#define GPIO_PIN14		((uint16_t)0x4000) 	//pin14
#define GPIO_PIN15		((uint16_t)0x8000) 	//pin15
#define GPIO_ALL_PIN	((uint16_t)0xffff) 	//all pins selected

//==================================================================================================



//************************
//-> pin mode reference
//************************

//data taken from the data-sheet

//00: Analog mode ---------->0
//01: Floating input (reset state)---------->1
//10: Input with pull-up / pull-down---------->
//11: Reserved---------->3 will be used as pull-down

//00: General purpose output push-pull---------->4
//01: General purpose output Open-drain---------->5
//10: Alternate function output Push-pull---------->6
//11: Alternate function output Open-drain---------->7



#define GPIO_ANALOG   				0x00000000u
#define GPIO_FLOATING_INPUT			0x00000001u
#define GPIO_PULLUP_INPUT 			0x00000002u
#define GPIO_PULLDOWN_INPUT 		0x00000003u
#define GPIO_PUSHPULL_OUTPUT		0x00000004u
#define GPIO_OPENDRAIN_OUTPUT 		0x00000005u
#define GPIO_AFIO_PP_OUTPUT 		0x00000006u
#define GPIO_AFIO_OP_OUTPUT 		0x00000007u



//==================================================================================================


//************************
//-> pin output speed reference
//************************

// data taken from data-sheet
//01: Output mode, max speed 10 MHz. ----->1
//10: Output mode, max speed 2 MHz. ------>2
//11: Output mode, max speed 50 MHz. ----->3

#define GPIO_OUTPUT_10MHz  0x00000001u
#define GPIO_OUTPUT_2Hz    0x00000002u
#define GPIO_OUTPUT_50MHz  0x00000003u


//==================================================================================================
//==================================================================================================


/*
@ref GPIO_PIN_state
*/
#define GPIO_PIN_false                      0
#define GPIO_PIN_true                       1

/*
@ref GPIO_RETURN_LOCK
*/
#define GPIO_RETURN_LOCK_Enabled                1
#define GPIO_RETURN_LOCK_erorr                  0




//******************************************************************************
//                APIs supported by MCAL GPIO driver
//******************************************************************************


void MCAL_GPIO_INIT(GPIOx_typedef *GPIOx, GPIO_CONFIGURATION *pin_config);
void MCAL_GPIO_DeINIT(GPIOx_typedef *GPIOx);

void MCAL_GPIO_WRITE_PIN(GPIOx_typedef *GPIOx, uint16_t pin_number ,uint8_t value);
void MCAL_GPIO_WRITE_PORT(GPIOx_typedef *GPIOx , uint8_t value);

uint8_t MCAL_GPIO_READ_PIN(GPIOx_typedef *GPIOx, uint16_t pin_number);
uint16_t MCAL_GPIO_READ_PORT(GPIOx_typedef *GPIOx);

void MCAL_GPIO_TOGGLE(GPIOx_typedef *GPIOx, uint16_t pin_number);
void MCAL_GPIO_WriteGroup(GPIOx_typedef * GPIOx,uint16_t Value,uint16_t Mask);
uint8_t MCAL_GPIO_LOCKPIN(GPIOx_typedef *GPIOx, uint16_t pin_number);
#endif /* INC_STM32_F103C6_GPIO_DRIVER_H_ */
