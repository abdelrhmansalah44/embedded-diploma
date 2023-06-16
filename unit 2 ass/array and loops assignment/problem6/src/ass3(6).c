/*
 ============================================================================
 Name        : ass3(6).c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char arr[100],ch;
	int cnt=0;
	printf("enter a string ");
	fflush(stdin);fflush(stdout);;
	scanf("%s",arr);
	printf("enter a character to find its frequency");
		fflush(stdin);fflush(stdout);;
		scanf("%c",&ch);
		for(int i=0;arr[i]!=100;i++)
		{
			if(ch==arr[i])
			{
			   cnt++;
			}
		}
			printf("frequency of %c is %d",ch,cnt);

	return EXIT_SUCCESS;
}
