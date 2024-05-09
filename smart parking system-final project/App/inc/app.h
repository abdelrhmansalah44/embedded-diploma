/*
 * app.h
 *
 *  Created on: Nov 30, 2023
 *      Author: abdalrahman salah
 */

#ifndef INC_APP_H_
#define INC_APP_H_



//=================================================================
//					include files
//=================================================================
#include "stm32_f103c6_gpio_driver.h"
#include "stm32_f103c6_uart_driver.h"
#include "Servo_Motor.h"
#include "Timer.h"
#include "led.h"
#include "lcd.h"
#include "keypad.h"
#include "PIR.h"




//=================================================================
//					App apis
//=================================================================

void uart1_config();
void uart2_config();

void parking_init();
void parking_entry();
void parking_exit();

void HAL_init();
void MCAL_init();
#endif /* INC_APP_H_ */
