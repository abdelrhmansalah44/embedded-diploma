/*
 * UART.h
 *
 *  Created on: Sep 28, 2023
 *      Author: abdalrahman salah
 */

#ifndef INC_UART_H_
#define INC_UART_H_


#include <avr/io.h>
#include <avr/interrupt.h>
#include "utils.h"
#include "lcd.h"

void uart_init();
void transmit(char x);
char recieve();
void send_string(char* ptr);
void recieve_string(char* buff);
void send_number(uint32_t num);
uint32_t recieve_number();


#endif /* INC_UART_H_ */
