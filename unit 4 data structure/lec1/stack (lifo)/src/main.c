/*
 ============================================================================
 Name        : LIFO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "lifo.h"

unsigned int lifoarr[5];
int main(void) {
	// asigning a driver for example uart from astruct type

	lifo_elements uart;
	 int i,temp=0;

	if(lifo_init(&uart , lifoarr,5)==lifo_no_error)
		printf("initialization is done\n");


	printf("-------------------\n");

	for(i=0;i<5;i++)
	{
		if(lifo_push(&uart,i) == lifo_no_error)
		printf("the pushed elements is %d \n ",i);
	}
printf("------------------------\n");
	for(i=0;i<5;i++)
		{
		if(lifo_pop(&uart,&temp) == lifo_no_error)
			printf("the poped elements is %d \n ",temp);
		}


	return EXIT_SUCCESS;
}
