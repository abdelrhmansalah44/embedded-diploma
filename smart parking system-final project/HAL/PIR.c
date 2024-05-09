/*
 * PIR.c
 *
 *  Created on: Nov 30, 2023
 *      Author: abdalrahman salah
 */

#include "PIR.h"

void PIR_init()
{
	GPIO_CONFIGURATION pincnfg;


	//entry gate pin configuration
	pincnfg.GPIO_PIN_NUMBER =PIR_entrypin;
	pincnfg.GPIO_OUTPUT_SPEED =GPIO_OUTPUT_10MHz;
	pincnfg.GPIO_PIN_MODE =GPIO_PUSHPULL_OUTPUT;
	MCAL_GPIO_INIT(PIR_gpiox, &pincnfg);

	//exit gate pin configuration
	pincnfg.GPIO_PIN_NUMBER =PIR_exitpin;
	pincnfg.GPIO_OUTPUT_SPEED =GPIO_OUTPUT_10MHz;
	pincnfg.GPIO_PIN_MODE =GPIO_PUSHPULL_OUTPUT;
	MCAL_GPIO_INIT(PIR_gpiox, &pincnfg);


}
PIR_status PIR_Entergate()
{
	uint8_t pin_status=MCAL_GPIO_READ_PIN(PIR_gpiox, PIR_entrypin);
	PIR_status status;
	if(pin_status == GPIO_PIN_true)
	{

		status= PIR_true;
	}

	else
	{
		status= PIR_false;

	}



	return status;
}
PIR_status PIR_Exitgate()
{
		uint8_t pin_status=MCAL_GPIO_READ_PIN(PIR_gpiox, PIR_exitpin);
		PIR_status status;
		if(pin_status == GPIO_PIN_true)
		{

			status= PIR_true;
		}

		else
		{
			status= PIR_false;

		}


		return status;




}
