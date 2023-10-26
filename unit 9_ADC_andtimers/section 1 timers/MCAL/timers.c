/*
 * timers.c
 *
 *  Created on: Oct 23, 2023
 *      Author: abdalrahman salah
 */


#include "timers.h"

timer_config_t *global_cnfg;
ptr_callback overflow_callback;
ptr_callback compare_callback;

unsigned char overflow_number=0;


E_STATUS_t timer_init(timer_config_t *configuration)
{
	E_STATUS_t val=OK;

	if(NULL_PTR == configuration)
		val= NOK;

	else {
		global_cnfg = configuration;

		//checking the mode
		if (global_cnfg->timer_mode == Normal
				|| global_cnfg->timer_mode == CTC) {
			TCCR0 |= global_cnfg->timer_mode;
		} else {
			val = NOK;
		}
		if (global_cnfg->timer_clk >= No_clck_src
				&& global_cnfg->timer_clk <= EXT_CLK_RISING)

				{
			TCCR0 |= global_cnfg->timer_clk;

		} else {
			val = NOK;
		}

		if (global_cnfg->timer_compare == OCEI_ENABLE
				|| global_cnfg->timer_compare == OCEI_ENABLE) {
			TIMSK |= global_cnfg->timer_compare;

		} else {
			val = NOK;
		}
		if (global_cnfg->timer_overflow == TOEI_ENABLE
				|| global_cnfg->timer_overflow == TOEI_DISABLE) {
			TIMSK |= global_cnfg->timer_overflow;

		}

		else {
			val = NOK;
		}

	}
		return val;
}
E_STATUS_t timer_stop()
{
	E_STATUS_t val =OK;
	clear_bit(TCCR0,CS00);
	clear_bit(TCCR0,CS01);
	clear_bit(TCCR0,CS02);

	return val;
}

E_STATUS_t timer_getcompare(unsigned char *tickers)
{
	E_STATUS_t val =OK;
	*tickers =OCR0;
	return val;


}
E_STATUS_t timer_setcompare(unsigned char tickers)
{
	E_STATUS_t val =OK;
	OCR0=tickers;
		return val;

}

E_STATUS_t timer_getcounter(unsigned char *tickers)
{
	E_STATUS_t val =OK;
			*tickers =TCNT0;
			return val;

}
E_STATUS_t timer_setcounter(unsigned char tickers)
{
	E_STATUS_t val =OK;
		TCNT0=tickers;
			return val;
}

E_STATUS_t timer_getoverflow(unsigned char *tickers)
{
	E_STATUS_t val =OK;
		*tickers =overflow_number;
		return val;
}
E_STATUS_t timer_setoverflow(unsigned char tickers)
{
	E_STATUS_t val =OK;
	overflow_number=tickers;
				return val;
}

void timer_overflow_callback(ptr_callback callback)
{
	overflow_callback =callback;

}
void timer_compare_callback(ptr_callback callback)
{

	compare_callback = callback;
}

ISR(TIMER0_COMP_vect)
{
	overflow_number++;

	compare_callback();

}


ISR(TIMER0_OVF_vect)
{
	overflow_number++;
	overflow_callback();

}
