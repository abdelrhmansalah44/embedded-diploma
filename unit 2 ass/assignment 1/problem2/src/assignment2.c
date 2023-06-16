/*
 ============================================================================
 Name        : assignment2.c
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
	printf("enter an integer:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);
	printf("yot entered  %d",x);

	return EXIT_SUCCESS;
}
