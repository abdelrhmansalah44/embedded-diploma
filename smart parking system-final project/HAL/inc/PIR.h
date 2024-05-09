/*
 * PIR.h
 *
 *  Created on: Nov 30, 2023
 *      Author: abdalrahman salah
 */

#ifndef INC_PIR_H_
#define INC_PIR_H_

#include "stm32_f103c6_gpio_driver.h"
#include "Timer.h"



typedef enum{

	PIR_false,
	PIR_true
}PIR_status;


#define PIR_gpiox  			GPIOA

#define PIR_entrypin 		GPIO_PIN6
#define PIR_exitpin 		GPIO_PIN1





void PIR_init();
PIR_status PIR_Entergate();
PIR_status PIR_Exitgate();

#endif /* INC_PIR_H_ */
