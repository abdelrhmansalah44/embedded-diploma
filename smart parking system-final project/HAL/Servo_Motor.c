/*
 * Sorce_Motor.c
 *
 *  Created on: Nov 12, 2021
 *      Author: Mostafa Mahmoud Elshiekh
 */

#include "Servo_Motor.h"





//B8 SERVO1
void Servo1_Entry_Gate_Init(void)
{
	/*SERVO MOTOR 1*/
	GPIO_CONFIGURATION PinCinfg;
	PinCinfg.GPIO_PIN_NUMBER=GPIO_PIN8;
	PinCinfg.GPIO_PIN_MODE = GPIO_PUSHPULL_OUTPUT;
	PinCinfg.GPIO_OUTPUT_SPEED =GPIO_OUTPUT_10MHz;
	MCAL_GPIO_INIT(GPIOB, &PinCinfg);
}

//Direction Up or Down
void Servo1_Entry_Gate(uint8_t Direction)
{
	if(Direction == UP)
	{
		//servo1 Enter gate up +90
		MCAL_GPIO_WRITE_PIN(GPIOB, GPIO_PIN8, 1);
		delay_us(500);
		MCAL_GPIO_WRITE_PIN(GPIOB, GPIO_PIN8, 0);
	}
	if(Direction==Down)
	{
		//servo1 Enter gate down -90
		MCAL_GPIO_WRITE_PIN(GPIOB, GPIO_PIN8, 1);
		delay_us(1488);
		MCAL_GPIO_WRITE_PIN(GPIOB, GPIO_PIN8, 0);
	}


}

//B9 SERVO2
void Servo2_Exit_Gate_Init(void)
{
	/*SERVO MOTOR 2*/

	GPIO_CONFIGURATION PinCinfg;
	PinCinfg.GPIO_PIN_NUMBER=GPIO_PIN9;
	PinCinfg.GPIO_PIN_MODE = GPIO_PUSHPULL_OUTPUT;
	PinCinfg.GPIO_OUTPUT_SPEED =GPIO_OUTPUT_10MHz;
	MCAL_GPIO_INIT(GPIOB, &PinCinfg);
}

//Direction Up or Down
void Servo2_Exit_Gate(uint8_t Direction)
{
	if(Direction == UP)
	{
		//servo2 Exit gate up +90
		MCAL_GPIO_WRITE_PIN(GPIOB, GPIO_PIN9, 1);
		delay_us(500);
		MCAL_GPIO_WRITE_PIN(GPIOB, GPIO_PIN9, 0);
	}

	if(Direction == Down)
	{
		//servo2 Exit gate down -90
		MCAL_GPIO_WRITE_PIN(GPIOB, GPIO_PIN9, 1);
		delay_us(1488);
		MCAL_GPIO_WRITE_PIN(GPIOB, GPIO_PIN9, 0);
	}

}
