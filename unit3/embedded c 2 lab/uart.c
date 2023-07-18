#include "uart.h"
#define UART0DR *((volatile unsigned int *) ((unsigned int *)0x101f1000))

void send(unsigned char *ptr)
{
while(*ptr!='\0')
{
	UART0DR=(unsigned int)(*ptr);
	ptr++;
}


}