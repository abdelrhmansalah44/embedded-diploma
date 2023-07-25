/*
 * fifo.c
 *
 *  Created on: Jul 23, 2023
 *      Author: abdalrahman salah
 */

#include "fifo.h"
#include <stdio.h>

fifo_status fifo_init(fifo_elements *fifo_buf ,datatype *buff, unsigned int length)
{
	if(buff == NULL)
		return fifo_full;

	fifo_buf->head=buff;
	fifo_buf->tail=buff;
	fifo_buf->base=buff;
	fifo_buf->count=0;
	fifo_buf->length=length;

	return fifo_no_error;

}
//-----------------------------------------------------------------

fifo_status fifo_push(fifo_elements *fifo_buf , datatype item)
{
	if(!fifo_buf->head || !fifo_buf->tail || !fifo_buf->base)
		return fifo_null;

	if(fifo_is_full(fifo_buf)==fifo_full)
		return fifo_full;


	*(fifo_buf->head)=item;
	fifo_buf->count++;

	//in case of circular fifo
	if(fifo_buf->head == (fifo_buf->base+(fifo_buf->length * sizeof(datatype))))
		fifo_buf->head=fifo_buf->base;
	else
	fifo_buf->head++;


	return fifo_no_error;

}
//--------------------------------------------------------------------
fifo_status fifo_pop(fifo_elements *fifo_buf , datatype *item)
{
	if(!fifo_buf->head || !fifo_buf->tail || !fifo_buf->base)
			return fifo_null;

if(fifo_buf->count==0)
	return fifo_empty;

        *item =*(fifo_buf->tail);
		fifo_buf->count--;

	//in case of circular fifo
	if(fifo_buf->tail == (fifo_buf->base+(fifo_buf->length * sizeof(datatype))))
		fifo_buf->tail=fifo_buf->base;

	else
		fifo_buf->tail++;

	return fifo_no_error;

}
//-------------------------------------------------------------
fifo_status fifo_is_full(fifo_elements *fifo_buf)
{
	if(!fifo_buf->head || !fifo_buf->tail || fifo_buf->base)
			return fifo_null;

	if(fifo_buf->length == fifo_buf->count)
		return fifo_full;

	return fifo_no_error;

}
