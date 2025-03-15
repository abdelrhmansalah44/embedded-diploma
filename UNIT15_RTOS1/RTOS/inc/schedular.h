/*
 * schedular.h
 *
 *  Created on: Jul 5, 2024
 *      Author: abdalrahman salah
 */

#ifndef INC_SCHEDULAR_H_
#define INC_SCHEDULAR_H_

#include "cortexM_os_porting.h"
#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//#include "MYRTOS_FIFO.h"





typedef enum{

	no_error,
	OS_heapsize_excedded,
	OS_FIFO_error,
	task_excedded_heap,
	cant_aquire_mutex

}MYRTOS_errorID;



typedef struct{

	char task_name[50];
	unsigned int _s_psp;
	unsigned int _e_psp;
	unsigned int *current_psp;
	unsigned char priority;
	void (*p_task_function)(void);
	unsigned char Autostart;
	enum{
		suspend,
		waiting,
		ready,
		running

	}OS_task_state;

	unsigned int task_stack_size;

	struct{

		enum{

			OS_blocking_enable,
			OS_blocking_disable,

		}blocking;
		unsigned int ticks_count;

	}task_waiting;



}OS_task_ref;



typedef struct{

	unsigned char* payload;
	int payload_size;
	OS_task_ref* current_muttex_user;
	OS_task_ref* next_mutex_user;
	char mutex_name[30];


}OS_mutex;





#define element_type OS_task_ref*


//APIs
MYRTOS_errorID MYRTOS_init();
MYRTOS_errorID MYRTOS_CreateTask(OS_task_ref* Tref);

void MYRTOS_activate_task(OS_task_ref *tref);
void MYRTOS_terminate_task(OS_task_ref *tref);

void MYRTOS_start();

void MYRTOS_taskwait(uint32_t no_of_ticks,OS_task_ref* wait_ref);

MYRTOS_errorID MYRTOS_Aquire_mutex(OS_mutex* mutex , OS_task_ref* tref);
void MYRTOS_release_mutex(OS_mutex* mutex , OS_task_ref* tref);


















#endif /* INC_SCHEDULAR_H_ */
