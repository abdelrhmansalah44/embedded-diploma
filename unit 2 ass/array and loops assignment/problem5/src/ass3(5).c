/*
 ============================================================================
 Name        : ass3(5).c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n,x,i;
	int arr[100];
	printf("enter no of elements");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("enter element to be searched");
		fflush(stdin);fflush(stdout);
		scanf("%d",&x);
      i=0;
		 while( i<n && x!=arr[i])
		 {
			 i++;
		 }

		 printf("found at %d",i+1);


	return EXIT_SUCCESS;
}
