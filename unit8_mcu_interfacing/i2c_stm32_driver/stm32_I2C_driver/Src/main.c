/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "stm32_f103c6_I2C_driver.h"
#include "stm32_f103c6_gpio_driver.h"
#include "I2C_EEPROM_slave.h"

void clock_init();

int main(void)
{
    clock_init();

    //test case 1

    uint8_t ch1[]={0x1,0x2,0x3,0x4,0x5,0x6,0x7};
    uint8_t ch2[7] = {0};

    EEPROM_init();
    EEPROM_write(0xAF, ch1, 7);
    EEPROM_read(0xAF, ch2, 7);


    //test case 2
    ch1[0] =0xA;
    ch1[1] =0xB;
    ch1[2] =0xC;
    ch1[3] =0xD;


    EEPROM_write(0xFFFF, ch1, 4);
     EEPROM_read(0xFFFF, ch2, 4);



}

void clock_init()
{
	RCC_GPIOA_CLOCK_ENABLE;
	RCC_GPIOB_CLOCK_ENABLE;
	RCC_AFIO_ENABLE;

}
