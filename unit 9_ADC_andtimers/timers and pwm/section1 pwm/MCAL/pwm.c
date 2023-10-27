/*
 * pwm.c
 *
 *  Created on: Oct 26, 2023
 *      Author: abdalrahman salah
 */


#include "pwm.h"
pwm_config_t *global_cnfg;


void pwm_init(pwm_config_t *configuration)
{
	E_STATUS_t val = OK;
	if(NULL_PTR == configuration)
	{
		val = NOK;
	}
	else
	{
		global_cnfg = configuration;
		if( (global_cnfg->pwm_mode ==pwm_fastmode) || (global_cnfg->pwm_mode ==pwm_phasecorrect) )
		{

			TCCR0 |=global_cnfg->pwm_mode;
			val =OK;
		}
		else
		{
			val= NOK;
		}



		if((global_cnfg->pwm_clk ==No_clck_src) || (global_cnfg->pwm_clk ==Prescaling_8))
		{

			TCCR0 |=global_cnfg->pwm_clk;
			val =OK;
		}
		else
		{
			val= NOK;
		}


		if((global_cnfg->pwm_output_mode ==pwm_fastmode_inverting) || (global_cnfg->pwm_output_mode ==pwm_fastmode_noninverting) || (global_cnfg->pwm_output_mode ==pwm_phase_noninverting) || (global_cnfg->pwm_output_mode ==pwm_phase_inverting) )
		{

			TCCR0 |=global_cnfg->pwm_output_mode;
			val =OK;
		}
		else
		{
			val= NOK;
		}


	}

	return val;

	TCCR0 |= global_cnfg->pwm_mode | global_cnfg->pwm_clk | global_cnfg->pwm_output_mode ;

	set_bit(TCCR0,5);

}

void pwm_stop()
{

		clear_bit(TCCR0,CS00);
		clear_bit(TCCR0,CS01);
		clear_bit(TCCR0,CS02);

}

void pwm_dutycycle(unsigned char duty_cycle)
{


	if(global_cnfg->pwm_output_mode ==pwm_phase_noninverting)
		OCR0 = (uint32_t)((duty_cycle*510)/2*100);
	else if(global_cnfg->pwm_output_mode ==pwm_phase_inverting)
		OCR0 = (uint32_t)((510-510*duty_cycle)/2*100);
	else{

	}

}

