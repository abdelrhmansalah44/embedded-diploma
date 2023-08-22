/*
 ============================================================================
 Name        : proj2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
int main(void) {

	queue_init();
	while(1)
	{
	int x;

	printf("welcome to the student database\n");
	printf("enter the operation you want to make\n");
	printf("1. add student manually\n");
	printf("2. add student by file\n");
	printf("3. find student by id\n");
	printf("4. find student by first name\n");
	printf("5. delete student\n");
	printf("6. number of student appliying to a course\n");
	printf("7. number of students in the database\n");
	printf("8. update student data\n");
    printf("9. show all students\n");
    printf("============================================\n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);


	switch(x)
	{
	case 1:
		add_student_manually();
		break;
	case 2:
		add_student_file();
		break;

	case 3:
		find_ID();
		break;

	case 4:
		find_firstname();
		break;

	case 5:
		delete_student();
		break;

	case 6:
		find_course();
		break;

	case 7:
		count();
		break;

	case 8:
		update_student();
		break;

	case 9:
		show_all();
		break;

	default:
        printf("wrong choise try again\n");
	    break;

	}


	}



	return EXIT_SUCCESS;
}
