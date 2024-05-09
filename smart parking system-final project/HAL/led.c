/*
 * led.c
 *
 *  Created on: Nov 30, 2023
 *      Author: abdalrahman salah
 */

#include "led.h"

void led_init() {

	GPIO_CONFIGURATION pincnfg;

	//green led init
	pincnfg.GPIO_PIN_NUMBER = led_green_pin;
	pincnfg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_10MHz;
	pincnfg.GPIO_PIN_MODE = GPIO_PUSHPULL_OUTPUT;
	MCAL_GPIO_INIT(led_gpiox, &pincnfg);

	//red led init
	pincnfg.GPIO_PIN_NUMBER = led_red_pin;
	pincnfg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_10MHz;
	pincnfg.GPIO_PIN_MODE = GPIO_PUSHPULL_OUTPUT;
	MCAL_GPIO_INIT(led_gpiox, &pincnfg);

}
void led__green_on() {

	MCAL_GPIO_WRITE_PIN(led_gpiox, led_green_pin, GPIO_PIN_true);

}
void led_green_off() {

	MCAL_GPIO_WRITE_PIN(led_gpiox, led_green_pin, GPIO_PIN_false);

}
void led__red_on() {

	MCAL_GPIO_WRITE_PIN(led_gpiox, led_red_pin, GPIO_PIN_true);

}
void led_red_off() {

	MCAL_GPIO_WRITE_PIN(led_gpiox, led_red_pin, GPIO_PIN_false);

}
