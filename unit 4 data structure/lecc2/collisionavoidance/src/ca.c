/*
 * ca.c
 *
 *  Created on: Jul 28, 2023
 *      Author: abdalrahman salah
 */

#include "ca.h"

int ca_speed =0,ca_distance=0,threshold=50;

 void (*PTR_STATE)();


void us_set_distance(int d)
{
	ca_distance=d;
	(ca_distance<=threshold) ? (PTR_STATE= state(CV_waiting)) : (PTR_STATE=state(CV_driving));
	printf("ultrasonic set ------distance--%d---to cv \n",ca_distance);

}

STATE(CV_waiting)

{
	//giving the waiting state
	cv_state = cv_waiting;
	printf("distance is:%d speed is:%d\n",ca_distance,ca_speed);
	//attributes
	 ca_speed =0;
	dc_motor_set(ca_speed);
}
 STATE(CV_driving){

	//giving the waiting state
	cv_state = cv_driving;
	printf("distance is:%d speed is:%d\n", ca_distance, ca_speed);
	//attributes
	ca_speed = 30;
	dc_motor_set(ca_speed);


}
