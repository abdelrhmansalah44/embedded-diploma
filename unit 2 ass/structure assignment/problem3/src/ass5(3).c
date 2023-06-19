/*
 ============================================================================
 Name        : ass5(3).c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct num{
	float real;
	float img;
};
struct num add(struct num x,struct num y);
int main(void) {
	struct num x,y,z;
	printf("enter the data of first numbers\n");
	printf("value of real and comlex:");
	fflush(stdin);fflush(stdout);
	scanf("%f %f",&x.real,&x.img);
	printf("enter the data of second numbers\n");
	printf("value of real and comlex:");
	fflush(stdin);fflush(stdout);
	scanf("%f %f",&y.real,&y.img);
    z=add(x,y);
	printf("sum=%f+%fi",z.real,z.img);

	return EXIT_SUCCESS;
}
struct num add(struct num x,struct num y){
	struct num sum;
	sum.img=x.img+y.img;
	sum.real=x.real+y.real;
	return sum;

}
