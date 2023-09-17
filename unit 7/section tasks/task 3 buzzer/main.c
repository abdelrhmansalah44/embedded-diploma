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

	set_bit(DDRD,4);
	set_bit(SFIOR,2);

	clear_bit(DDRD,0); //push button input
	while(1)
	{
		if(read_bit(PIND,0)==1)
		{
			set_bit(PORTD,4);
			_delay_ms(1000);
			clear_bit(PORTD,4);
		}

	}


}
