/*
 * alarm_monitor.c
 *
 *  Created on: Aug 15, 2023
 *      Author: abdalrahman salah
 */

#include "alarm_monitor.h"

void (*alarm_monitor_pointer_state)();

void High_Pressure_Detected(unsigned int st_val){

	if(st_val == true)
		alarm_monitor_pointer_state = STATE(alarmon_);

	else
		alarm_monitor_pointer_state = STATE(alarmoff_);
}


STATE_DEFINE(alarmon_)
{
	AM_state = St_alarm_on;

	Start_Alarm();

    alarm_monitor_pointer_state = STATE(alarmwaiting_);


}

STATE_DEFINE(alarmoff_)
{
	AM_state = St_alarm_off;

	Stop_Alarm();

}

STATE_DEFINE(alarmwaiting_)
{
	AM_state = St_alarm_waiting;

	Delay(600);

	alarm_monitor_pointer_state = STATE(alarmoff_);

}
