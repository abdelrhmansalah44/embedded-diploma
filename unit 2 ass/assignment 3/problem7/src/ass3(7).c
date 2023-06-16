/*
 ============================================================================
 Name        : ass3(7).c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char arr[100];
	int cnt=0;
	printf("enter a string");
	fflush(stdin);fflush(stdout);
	scanf("%s",arr);
	for(int i=0;arr[i]!='\0';i++)
	{
		cnt++;
	}
	printf("length of string %d",cnt);

	return EXIT_SUCCESS;
}
