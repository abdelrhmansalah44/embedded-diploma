/*
 * main.c
 *
 *  Created on: Oct 26, 2023
 *      Author: abdalrahman salah
 */

#include "pwm.h"
#define F_CPU 8000000
int main()
{
	pwm_config_t cnfg;

	DDRB |=(1<<3);

	cnfg.pwm_mode =pwm_fastmode;
	cnfg.pwm_clk = Prescaling_8;
	cnfg.pwm_output_mode =pwm_fastmode_noninverting;
	pwm_init(&cnfg);


	while(1)
	{

	pwm_dutycycle(50);
	}


}
