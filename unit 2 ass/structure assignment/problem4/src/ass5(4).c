/*
 ============================================================================
 Name        : ass5(4).c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
struct student {
	char name[50];
	int roll;
	int marks;
};

int main(void) {


	struct student x[10];
	printf("enter information of students:\n");

	for(int i=0;i<10;i++)
	{
		x[i].roll=i+1;
		printf("for roll number %d\n",x[i].roll);
		printf("enter name:");
		fflush(stdin);fflush(stdout);
		scanf("%s",x[i].name);

		printf("enter marks:");
		fflush(stdin);fflush(stdout);
		scanf("%d",&x[i].marks);

	}

	printf("displaying info of students\n");
	for(int i=0;i<10;i++)
	{
		printf("info for roll number %d\n",x[i].roll);
		printf("name: %s\n",x[i].name);
		printf("marks: %d\n",x[i].marks);
	}

	return EXIT_SUCCESS;
}
