/*
 ============================================================================
 Name        : ass2(4).c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x;
	printf( "enter the number");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);
	if(x>=0)
		printf("%d is positive",x);
	else
		printf("%d is negative",x);
	return EXIT_SUCCESS;
}
