/*
 * main.c
 *
 *  Created on: Sep 20, 2023
 *      Author: abdalrahman salah
 */


#include "KEY_PAD_DRIVER/KEYPAD.h"
#include "LCD_DRIVER/LCD.h"




int main(void)
{
    LCD_init();
     Key_pad_init();




	char pressed_key;
    while (1)
    {
		pressed_key = Key_pad_get_char();

		switch(pressed_key)
		{
			case '!':
			LCD_clear_screen();
			break;

			case 'N':
			break;

			default:
			LCD_Write_char(pressed_key);
		}
    }
}




