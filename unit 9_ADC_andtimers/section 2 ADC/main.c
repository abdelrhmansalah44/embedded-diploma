/*
 * MAIN.C
 *
 *  Created on: Oct 25, 2023
 *      Author: abdalrahman salah
 */


#define  F_CPU 8000000


#include "avr/io.h"
#include "lcd.h"
#include "ADC.h"
#include "util/delay.h"
#include "stdio.h"
int main()
{

	uint32_t ADC_val , temperature,size,percent;


	//setting ADC port as input
	DDRA = 0x00;
	lcd_init();

	lcd_GOTO_XY(1,0);
	lcd_send_String("temp :");



	ADC_config_t adc_cnfg;

	adc_cnfg.ADC_vref_mode =ADC_vref_5v;
	adc_cnfg.ADC_prescalling = ADC_prescalling_64;
	adc_cnfg.ADC_IRQ =ADC_IRQ_ENABLE_NONE;
	adc_cnfg.p_callback =NULL;


	MCAL_ADC_Init(&adc_cnfg);




	while(1)
	{
	ADC_val =MCAL_ADC_Get_Result(ADC0);

	temperature =(uint32_t)((ADC_val*512)/resolution);
	lcd_GOTO_XY(1,7);
	lcd_display_number(temperature);

//
//	percent =(ADC_val*100.0)/resolution;
//	lcd_GOTO_XY(1,10);
//	lcd_display_number(percent);


	size = (16*temperature)/100;
			lcd_GOTO_XY(2, 0);
			for(int i=0 ; i<size ;i++){
				lcd_Send_Char(0xff);
			}
	}





};
