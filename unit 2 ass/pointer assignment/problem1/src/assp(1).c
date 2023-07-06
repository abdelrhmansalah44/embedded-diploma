/*
 ============================================================================
 Name        : assp(1).c
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
	int *p;
	printf("enter your number");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);
    p=&x;
    *p=25;
    printf("the value of x=%d and p=%d\n",x,*p);
    printf("the addres of x=%p and p=%p",&x,&p);
	return EXIT_SUCCESS;
}
