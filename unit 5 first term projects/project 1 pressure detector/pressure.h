/*
 * pressure.h
 *
 *  Created on: Aug 15, 2023
 *      Author: abdalrahman salah
 */

#ifndef PRESSURE_H_
#define PRESSURE_H_

#include "state.h"

enum {

	// pressure sensor states
	pr_init,
	pr_reading,
	pr_waiting

}pr_state;

// pressure sensor functions

STATE_DEFINE(pressure_reading);
STATE_DEFINE(pressure_waiting);
STATE_DEFINE(pressure_init);
unsigned int get_pval();
extern void (*pr_pointerstate)();
#endif /* PRESSURE_H_ */
