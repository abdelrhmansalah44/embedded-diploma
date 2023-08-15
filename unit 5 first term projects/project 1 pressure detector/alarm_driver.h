/*
 * alarm_driver.h
 *
 *  Created on: Aug 15, 2023
 *      Author: abdalrahman salah
 */

#ifndef ALARM_DRIVER_H_
#define ALARM_DRIVER_H_

#include "state.h"
extern void (*alarm_driver_pointer)();


enum {
	St_Ad_init,
	St_Ad_waiting,
	St_Ad_alarm_on,
	St_Ad_alarm_off

}AD_state;


STATE_DEFINE(alarm_d_init);
STATE_DEFINE(alarm_d_on);
STATE_DEFINE(alarm_d_off);
STATE_DEFINE(alarm_d_waiting);


#endif /* ALARM_DRIVER_H_ */
