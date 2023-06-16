/*
 ============================================================================
 Name        : ass3(8).c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>

int main(void) {
	char arr[100], x;
	int j = 0;
	printf("enter the string");
	fflush(stdin);
	fflush(stdout);
	scanf("%s", arr);

	j = strlen(arr) - 1;
	for (int i = 0; i < strlen(arr); i++) {
		if (i < j) {
			x = arr[i];
			arr[i] = arr[j];
			arr[j] = x;
			j--;
		}
	}
	printf("%s", arr);

	return 0;
}
