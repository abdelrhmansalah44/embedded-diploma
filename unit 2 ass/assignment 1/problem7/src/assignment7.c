/*
 ============================================================================
 Name        : assignment7.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */



#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x,y;
	printf("enter value of a :");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);
	printf("enter value of b :");
	fflush(stdin);fflush(stdout);
	scanf("%d",&y);
	x=x+y;
	y=x-y;
	x=x-y;
	printf("value of a after swaping %d \n",x);
	printf("value of b after swaping %d \n",y);
	return EXIT_SUCCESS;
}
