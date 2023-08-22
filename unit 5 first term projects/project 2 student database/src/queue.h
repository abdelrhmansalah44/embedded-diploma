/*
 * queue.h
 *
 *  Created on: Aug 16, 2023
 *      Author: abdalrahman salah
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define datatype int

typedef struct {

char first_name[15];
	 char last_name[15];
	datatype student_id;
	float gpa;
	unsigned int course_id[5];

}student_element;



typedef struct {

	student_element *head;
	student_element *tail;
	student_element *base;
	datatype length;
	datatype count;

}queue_elements;

student_element queue_arr[50];

typedef enum{

	queue_no_error,
	queue_full,
	queue_null,
	queue_empty,
	queue_error


}queue_status;



queue_elements qu;



//// queue APIs
//queue_status queue_init(queue_elements *queue_buff , queue_elements *array , queue_elements length);
//queue_status queue_push(queue_elements *queue_buff , queue_elements item);
//queue_status queue_pop(queue_elements *queue_buff , queue_elements *item);
//queue_status queue_is_full(queue_elements *queue_buff);
//


extern queue_status add_student_manually();
extern queue_status add_student_file();
extern queue_status find_ID();
extern queue_status find_firstname();
extern queue_status find_course();
extern queue_status count();
extern queue_status delete_student();
extern queue_status update_student();
extern queue_status show_all();
extern void show_student_data();
extern void queue_init();
#endif /* QUEUE_H_ */
