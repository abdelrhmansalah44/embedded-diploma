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

#include "../HAL.c/inc/lcd.h"
#include "../HAL.c/inc/keypad.h"
#include "stm32_f103c6_EXTI_driver.h"
#include "stm32_f103c6_gpio_driver.h"
#include "stdio.h"

int flag=1;
void my_wait(int x){
	uint16_t i, j;
	for(i = 0; i < x; i++){
		for(j = 0; j < 255; j++);
	}
}

void EXTI_callback9()
{
	flag = 1;
	LCD_WRITE_STRING("IRQ EXTI9 IS DONE");
	my_wait(100);
}

void clock_init()
{

	RCC_AFIO_ENABLE;
	RCC_GPIOA_CLOCK_ENABLE;
	RCC_GPIOB_CLOCK_ENABLE;
}

void EXTI_init()
{
	EXTI_PINCONFIG pinconfig;
	pinconfig.EXTI_PIN=EXTI9PB9;
	pinconfig.trigger_case = trigger_rise;
	pinconfig.IRQ_enable =EXTI_PIN_ENABLE;
	pinconfig.P_IRQ_CallBack= EXTI_callback9;
	MCAL_EXTI_GPIO_INIT(&pinconfig);

}

int main(void)
{

	clock_init();
    LCD_INIT();

//    LCD_GOTO_XY(1,0);
    LCD_WRITE_STRING("welcome");
    my_wait(1000);
    EXTI_init();


    while(1)
    {
    	if(flag)
    	{
    		LCD_clear_screen();
    		flag=0;
    	}


    }

}




















