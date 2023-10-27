/*
 * timers.h
 *
 *  Created on: Oct 23, 2023
 *      Author: abdalrahman salah
 */

#ifndef INC_TIMERS_H_
#define INC_TIMERS_H_

#include "avr/io.h"
#include "utils.h"
#include "avr/interrupt.h"

//***********************************************
//				GLOBAL VARIABLES
//***********************************************

typedef void(*ptr_callback)(void);
#define  NULL_PTR ((void*)0)



//***********************************************
//				TYPDEF-ENUMS
//***********************************************
typedef unsigned char E_STATUS_t;
#define OK		(E_STATUS_t)(0)
#define NOK		(E_STATUS_t)(1)


typedef enum {

	Normal,
	CTC=0x08


}timers_mode_t;

typedef enum{
	No_clck_src,
	NO_Prescaling = 0x1,
	Prescaling_8 = 0x2,
	Prescaling_64 = 0x3,
	Prescaling_256 = 0x4,
	Prescaling_1024 = 0x5,
	EXT_CLK_FALLING,
	EXT_CLK_RISING


}timer_clockset_t;

typedef enum{

	OCEI_ENABLE=0x02,
	OCEI_DISABLE=0x00

}OCIE_t;

typedef enum{

	TOEI_ENABLE=0x01,
	TOEI_DISABLE=0x00

}TOIE_t;


typedef struct{
	timers_mode_t timer_mode;
	timer_clockset_t timer_clk;
	OCIE_t timer_compare;
	TOIE_t timer_overflow;
}timer_config_t;




//***********************************************
//				APIS
//***********************************************
E_STATUS_t timer_init(timer_config_t *configuration);
E_STATUS_t timer_stop();

E_STATUS_t timer_getcompare(unsigned char *tickers);
E_STATUS_t timer_setcompare(unsigned char tickers);

E_STATUS_t timer_getcounter(unsigned char *tickers);
E_STATUS_t timer_setcounter(unsigned char tickers);

E_STATUS_t timer_getoverflow(unsigned char *tickers);
E_STATUS_t timer_setoverflow(unsigned char tickers);

void timer_overflow_callback(ptr_callback callback);
void timer_compare_callback(ptr_callback callback);



#endif /* INC_TIMERS_H_ */
