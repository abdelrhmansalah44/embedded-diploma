/*
 * mainalgorithm.c
 *
 *  Created on: Aug 15, 2023
 *      Author: abdalrahman salah
 */

#include "mainalgorithm.h"
#include "pressure.h"

void (*main_pointer)();

static unsigned int MA_val;
static unsigned int threshold =20;

STATE_DEFINE(MA_high_pressure_detected)
{
	MA_state = MA_pressure_detected;
	MA_val = get_pval();

	if(MA_val >threshold)
	{
		High_Pressure_Detected(true);
		main_pointer = STATE(MA_high_pressure_detected) ;
	}

	else
		main_pointer = STATE(MA_high_pressure_detected) ;


}
