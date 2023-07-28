/*
 * dc.h
 *
 *  Created on: Jul 28, 2023
 *      Author: abdalrahman salah
 */

#ifndef DC_H_
#define DC_H_

#include "state.h"
#include <stdio.h>
extern void (*ptr_dc_state)();
enum{

	dc_ideal,
	dc_busy
}dc_state;


STATE(DC_ideal);
STATE(DC_busy);

void DC_init();

#endif /* DC_H_ */
