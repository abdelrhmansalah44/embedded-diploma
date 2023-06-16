/*
 ============================================================================
 Name        : ass3(2).c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int arr[100];
	int n;
	int avg,sum=0.0;

	printf("enter number of data ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("enter number:");
		fflush(stdin);fflush(stdout);
			scanf("%d",&arr[i]);


	}
	for(int i=0;i<n;i++)
		{
			sum+=arr[i];
		}
	avg=sum/n;
	printf(" average: %d",avg);

	return EXIT_SUCCESS;
}
