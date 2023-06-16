/*
 ============================================================================
 Name        : ass2(8).c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char c;
	float x,y;
	printf("enter operator either + or - or * or divide");
	fflush(stdin);fflush(stdout);
	scanf("%c",&c);
	printf("enter two operands");
	fflush(stdin);fflush(stdout);
	scanf("%f %f",&x,&y);

	switch(c)
	{
	case '+':
		printf("%.1f + %.1f = %.1f",x,y,(x+y));
	break;
	case '-':
		printf("%.1f - %.1f = %.1f",x,y,(x-y));
	break;
	case '*':
		printf("%.1f * %.1f = %.1f",x,y,(x*y));
	break;
	case '/':
		printf("%.1f / %.1f = %.1f",x,y,(x/y));
		break;

	default:
		printf("none");
		break;

	}
	return EXIT_SUCCESS;
}
