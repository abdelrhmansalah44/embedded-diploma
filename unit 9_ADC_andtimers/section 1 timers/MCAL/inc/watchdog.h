/*
 * watchdog.h
 *
 *  Created on: Oct 23, 2023
 *      Author: abdalrahman salah
 */

#ifndef INC_WATCHDOG_H_
#define INC_WATCHDOG_H_


#include "avr/io.h"
#include "util/delay.h"

void watchdog_init();
void watchdog_enable();
void watchdog_disable();


#endif /* INC_WATCHDOG_H_ */
