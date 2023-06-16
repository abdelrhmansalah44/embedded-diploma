/*
 ============================================================================
 Name        : ass4f(4).c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int power(int x,int y);
int main(void) {
	int x,y;
	printf("enter the base number:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);
	printf("enter the power number:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&y);
	printf("%d ^ %d=%d",x,y,power(x,y));
	return EXIT_SUCCESS;
}
int power(int x,int y)
{
	if(y==0)
		return 1;
	else
	return	(x*power(x,y-1));
}
