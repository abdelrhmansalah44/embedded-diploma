/*
 ============================================================================
 Name        : ass2(6).c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n,sum=0;
	printf("enter an integer");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
	{
		sum+=i;
	}
	printf("sum= : %d",sum);
	return EXIT_SUCCESS;
}
