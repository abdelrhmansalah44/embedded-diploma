/*
 * led.h
 *
 *  Created on: Nov 30, 2023
 *      Author: abdalrahman salah
 */

#ifndef INC_LED_H_
#define INC_LED_H_


#include "stm32_f103c6_gpio_driver.h"


#define led_gpiox		GPIOA

#define led_green_pin		GPIO_PIN11
#define led_red_pin			GPIO_PIN0


void led_init();
void led__green_on();
void led_green_off();
void led__red_on();
void led_red_off();



#endif /* INC_LED_H_ */
