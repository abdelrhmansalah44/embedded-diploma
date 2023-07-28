/*
 * dc.c
 *
 *  Created on: Jul 28, 2023
 *      Author: abdalrahman salah
 */


#include "dc.h"
int dc_speed =0;
 void (*ptr_dc_state)();


 void DC_init()
 {
	 printf("dc motor initialized\n");
 }
STATE(DC_ideal)
{
	dc_state = dc_ideal;

	printf("dc ideal state speed---:%d\n",dc_speed);

}
STATE(DC_busy)
{
	dc_state = dc_busy;

	ptr_dc_state = state(DC_ideal);
	printf("dc_busy state speed---:%d\n",dc_speed);


}


void dc_motor_set(int s)
{

	dc_speed=s;
	ptr_dc_state = state(DC_busy);
	printf("cv set ------speed--%d---to dc_motor \n",dc_speed);

}
