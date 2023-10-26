/*
 * ADC.h
 *
 *  Created on: Oct 25, 2023
 *      Author: abdalrahman salah
 */

#ifndef INC_ADC_H_
#define INC_ADC_H_

#include "avr/io.h"
#include "avr/interrupt.h"
#include "utils.h"
//***********************************************************
//					ADC_TYPEDEF
//***********************************************************

#define Vref 		5000
#define resolution  1024


typedef struct{

	uint8_t ADC_vref_mode; //@ref ADC_vref_mode

	uint8_t ADC_prescalling; //@ref ADC_prescalling

	uint8_t ADC_IRQ;

	void (*p_callback)(void);



}ADC_config_t;

//***********************************************************
//					@references
//***********************************************************

//@ref ADC_vref_mode
#define ADC_vref_two_half   		(1<<REFS1)|(1<<REFS0)
#define ADC_vref_5v					(0<<REFS1)|(1<<REFS0)


//@ref ADC_channels  writing from bit0:4 in ADMUX register
typedef enum
{
	ADC0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7
}Channel_Select_t;

typedef enum
{
	ENABLE,
	DISABLE
}Polling_Mechanism_t;



//@ref ADC_prescalling
#define ADC_prescalling_2		(0<<ADPS2)|(0<<ADPS1)|(0<<ADPS0)
#define ADC_prescalling_4		(0<<ADPS2)|(1<<ADPS1)|(0<<ADPS0)
#define ADC_prescalling_8		(0<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)
#define ADC_prescalling_16		(1<<ADPS2)|(0<<ADPS1)|(0<<ADPS0)
#define ADC_prescalling_32		(1<<ADPS2)|(0<<ADPS1)|(1<<ADPS0)
#define ADC_prescalling_64		(1<<ADPS2)|(1<<ADPS1)|(0<<ADPS0)
#define ADC_prescalling_128		(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)

//@ref ADC_irq_callback
#define ADC_IRQ_ENABLE 			(1<<3)
#define ADC_IRQ_ENABLE_NONE 	(0<<3)




//***********************************************************
//					MCAL-ADC-APIS
//***********************************************************

void MCAL_ADC_Init(ADC_config_t *config);

void MCAL_ADC_Start_Conversion(void);
uint16_t MCAL_ADC_Get_Result(Channel_Select_t channel);



#endif /* INC_ADC_H_ */
