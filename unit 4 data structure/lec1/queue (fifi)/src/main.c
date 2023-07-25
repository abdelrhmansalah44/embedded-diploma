/*
 ============================================================================
 Name        : FIFO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "fifo.h"

unsigned int bufferarr[width];
int main(void) {

	fifo_elements uart;
	datatype i,temp=0;

   if(fifo_init(&uart , bufferarr,5)==fifo_no_error)

   printf("initialization is done \n");
   printf("-----------------\n");


	for(i=0;i<5;i++)
	{
		if(fifo_push(&uart,i)==fifo_no_error)
			printf("pushed elemnts is %d\n",i);
	}
	printf("---------------------\n");
	for(i=0;i<5;i++)
	{
		if(fifo_pop(&uart , &temp)==fifo_no_error)
			printf("poped items is %d\n",temp);


	}
	return EXIT_SUCCESS;
}
