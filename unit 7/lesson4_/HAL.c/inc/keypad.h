/*
 * keypad.h
 *
 * Created: 4/22/2021 6:32:00 PM
 *  Author: Marco
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "stm32f013x6.h"
#include "stm32_f103c6_gpio_driver.h"

#define KEYPAD_PORT GPIOB


#define R0 GPIO_PIN0
#define R1 GPIO_PIN1
#define R2 GPIO_PIN3
#define R3 GPIO_PIN4
#define C0 GPIO_PIN5
#define C1 GPIO_PIN6
#define C2 GPIO_PIN7
#define C3 GPIO_PIN8


void Keypad_init();
char Keypad_getkey();

#endif /* KEYPAD_H_ */
