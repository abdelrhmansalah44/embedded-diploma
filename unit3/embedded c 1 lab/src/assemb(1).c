/*
 ============================================================================
 Name        : assemb(1).c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define RCC_BASE 0X40021000
#define GPIOA_BASE 0X40010800

#define APB2ENR  *(volatile unsigned int *)(RCC_BASE+0x18)
#define GPIOA_CRH  *(volatile unsigned int *)(GPIOA_BASE+0x04)
#define GPIOA_ODR *(volatile unsigned int *)(GPIOA_BASE+0x0C)

typedef union{
	volatile unsigned int allfields;
	struct{

		volatile unsigned int reserved:13;
		volatile unsigned int p_13:1

	}pin;

}RODRT;

volatile RODRT *rodr = ( volatile RODRT *)(GPIOA_BASE+0x0C);

int main(void) {

	APB2ENR |=(1<<2);
	GPIOA_CRH &= 0xFF0FFFF;
	GPIOA_ODR |= 0X0020000;

  while(1)
  {
	rodr->pin.p_13=1;
	for(int i=0;i<5000;i++);
	rodr->pin.p_13=0;
	for(int i=0;i<5000;i++);


}
	return EXIT_SUCCESS;
}
