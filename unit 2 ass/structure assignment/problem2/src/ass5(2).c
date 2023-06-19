/*
 ============================================================================
 Name        : ass5(2).c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


struct data {
	int feet;
	float inche;
};

int main(void) {
struct data x,y,sum;

printf("enter the information of the first distance");
fflush(stdin);fflush(stdout);
scanf("%d %f",&x.feet,&x.inche);

printf("enter the information of the second distance");
fflush(stdin);fflush(stdout);
scanf("%d %f",&y.feet,&y.inche);

sum.feet=x.feet+y.feet;
sum.inche=x.inche+y.inche;

if(sum.inche>12.0)
{
sum.inche-=12;
++sum.feet;
}
printf("sum of distance %d   %f",sum.feet,sum.inche);


	return EXIT_SUCCESS;
}
