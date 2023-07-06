/*
 ============================================================================
 Name        : assp(3).c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char str1[100];
	char str2[100];
	char *p;
	char *p2;

	p = str1;
	p2 = str2;
	int i = -1;
	printf("enter the sentence");
	fflush(stdin);
	fflush(stdout);
	scanf("%s", str1);

	while (*p != 0) {
		p++;
		i++;
	}
	while (i >= 0) {
		p--;
		*p2 = *p;
		p2++;
		--i;
	}
	*p2 = '\0';
	printf("the reversed sentence is %s", str2);

	return EXIT_SUCCESS;
}
