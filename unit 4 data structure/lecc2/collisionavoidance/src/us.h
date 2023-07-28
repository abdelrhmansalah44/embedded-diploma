/*
 * us.h
 *
 *  Created on: Jul 28, 2023
 *      Author: abdalrahman salah
 */

#ifndef US_H_
#define US_H_

#include "state.h"
#include <stdio.h>

enum
{
	us_busy

}us_state;


STATE(US_busy);
void us_init();
extern void (*ptr_us_state)();


#endif /* US_H_ */
