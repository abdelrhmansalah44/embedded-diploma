/*
 ============================================================================
 Name        : assp(4).c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int arr[15];
	int *p = &arr[0];

	printf("enter the array elements\n");
	for (int i = 0; i < 5; i++) {
		printf("element-%d:", i + 1);
		fflush(stdin);
		fflush(stdout);
		scanf("%d", p);
		p++;
	}

	printf("the reversed elemnts is \n");
	p = &arr[4];
	for (int i = 5; i > 0; i--) {
		printf("element-%d: %d\n ", i, *p);
		p--;
	}
	return EXIT_SUCCESS;
}
