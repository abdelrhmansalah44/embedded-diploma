/*
 * main.c
 *
 *  Created on: Sep 28, 2023
 *      Author: abdalrahman salah
 */



#include "UART.h"
#include "lcd.h"

void wait(int x)
{
	for(int i=0;i<x;i++)
	{
		for(int j=0; j<=255; j++);
	}
}

void gpio_init(){


}

int main() {
//	char arr[100];
 char x;
	uart_init();
	LCD_INIT();
	wait(100);
	LCD_GOTO_XY(2, 0);
	LCD_WRITE_STRING("welcome");

	wait(100);
	LCD_clear_screen();
	transmit('a');
	transmit('b');
	transmit('c');
	while (1) {

//		wait(1000);
//     LCD_clear_screen();
//  LCD_GOTO_XY(2,0);
//  x= recieve();
//  LCD_WRITE_CHAR(x);


	}




}
