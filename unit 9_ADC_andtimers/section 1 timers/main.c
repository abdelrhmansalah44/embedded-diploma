/*
 * main.c
 *
 *  Created on: Oct 23, 2023
 *      Author: abdalrahman salah
 */

#include "timers.h"
#include "util/delay.h"
extern overflow_number;

void overflow_irq()
{
	toggle_bit(PORTC,0);
	_delay_ms(1000);
	PORTA = overflow_number;


}

int main()
{

	set_bit(DDRC,0);


	DDRA =0xff;
	sei();
	timer_compare_callback(overflow_irq);
	timer_config_t cnfg ={CTC,Prescaling_8 ,OCEI_ENABLE ,TOEI_DISABLE};
	timer_getcompare(0xf0);
	timer_init(&cnfg);




	while(1)
	{

	}

}
