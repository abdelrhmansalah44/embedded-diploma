/*
 * fifo.h
 *
 *  Created on: Jul 23, 2023
 *      Author: abdalrahman salah
 */

#ifndef FIFO_H_
#define FIFO_H_

#define datatype unsigned char // to change data type easily
#define width 5 // to change the array size easily




typedef struct {
	datatype *head;
	datatype *tail;
	datatype *base;
	unsigned int length;
	unsigned int count;

}fifo_elements;


typedef enum{
	fifo_no_error,
	fifo_full,
	fifo_empty,
	fifo_null
}fifo_status;


fifo_status fifo_push(fifo_elements *fifo_buf , datatype item);
fifo_status fifo_pop(fifo_elements *fifo_buf , datatype *item);
fifo_status fifo_init(fifo_elements *fifo_buf ,datatype *buff, unsigned int length);
fifo_status fifo_is_full(fifo_elements *fifo_buf);

#endif /* FIFO_H_ */
