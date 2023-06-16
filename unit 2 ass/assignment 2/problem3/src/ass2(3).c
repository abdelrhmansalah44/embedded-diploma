/*
 ============================================================================
 Name        : ass2(3).c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float a,b,c;
	printf("enter three numbers");
	fflush(stdin);fflush(stdout);
	scanf("%f %f %f ",&a,&b,&c);
	if(a>=b && a>=c)
		printf("largest number is %.2f",a);
	else if(b>=a && b>=c)
		printf("largest number is %.2f",b);
	else
		printf("largest number is %.2f",c);
	return EXIT_SUCCESS;
}
