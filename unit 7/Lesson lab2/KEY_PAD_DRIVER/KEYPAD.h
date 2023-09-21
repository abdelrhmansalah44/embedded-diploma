/*
 * KEYPAD.h
 *
 *  Created on: Sep 20, 2023
 *      Author: abdalrahman salah
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include<avr/io.h>
#include<util/delay.h>


#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

#define KEYPAD_PORT PORTD
#define KEYPAD_DDRX DDRD
#define keypadPIN 	PIND

void Key_pad_init();
char Key_pad_get_char();

#endif /* KEYPAD_H_ */
