/*
 * LCD.c
 *
 *  Created on: Sep 19, 2023
 *      Author: abdalrahman salah
 */

#include "LCD.h"

void LCD_init()
{
	LCD_is_busy();

	//set control port as output
	LCD_PORTCTRL |= (1<<RS_SWITCH) | (1<<RW_SWITCH) | (1<<EN_SWITCH);

//====================================================
	#ifdef Eight_bit_mode
	//set data port as output
	LCD_DDRX |= 0xFF;

	lcd_clear_screen();
	_delay_ms(20);
	LCD_Write_command(Func_set_8bit_2line);
	#endif

	#ifdef Four_bit_mode
	//set data port as output
	LCD_DDRX |= 0xF0;
	LCD_clear_screen();
	_delay_ms(20);
	LCD_Write_command(0x02);
	LCD_Write_command(Func_set_4bit_2line);
	#endif
//====================================================
	LCD_Write_command(Display_on_cursor_blink);
	LCD_Write_command(Entry_mode);
	LCD_Write_command(Begin_first_row);
}

void LCD_Write_command(unsigned char commmand)
{

	#ifdef Eight_bit_mode
	LCD_PORT &= ~((1<<LCD_RS) | (1<<LCD_RW) | (1<<LCD_EN)); //write command Instruction
	LCD_PORT = commmand;
	LCD_kick();
	#endif

	#ifdef Four_bit_mode
	LCD_PORT = (LCD_PORT &(0x0F)) | (commmand & 0xF0);
	LCD_PORTCTRL &= ~((1<<RS_SWITCH) | (1<<RW_SWITCH));
	_delay_ms(1);
	LCD_kick();
	LCD_PORT = (LCD_PORT &(0x0F)) | ((commmand & 0x0F)<<4);
	LCD_PORTCTRL &= ~((1<<RS_SWITCH) | (1<<RW_SWITCH));
	_delay_ms(1);
	LCD_kick();
	_delay_ms(5);
	#endif
}

void LCD_Write_char(unsigned char data)
{

	#ifdef Eight_bit_mode
	//write data
	LCD_Ctrl_PORT &= ~((1<<LCD_RW) | (1<<LCD_EN));
	LCD_Ctrl_PORT |= (1<<LCD_RS);

	LCD_Data_PORT = data;
	LCD_kick();
	#endif

	#ifdef Four_bit_mode

	LCD_PORT = (LCD_PORT &(0x0F)) | (data & 0xF0);

	LCD_PORTCTRL &= ~(1<<RW_SWITCH);
	LCD_PORTCTRL |= (1<<RS_SWITCH);
	_delay_ms(1);
	LCD_kick();

	LCD_PORT = (LCD_PORT &(0x0F)) | ((data & 0x0F)<<4);
	LCD_PORTCTRL &= ~(1<<RW_SWITCH);
	LCD_PORTCTRL |= (1<<RS_SWITCH);
	_delay_ms(1);
	LCD_kick();

	_delay_ms(5);
	#endif
}
void LCD_Write_string(char* string)
{
	int count =0;
	for(count = 0 ; (string[count]!='\0') ; count++)
	{
		if(count == 16)
			LCD_Location(2,0);

		if(count == 32)
		{
			LCD_clear_screen();
			LCD_Location(1,0);
		}

		LCD_Write_char(string[count]);
	}
}

void LCD_is_busy(void)
{
	#ifdef Eight_bit_mode
	LCD_DDRxCTRL |= (1<<LCD_RS) | (1<<LCD_RW) | (1<<LCD_EN);
	LCD_DDRX = 0x00;

	LCD_PORTCTRL &= ~(1<<LCD_RS); //command register select

	LCD_PORTCTRL |= (1<<LCD_RW); //read mode

	LCD_kick();

	LCD_DDRX= 0xFF;
	LCD_PORTCTRL &= ~(1<<LCD_RW); //write
	#endif

	#ifdef Four_bit_mode
	LCD_DDRxCTRL |= (1<<RS_SWITCH) | (1<<RW_SWITCH) | (1<<EN_SWITCH);
	LCD_DDRX &= ~(0xFF<<4);

		LCD_PORTCTRL &= ~(1<<RS_SWITCH); //command register select

		LCD_PORTCTRL |= (1<<RW_SWITCH); //read mode

		LCD_kick();

		LCD_DDRX |= 0xF0;
		LCD_PORTCTRL &= ~(1<<RW_SWITCH); //write
	#endif
}

void LCD_kick()
{
	LCD_PORTCTRL |= (1<<EN_SWITCH); //set enable
	_delay_ms(5);
	LCD_PORTCTRL &= ~(1<<EN_SWITCH); //Reset enable
}

void LCD_clear_screen(void)
{
	LCD_Write_command(Clear_display);
}

void LCD_Location(unsigned char row , unsigned char column)
{
	switch(row)
	{
		case 1:
		LCD_Write_command(Begin_first_row + column);
		break;

		case 2:
		LCD_Write_command(Begin_second_row + column);
		break;
	}
}


void LCD_Custom_charachters()
{
	//To enable CGRAM and to save custom char
	LCD_Write_command(64);

	//Angry face
	 LCD_Write_char(0b00000);
	 LCD_Write_char(0b10001);
	 LCD_Write_char(0b11011);
	 LCD_Write_char(0b00000);
	 LCD_Write_char(0b00000);
	 LCD_Write_char(0b01110);
	 LCD_Write_char(0b10001);
	 LCD_Write_char(0b00000);

	 LCD_Write_command(Begin_first_row);
	 LCD_Write_char(0); //display the first custom char
	 _delay_ms(10);
}







