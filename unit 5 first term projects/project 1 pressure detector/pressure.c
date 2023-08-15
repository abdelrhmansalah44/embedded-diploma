/*
 * pressure.c
 *
 *  Created on: Aug 15, 2023
 *      Author: abdalrahman salah
 */

#include "pressure.h"

void (*pr_pointerstate)();

static unsigned int pval =0 ;


STATE_DEFINE(pressure_init)
{
	// defining init state
	pr_state = pr_init;
	pr_pointerstate = STATE(pressure_reading);

}

STATE_DEFINE(pressure_reading)
{
	// defining reading state
	pr_state = pr_reading;


	pval = getPressureVal();
	pr_pointerstate = STATE(pressure_waiting);
}


STATE_DEFINE(pressure_waiting)
{
	// defining waiting state
	pr_state = pr_waiting;

	// wait 100 seconds
	Delay(1000);

	//go to reading state to get a new value
	pr_pointerstate = STATE(pressure_reading);
}

unsigned int get_pval()
{
	return pval;
}
