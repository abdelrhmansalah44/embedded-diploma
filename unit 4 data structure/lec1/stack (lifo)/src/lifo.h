/*
 * lifo.h
 *
 *  Created on: Jul 23, 2023
 *      Author: abdalrahman salah
 */

#ifndef LIFO_H_
#define LIFO_H_


typedef struct {

	unsigned int *head;
	unsigned int *base;
	unsigned int length;
	unsigned int *count;

} lifo_elements;

typedef enum {
	lifo_no_error,
	lifo_full,
	lifo_empty,
	lifo_null
	// null means that the lifo is not present

}lifo_status;

// lifo functions for operations aka APIS

 lifo_status lifo_push ( lifo_elements* lifo_buf, unsigned int item);
 lifo_status lifo_pop (lifo_elements* lifo_buf, unsigned int* item);
 lifo_status lifo_init (lifo_elements* lifo_buf, unsigned int* buff ,unsigned int length);



#endif /* LIFO_H_ */
