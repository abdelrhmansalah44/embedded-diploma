/*
 ============================================================================
 Name        : ass2(2).c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char ch;
	printf("enter the alphabet \n");
	fflush(stdin);
	fflush(stdout);
	scanf("%c", &ch);
	if (ch=='a'|| ch=='A'||ch=='i'||ch=='I'||ch=='e'||ch=='E'||ch=='u'||ch=='U'||ch=='o'||ch=='O')

		printf(" %c is a vowel ",ch);

	else
		printf(" %c is a consonant ",ch);

	return EXIT_SUCCESS;
}
