/*
 ============================================================================
 Name        : ass4f(1).c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int prime(int x);

int main(void) {
	int a = 0, b = 0, f;
	printf("enter two numbers ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d%d", &a, &b);
	for (int i = a; i <= b; i++) {
		if (prime(i) == 1)
			printf("%d ", i);

	}

	return EXIT_SUCCESS;
}
int prime(int x) {
	int f = 1;
	for (int i = 2; i <= x / 2; i++) {
		if (x % i == 0) {
			f = 0;
			break;
		}

	}
	return f;

}
