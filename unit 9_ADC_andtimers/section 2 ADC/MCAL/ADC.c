/*
 * ADC.c
 *
 *  Created on: Oct 25, 2023
 *      Author: abdalrahman salah
 */


#include "ADC.h"

ADC_config_t *global_cnfg;
void MCAL_ADC_Init(ADC_config_t *config)
{
	global_cnfg = config;

	ADMUX|=global_cnfg->ADC_vref_mode ;


	ADCSRA|=global_cnfg->ADC_prescalling;


	if(global_cnfg->ADC_IRQ == ADC_IRQ_ENABLE)
	{
		sei();
	}
	   set_bit(ADCSRA,ADATE);



	//enabling ADC
	set_bit(ADCSRA,ADEN);


}

void MCAL_ADC_Start_Conversion(void)
{
	if(read_bit(ADCSRA,ADEN))
	{
		set_bit(ADCSRA,ADSC);
	}

}
uint16_t MCAL_ADC_Get_Result(Channel_Select_t channel)
{

	ADMUX|=channel;
	MCAL_ADC_Start_Conversion();

	while(!(read_bit(ADCSRA,ADSC)));

	return ADC;



}

IRQ(ANA_COMP_vect)
{
	global_cnfg->p_callback();
}
