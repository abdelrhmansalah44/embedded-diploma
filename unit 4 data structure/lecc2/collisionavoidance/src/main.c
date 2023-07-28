/*
 ============================================================================
 Name        : collisionavoidance.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "state.h"
#include "ca.h"
#include "us.h"
#include "dc.h"
void setup()
{
	DC_init();
	us_init();
	PTR_STATE=state(CV_waiting);
	ptr_us_state = state(US_busy);
	ptr_dc_state = state(DC_ideal);
}

int main(void) {

	setup();
	volatile int i;
	for(i=0;i<10;i++)
	{
		PTR_STATE();
		ptr_us_state();
		ptr_dc_state();
	}

	return EXIT_SUCCESS;
}
