/*
 * alarm_driver.c
 *
 *  Created on: Aug 15, 2023
 *      Author: abdalrahman salah
 */

#include "alarm_driver.h"

void (*alarm_driver_pointer)();

void Start_Alarm()
{
	alarm_driver_pointer =STATE(alarm_d_on);
}

void Stop_Alarm()
{
	alarm_driver_pointer =STATE(alarm_d_off);
}


STATE_DEFINE(alarm_d_init)
{
	AD_state = St_Ad_init;

	alarm_driver_pointer = STATE(alarm_d_waiting);
}

STATE_DEFINE(alarm_d_on)
{
	AD_state = St_Ad_alarm_on;

	Set_Alarm_actuator(0);

	alarm_driver_pointer = STATE(alarm_d_waiting);


}


STATE_DEFINE(alarm_d_off)
{
	AD_state = St_Ad_alarm_off;

	Set_Alarm_actuator(1);

		alarm_driver_pointer = STATE(alarm_d_waiting);
}


STATE_DEFINE(alarm_d_waiting)
{
	AD_state = 	St_Ad_waiting;

}
