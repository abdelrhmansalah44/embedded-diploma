/*
 ============================================================================
 Name        : ass5(1).c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */



#include <stdio.h>

struct student
{
	char name[50];
	int roll;
	float marks;
};

int main(void) {
	struct student s;
	printf("enter name:");
	fflush(stdin);
	fflush(stdout);
	scanf("%s", s.name);

	printf("enter roll number:");
	fflush(stdin);
	fflush(stdout);
	scanf("%d", &s.roll);

	printf("enter marks:");
	fflush(stdin);
	fflush(stdout);
	scanf("%f", &s.marks);

	printf("displaying information\n");
	printf("name: %s\n",s.name);
	printf("roll: %d\n",s.roll);
	printf("marks: %f\n",s.marks);

return 0;
}

