#include <stdio.h>
#include <stdint.h>
/* register address */
#define RCC_BASE 			0x40021000
#define GPIOA_BASE 			0x40010800

#define RCC_APB2ENR 		*((volatile int*) (RCC_BASE + 0x18))
#define GPIOA_CRH 			*((volatile int*) (GPIOA_BASE + 0x04))
#define GPIOA_ODR 			*((volatile int*) (GPIOA_BASE + 0x0C))

/* bit fields*/
typedef union {
	volatile int  All_Fields;
	struct {
		volatile int reserved:13;
		volatile int p_13:1;
	}pin;
}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIOA_BASE + 0x0C);

#define RCC_IOPAEN	(1<<2)
#define GPIOA_Pin13	(1UL<<13)

int main(void)
{
	RCC_APB2ENR |= RCC_IOPAEN; // Enable clock rcc
	GPIOA_CRH &= 0xff0fffff; // get them 0 first before change it
	GPIOA_CRH |= 0x00200000; // now we can set 2 safely

	while(1)
	{
		int i;
//		GPIOA_ODR |= GPIOA_Pin13 ; // Set port a pin 13
		R_ODR->pin.p_13 = 1;
		for( i = 0 ;i < 5000 ; i++);

//		GPIOA_ODR &= ~(GPIOA_Pin13) ; // Clear port a pin 13
		R_ODR->pin.p_13 = 0;
		for(i = 0 ;i < 5000 ; i++);
	}

	return 0;
}
