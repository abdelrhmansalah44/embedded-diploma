/*
 * KEYPAD.h
 *
 *  Created on: Sep 20, 2023
 *      Author: abdalrahman salah
 */



#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "stm32_f103c6_gpio_driver.h"
#include "stm32f013x6.h"


#define R0 GPIO_PIN0
#define R1 GPIO_PIN1
#define R2 GPIO_PIN3
#define R3 GPIO_PIN4

#define C0 GPIO_PIN5
#define C1 GPIO_PIN6
#define C2 GPIO_PIN7
#define C3 GPIO_PIN8

#define KEYPAD_PORT GPIOB


void Key_pad_init();
char Key_pad_get_char();


#endif /* KEYPAD_H_ */
