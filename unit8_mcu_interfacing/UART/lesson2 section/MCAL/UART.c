/*
 * UART.c
 *
 *  Created on: Sep 28, 2023
 *      Author: abdalrahman salah
 */

#include "UART.h"
void uart_init()
{
	//baud rat
	UBRRL=51;

	//Mode asynchronous
	clear_bit(UCSRC, UMSEL);
	clear_bit(UCSRA, U2X);



	//FRAME

	//no parity
	clear_bit(UCSRC, UPM0);
	clear_bit(UCSRC, UPM1);

	//one stop bit
//	clear_bit(UCSRC, USBS);

	//8 bit data-transfer
	set_bit(UCSRC, UCSZ0);
	set_bit(UCSRC, UCSZ1);
	clear_bit(UCSRB, UCSZ2);

	//enable

	set_bit(UCSRB,TXEN);
	set_bit(UCSRB,RXEN);


}
void transmit(char x)
{
	while(!(read_bit(UCSRA,UDRE)));
		UDR=(char)x;
}

char recieve()
{
	while(!(read_bit(UCSRA,RXC)));

	 return	UDR;

}
void send_string(char* ptr)
{


    while(*ptr)
    {
    	transmit(*ptr++);
    }
    transmit('\r');

}


void recieve_string(char* buff)
{

	*buff = recieve();
      while(*buff !='\r')

      	{
    	  buff++;
    	  *buff = recieve();
      	}

      *buff='\0';

}

void send_number(uint32_t num)
{
	uint8_t *p=&num;
	transmit(p[0]);
	transmit(p[1]);
	transmit(p[2]);
	transmit(p[3]);


}
uint32_t recieve_number()
{
	uint32_t num;
	uint8_t *p=&num;

	p[0]=recieve();
	p[1]=recieve();
	p[2]=recieve();
	p[3]=recieve();

	return num;



}
