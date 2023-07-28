/*
 * us.c
 *
 *  Created on: Jul 28, 2023
 *      Author: abdalrahman salah
 */

#include "us.h"
void (*ptr_us_state)();

int us_distance=0;


void us_init()
{
	printf("hall sensor initialized\n");
	printf("-----------------------\n");
}

STATE(US_busy){
 us_state=us_busy;
 us_distance = random_testdata(45,55,1);
 printf("us busy state distance---%d\n ",us_distance);



 us_set_distance(us_distance);
  ptr_us_state = state(US_busy) ;

}


int random_testdata(int l,int r,int count)
{
int i;
for(i=0;i<count;i++)
{
	int random= (rand() % (r-l+1))+l;
	return random;
}
	return 0;
}

