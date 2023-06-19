/*
 ============================================================================
 Name        : ass5(5).c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define pi 3.14
int main(void) {
	int r;
	float area;
	printf("enter the radius");
    fflush(stdin);fflush(stdout);
    scanf("%d",&r);
	area=r*r*pi;
	printf("Area= %f",area);
	return EXIT_SUCCESS;
}
