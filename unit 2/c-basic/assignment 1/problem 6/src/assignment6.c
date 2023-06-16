/*
 ============================================================================
 Name        : assignment6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x,y,temp;
	printf("enter value of a :");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);
	printf("enter value of b :");
	fflush(stdin);fflush(stdout);
	scanf("%d",&y);
	temp=x;
	x=y;
	y=temp;
	printf("value of a after swaping %d \n",x);
	printf("value of b after swaping %d \n",y);
	return EXIT_SUCCESS;
}
