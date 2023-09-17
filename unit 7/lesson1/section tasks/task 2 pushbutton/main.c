/*
 * main.c
 *
 *  Created on: Sep 17, 2023
 *      Author: abdalrahman salah
 */

#include "MemMap.h"
#include "utils.h"
#include "avr/delay.h"

int main()
{
	DDRD =0x00;
	DDRD|=(0b111<<5);

	set_bit(SFIOR,2); // disabling pullup resistor for all pins
	clear_bit(DDRD,0);  //configuring PD0 as an input

	int i;
	while(1)
	{
		if((read_bit(PIND,0))==1)
		{
			while((read_bit(PIND,0))==1)
			{
				for(i=5;i<8;i++)
				{
					set_bit(PORTD,i);
					_delay_ms(500);

				}
			}

		}
		else
		{
				for(;i>=5;i--)
				{
					clear_bit(PORTD,i);
					_delay_ms(500);

				}

		}

	}


}
