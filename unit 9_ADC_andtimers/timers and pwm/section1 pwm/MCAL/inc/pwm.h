/*
 * pwm.h
 *
 *  Created on: Oct 26, 2023
 *      Author: abdalrahman salah
 */

#ifndef INC_PWM_H_
#define INC_PWM_H_

#include "avr/io.h"
#include "avr/interrupt.h"
#include "utils.h"
#include "stdlib.h"

typedef void(*ptr_callback)(void);
#define  NULL_PTR ((void*)0)

typedef unsigned char E_STATUS_t;
#define OK		(E_STATUS_t)(0)
#define NOK		(E_STATUS_t)(1)
//***********************************************
//				typedef
//***********************************************

typedef struct{
	uint16_t pwm_mode;  //---done
	uint16_t pwm_clk;    //---done
	uint16_t timer_compare;
	uint16_t timer_overflow;
	uint16_t pwm_output_mode; //---done

}pwm_config_t;


//***********************************************
//				reference config
//***********************************************


//@ref pwm_mode  Register – TCCR0
#define pwm_phasecorrect			(1<<WGM00)
#define pwm_fastmode				(1<<WGM00)|(1<WGM01)

//@ref timer_compare
#define timer_compare_enable  		1<<OCIE0
#define timer_compare_disable		0x00

//@ref timer_overflow
#define timer_overflow_enable  		1<<TOIE0
#define timer_overflow_disable		0x00

//@ref pwm_output_mode Register – TCCR0

#define pwm_phase_noninverting  			(0b10<<4)
#define pwm_phase_inverting  	  			(0b11<<4)
#define pwm_fastmode_noninverting  			(0b10<<4)
#define pwm_fastmode_inverting  	  		(0b11<<4)


//@ref pwm_clk_select Register – TCCR0
#define No_clck_src 				0x00
#define	NO_Prescaling  				1<<CS00
#define Prescaling_8  				1<<CS01
#define Prescaling_64   			(1<<CS00)|(1<<CS01)
#define Prescaling_256  			1<<CS02
#define Prescaling_1024     		(1<<CS00)|(1<<CS02)
#define EXT_CLK_FALLING				(1<<CS01)|(1<<CS02)
#define EXT_CLK_RISING				(1<<CS01)|(1<<CS02)|(1<<CS00)




//***********************************************
//				APIS
//***********************************************
void pwm_init(pwm_config_t *configuration);
void pwm_stop();

void pwm_dutycycle(unsigned char duty_cycle);



#endif /* INC_PWM_H_ */
