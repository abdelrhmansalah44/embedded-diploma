

#include "lifo.h"
#include <stdio.h>

lifo_status lifo_push ( lifo_elements* lifo_buf, unsigned int item)
{
	// checking if the lifo is assigned or not
	if(!lifo_buf->head || !lifo_buf->base)
		return lifo_null;
	//-----------------------------------------

	//checking if lifo is full or not
	if(lifo_buf->length == lifo_buf->count )
		return lifo_full;
	//-------------------------------------

		//pushing elements in lifo
	*(lifo_buf->head) = item;
	lifo_buf->head++;
	lifo_buf->count++;

	return lifo_no_error;
}

lifo_status lifo_pop (lifo_elements* lifo_buf, unsigned int* item)
{
	// checking if the lifo is assigned or not
	if(!lifo_buf->head || !lifo_buf->base)
			return lifo_null;
	//-----------------------------------------

	//checking if lifo is empty or not
	if(lifo_buf->count == 0)
		return lifo_empty;
	//-----------------------------------------

	//removing elements from lifo
	lifo_buf->head--;
	*item = *(lifo_buf->head);
	lifo_buf->count--;
	return lifo_no_error;

}
 lifo_status lifo_init (lifo_elements* lifo_buf, unsigned int* buff ,unsigned int length)
{
	if(buff==NULL)
		return lifo_null;

	lifo_buf->head = buff;
	lifo_buf->base = buff;
	lifo_buf->length = length;
	lifo_buf->count = 0;

	return lifo_no_error;


}
