/*
 * LCD.h
 *
 *  Created on: Sep 19, 2023
 *      Author: abdalrahman salah
 */

#ifndef LCD_H_
#define LCD_H_

#include "stm32_f103c6_gpio_driver.h"
#include "stm32f013x6.h"


#define LCD_PORT 			GPIOA

#define LCD_PORTCTRL 		GPIOB


#define RS_SWITCH           GPIO_PIN8
#define RW_SWITCH			GPIO_PIN9
#define EN_SWITCH			GPIO_PIN10




//#define Eight_bit_mode
#define Four_bit_mode


//#ifdef FOUR_BIT_MODE
//	#define DATA_SHIFT 4
//#endif




#define Func_set_8bit_1line        	0x30
#define Func_set_8bit_2line    	   	0x38
#define Func_set_4bit_1line        	0x20
#define Func_set_4bit_2line      	0x28
#define Entry_mode               	0x06
#define Display_off_cursor_off   	0x08
#define Display_on_cursor_on     	0x0E
#define Display_on_cursor_off    	0x0C
#define Display_on_cursor_blink  	0x0F
#define Shift_entire_Disp_left   	0x18
#define Shift_entire_Disp_right  	0x1C
#define Move_cursor_left_by_one  	0x10
#define Move_cursor_right_by_one 	0x14
#define Begin_first_row			 	0x80
#define Begin_second_row		 	0xC0
#define Clear_display            	0x01






void LCD_Custom_charachters();
void LCD_Location(unsigned char row , unsigned char column);
void LCD_init(void);
void LCD_Write_command(unsigned char command);
void LCD_Write_char(unsigned char data);
void LCD_Write_string(char* string);
void LCD_kick();
void LCD_clear_screen(void);
void LCD_is_busy();
void _delay_(int x);

#endif /* LCD_H_ */
