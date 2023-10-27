/*
 * watchdog.c
 *
 *  Created on: Oct 23, 2023
 *      Author: abdalrahman salah
 */



#include "watchdog.h"


void watchdog_init()
{
	//prescaling watchdog for 1sec
	WDTCR |= (1<<WDP2);
	WDTCR |= (1<<WDP1);
	WDTCR &=~(1<<WDP0);

}

void watchdog_enable()
{
	WDTCR |=WDE;

}

void watchdog_disable()
{
	WDTCR |=1<<WDE;
		WDTCR |=1<<WDTOE;

		WDTCR = 0x00;
}
