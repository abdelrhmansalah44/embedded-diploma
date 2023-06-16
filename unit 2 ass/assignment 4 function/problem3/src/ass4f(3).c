/*
 ============================================================================
 Name        : ass4f(3).c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void reverse ();
int main(void) {
	printf("enter the sentence:");
	fflush(stdin);fflush(stdout);
	reverse();

	return EXIT_SUCCESS;
}
void reverse ()
{
	char c;
	scanf("%c",&c);
	if(c!='\n')
	{
		reverse();
		printf("%c",c);
	}
}
