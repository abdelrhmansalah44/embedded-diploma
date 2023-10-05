/*
 * RCC_clock_configuration.h
 *
 *  Created on: Sep 30, 2023
 *      Author: abdalrahman salah
 */

#ifndef INC_RCC_CLOCK_CONFIGURATION_H_
#define INC_RCC_CLOCK_CONFIGURATION_H_





#include "stm32f013x6.h"
#include "stm32_f103c6_gpio_driver.h"

//-----------------------------
//User type definitions (structures)
//-----------------------------


//-----------------------------
//Macros Configuration References
//-----------------------------

#define HSI_CLK     (uint32_t)8000000

#define HSE_CLK     (uint32_t)16000000

/*
* ===============================================
* APIs Supported by "MCAL RCC DRIVER"
* ===============================================
*/

uint32_t MCAL_RCC_GetSysCLK(void);
uint32_t MCAL_RCC_GetHCLKFreq(void);
uint32_t MCAL_RCC_GetPCLK1Freq(void);
uint32_t MCAL_RCC_GetPCLK2Freq(void);




#endif /* INC_RCC_CLOCK_CONFIGURATION_H_ */
