/*
 ============================================================================
 Name        : ass2(7).c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x,ans=1;
	printf("enter an integer");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);
	if(x<0)

		printf(" error factorial of negative number doesnt exist ");
	else
		for(int i=1;i<=x;i++)
		{
			ans*=i;
		}
	printf("factorial= %d",ans);

	return EXIT_SUCCESS;
}
