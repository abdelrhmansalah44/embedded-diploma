/*
 * main.c
 *
 *  Created on: Oct 5, 2023
 *      Author: abdalrahman salah
 */

#include "avr/io.h"
#include "utils.h"
#include "util/delay.h"
#include "stdint.h"


#define decode_mode  0xX9

#define MOSI 5
#define SS   4
#define CLK  7

void spi_master_init();
void execute(unsigned char cmd, unsigned char data);

int main()
{
	unsigned char counter = 0;
		unsigned char index_display;
		spi_master_init();
		execute(0x09, 0xFF);
		execute(0x0A, 0xFF);
		execute(0x0B, 0xF7);
		execute(0x0C, 0x01);
	    while (1)
	    {
			for (index_display = 1; index_display < 9; index_display++)
				execute(index_display, counter++);
			_delay_ms(1000);
	    }


}
void spi_master_init()
{
	// setting pins as output

	set_bit(DDRB,MOSI);
	set_bit(DDRB,SS);
	set_bit(DDRB,CLK);


	//MSTR bit
	set_bit(SPCR,MSTR);


	//enabling spi
	set_bit(SPCR,SPE);

	// fck/16
	set_bit(SPCR,SPR0);

}
void execute(unsigned char cmd, unsigned char data)
{
	PORTB &= ~(1 << SS);
	SPDR = cmd;
	while (!(SPSR & (1 << SPIF)));
	SPDR = data;
	while (!(SPSR & (1 << SPIF)));
	PORTB |= (1 << SS);
}
