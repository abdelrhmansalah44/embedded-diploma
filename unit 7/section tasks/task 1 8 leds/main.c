/*
 * main.c
 *
 *  Created on: Sep 17, 2023
 *      Author: abdalrahman salah
 */



#include "MemMap.h"
#include "utils.h"
#include "avr/delay.h"
#include "util/delay.h"
int main()
{

	DDRD =0X00;
	DDRD|=(0b111<<5);
int i;
	while(1)
	{
		for(i=5;i<8;i++)
		{
			set_bit(PORTD,i);
			_delay_ms(500);
		}
		for(;i>=5;i--)
		{
			clear_bit(PORTD,i);
			_delay_ms(500);
		}


	}



}
