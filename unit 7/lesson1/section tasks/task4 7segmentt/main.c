/*
 * main.c
 *
 *  Created on: Sep 17, 2023
 *      Author: abdalrahman salah
 */




#include "util/delay.h"
#include "MemMap.h"
#include "utils.h"


int main()
{
	DDRC = 0xff;
	while(1)
	{
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++)
			{
				PORTC=0b1011|(i<<4);
				_delay_ms(100);
				PORTC=0b0111|(j<<4);
				_delay_ms(100);

			}
		}


	}


}
