/*
 ============================================================================
 Name        : assp(2).c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char *p;
	char str[27];
	p=str;
	for(int i=0;i<26;i++)
	{
		*p=i+'A';
		p++;
	}
	p=str;
for(int i=0;i<27;i++)
{
	printf("%c ",*p);
	p++;

}
	return EXIT_SUCCESS;
}
