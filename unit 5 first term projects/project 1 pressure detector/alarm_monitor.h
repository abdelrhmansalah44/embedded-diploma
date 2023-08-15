/*
 * alarm_monitor.h
 *
 *  Created on: Aug 15, 2023
 *      Author: abdalrahman salah
 */

#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_

#include "state.h"
enum{

	St_alarm_on,
	St_alarm_off,
	St_alarm_waiting

}AM_state;


STATE_DEFINE(alarmon_);
STATE_DEFINE(alarmoff_);
STATE_DEFINE(alarmwaiting_);


extern void (*alarm_monitor_pointer_state)();


#endif /* ALARM_MONITOR_H_ */
