/*
 * main.c
 *
 *  Created on: Sep 13, 2023
 *      Author: abdalrahman salah
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>



#define IO_BASE 0x20
#define PORTD *(volatile unsigned int *)(IO_BASE +0X12)
#define DDRD  *(volatile unsigned int *)(IO_BASE +0X11)

#define INT0 *(volatile unsigned int *)(IO_BASE +0X35)
#define INT1 *(volatile unsigned int *)(IO_BASE +0X35)
#define INT2 *(volatile unsigned int *)(IO_BASE +0X34)
#define GICR *(volatile unsigned int *)(IO_BASE +0X3B)
#define SREG *(volatile unsigned int *)(IO_BASE +0X3F)


#define set_bit(address,bit) address|=(1<<bit)
#define reset_bit(address,bit) address&=~(1<<bit)


int main()
{

	//allowing bit 5,6,7 as an output in portD
	set_bit(DDRD,5);
	set_bit(DDRD,6);
	set_bit(DDRD,7);



	//set bit 7 in SREG register to enable global interrupt
	set_bit(SREG,7);

	//set bit 5,6,7 in GICR register
	set_bit(GICR,5);
	set_bit(GICR,6);
	set_bit(GICR,7);

	//INT0 interrupt occur at any logical change
	set_bit(INT0,0);
	reset_bit(INT0,1);

	//INT1 interrupt occur at rising edge
	set_bit(INT1,3);
	set_bit(INT1,2);

	//INT2 interrupt occur at falling edge
	reset_bit(INT2,6);




	while(1)
	{
		reset_bit(PORTD,5);
		reset_bit(PORTD,6);
		reset_bit(PORTD,7);
	}

}

ISR(INT0_vect)
{
	set_bit(PORTD,5);
	_delay_ms(100);
}

ISR(INT1_vect)
{
	set_bit(PORTD,6);
	_delay_ms(100);
}

ISR(INT2_vect)
{
	set_bit(PORTD,7);
	_delay_ms(100);

}
