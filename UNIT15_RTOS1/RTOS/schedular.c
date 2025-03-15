/*
 * schedular.c
 *
 *  Created on: Jul 5, 2024
 *      Author: abdalrahman salah
 */


#include "schedular.h"
#include "MYRTOS_FIFO.h"



FIFO_Buf_t Ready_queue;
OS_task_ref* fifo_buffer[100];
static OS_task_ref OS_idle_task;
int idle_taskled;
int systimer_tick;

struct{
	unsigned int _s_msp;
	unsigned int _e_msp;
	unsigned int psp_locator;
	OS_task_ref* OS_size[100];
	OS_task_ref* next_task;
	OS_task_ref* current_task;
	unsigned char no_of_active_task;
	enum{

		OS_suspend,
		OS_running


	}OS_mode;



}OS_control;


typedef enum{

	svc_task_activate,
	svc_task_terminate,
	svc_task_waiting_time

}SVC_id;


void idle_task()
{
	while(1)
	{
		idle_taskled^=1;
		__asm("wfe");
	}
}


__attribute ((naked)) void PendSV_Handler()
{

	//switch context current task

	OS_get_psp_address(OS_control.current_task->current_psp);

	(OS_control.current_task->current_psp)--;
	__asm("mov %0,r4":"=r"(*(OS_control.current_task->current_psp)));
	(OS_control.current_task->current_psp)--;
	__asm("mov %0,r5":"=r"(*(OS_control.current_task->current_psp)));
	(OS_control.current_task->current_psp)--;
	__asm("mov %0,r6":"=r"(*(OS_control.current_task->current_psp)));
	(OS_control.current_task->current_psp)--;
	__asm("mov %0,r7":"=r"(*(OS_control.current_task->current_psp)));
	(OS_control.current_task->current_psp)--;
	__asm("mov %0,r8":"=r"(*(OS_control.current_task->current_psp)));
	(OS_control.current_task->current_psp)--;
	__asm("mov %0,r9":"=r"(*(OS_control.current_task->current_psp)));
	(OS_control.current_task->current_psp)--;
	__asm("mov %0,r10":"=r"(*(OS_control.current_task->current_psp)));
	(OS_control.current_task->current_psp)--;
	__asm("mov %0,r11":"=r"(*(OS_control.current_task->current_psp)));





	//switch restore next task

	if (OS_control.next_task != NULL)
	{
		OS_control.current_task = OS_control.next_task;
		OS_control.next_task = NULL;
	}

	__asm("mov r11,%0": :"r"(*(OS_control.current_task->current_psp)));
	(OS_control.current_task->current_psp)++;
	__asm("mov r10,%0": :"r"(*(OS_control.current_task->current_psp)));
	(OS_control.current_task->current_psp)++;
	__asm("mov r9,%0": :"r"(*(OS_control.current_task->current_psp)));
	(OS_control.current_task->current_psp)++;
	__asm("mov r8,%0": :"r"(*(OS_control.current_task->current_psp)));
	(OS_control.current_task->current_psp)++;
	__asm("mov r7,%0": :"r"(*(OS_control.current_task->current_psp)));
	(OS_control.current_task->current_psp)++;
	__asm("mov r6,%0": :"r"(*(OS_control.current_task->current_psp)));
	(OS_control.current_task->current_psp)++;
	__asm("mov r5,%0": :"r"(*(OS_control.current_task->current_psp)));
	(OS_control.current_task->current_psp)++;
	__asm("mov r4,%0": :"r"(*(OS_control.current_task->current_psp)));
	(OS_control.current_task->current_psp)++;


	OS_set_psp_address(OS_control.current_task->current_psp);
	__asm volatile("BX LR");



}




void decide_what_next()
{

	if((OS_control.current_task->OS_task_state !=suspend) && (Ready_queue.counter==0))
	{
		OS_control.current_task->OS_task_state= running;
		//add the current again(round robin)
		FIFO_enqueue(&Ready_queue, OS_control.current_task);
		OS_control.next_task = OS_control.current_task;
	}
	else
	{
		FIFO_dequeue(&Ready_queue, &OS_control.next_task);
		OS_control.next_task->OS_task_state=running;
		if((OS_control.current_task->priority == OS_control.next_task->priority)&&(OS_control.current_task->OS_task_state!=suspend))
		{
			FIFO_enqueue(&Ready_queue, OS_control.current_task);
			OS_control.current_task->OS_task_state = ready;
		}

	}

}

void bubbleSort()
{
	unsigned int i, j , n;
	OS_task_ref *temp ;
	n = OS_control.no_of_active_task ;
	for (i = 0; i < n - 1; i++)
	{
		// Last i elements are already in place
		for (j = 0; j < n - i - 1; j++)
		{
			if (OS_control.OS_size[j]->priority > OS_control.OS_size[j + 1]->priority)
			{
				temp = OS_control.OS_size[j] ;
				OS_control.OS_size[j] = OS_control.OS_size[j + 1 ] ;
				OS_control.OS_size[j + 1] = temp ;
			}
		}

  }
}
void MYRTOS_update_mySchedule()
{
	OS_task_ref* temp=NULL;
	OS_task_ref* ptref;
	OS_task_ref* pnexttref;
	int i=0;
	bubbleSort();

	//free ready queue
	while(FIFO_dequeue(&Ready_queue, &temp)!=FIFO_EMPTY);

	while(i<OS_control.no_of_active_task)
	{
		ptref =OS_control.OS_size[i];
		pnexttref=OS_control.OS_size[i+1];



		if(ptref->OS_task_state!=suspend)
		{
			//in case we reached the end of available os tasks
			if(pnexttref->OS_task_state == suspend)
			{
				FIFO_enqueue(&Ready_queue, ptref);
				ptref->OS_task_state = ready;
				break;
			}

			else if(ptref->priority < pnexttref->priority)
			{
				FIFO_enqueue(&Ready_queue, ptref);
				ptref->OS_task_state = ready;
				break;
			}

			else if(ptref->priority==pnexttref->priority)
			{
				FIFO_enqueue(&Ready_queue, ptref);
				ptref->OS_task_state = ready;
			}

			else if(ptref->priority>pnexttref->priority)
			{
				//won`t happen as we already sorted our os stack
				break;
			}

		}

	i++;

	}

}

void OS_svc_services(uint32_t *stackframepointer)
 {

	int SVC_id = *((unsigned char*) ((unsigned char*) (stackframepointer[6]))- 2);

	switch (SVC_id)

	{

	case svc_task_activate:
	case svc_task_terminate:
		MYRTOS_update_mySchedule();

		if (OS_control.OS_mode == OS_running) {
			//check that the task is not the idle task
			if (strcmp(OS_control.current_task->task_name, "idle_task") != 0) {
				decide_what_next();
				trigger_OS_PendSV();
			}

		}

		break;
	case svc_task_waiting_time:
		MYRTOS_update_mySchedule();
		break;

	}


}

void SysTick_Handler(void)
{
	systimer_tick^=1;

	decide_what_next();

	trigger_OS_PendSV();



}


void OS_svc_set_id(SVC_id id)
{
	switch (id) {

	case svc_task_activate:
		__asm("svc #0x00");
		break;
	case svc_task_terminate:
		__asm("svc #0x01");
		break;
	case svc_task_waiting_time:
		__asm("svc #0x02");
		break;

	}

}



void MYRTOS_update_taskwaiting_time() {
	for (int i = 0; i < OS_control.no_of_active_task; i++) {
		if (OS_control.OS_size[i]->OS_task_state == suspend)
		{

			if (OS_control.OS_size[i]->task_waiting.blocking == OS_blocking_enable)
			{
				(OS_control.OS_size[i]->task_waiting.ticks_count)--;

				if (OS_control.OS_size[i]->task_waiting.ticks_count == 1)
				{
					OS_control.OS_size[i]->task_waiting.blocking = OS_blocking_disable;
					OS_control.OS_size[i]->OS_task_state = waiting;

					OS_svc_set_id(svc_task_waiting_time);
				}

			}

		}

	}

}
void OS_create_mainstack()
{

	OS_control._s_msp = (uint32_t)&_estack;
	OS_control._e_msp =OS_control._s_msp -OS_main_stack_size;
	OS_control.psp_locator = (OS_control._e_msp-8);

//	if(OS_control._e_msp<(uint32_t)(&_Min_Heap_Size))
//	{
//		error= OS_heapsize_excedded;
//	}


}


void OS_create_task_stack(OS_task_ref* tref){

	//xpsr
	//pc
	//lr
	//r12
	//r4
	//r3
	//r2
	//r1
	//r0

	// r5,r6,r7,r8,r9,r10,r11
	tref->current_psp =  tref->_s_psp;


	tref->current_psp--;
	*(tref->current_psp)=0x01000000;

	tref->current_psp--;
	*(tref->current_psp)=(uint32_t)tref->p_task_function;//for pc


	tref->current_psp--;
	*(tref->current_psp) = 0xFFFFFFFD;


	for(int i=0;i<13;i++)
	{
	tref->current_psp--;

	*(tref->current_psp) = 0;
	}

}



MYRTOS_errorID MYRTOS_init(){

	MYRTOS_errorID error;
	error = no_error;

	//determine the suspend state
	OS_control.OS_mode = OS_suspend;
	//create the main stack
	OS_create_mainstack();

	//initialize OS_FIFO

	if(FIFO_init(&Ready_queue,fifo_buffer,100)!=FIFO_NO_ERROR)
	{
		error+= OS_FIFO_error;
	}

//	//create idle_task


	strcpy(	OS_idle_task.task_name,"idle_task");
	OS_idle_task.priority =255;
	OS_idle_task.task_stack_size =300;
	OS_idle_task.p_task_function =idle_task;

	error+=MYRTOS_CreateTask(&OS_idle_task);

	OS_idle_task.OS_task_state = suspend;

	return error;

}

MYRTOS_errorID MYRTOS_CreateTask(OS_task_ref* Tref){

	MYRTOS_errorID error;
	error = no_error;

	Tref->_s_psp =OS_control.psp_locator;
	Tref->_e_psp =Tref->_s_psp - Tref->task_stack_size;
	OS_control.psp_locator = Tref->_e_psp - 8;

	if(Tref->_e_psp<((uint32_t)(&_Min_Heap_Size)))
		{
			return task_excedded_heap;
		}


	//initialize task stack
	OS_create_task_stack(Tref);



	OS_control.OS_size[OS_control.no_of_active_task]=Tref;
	OS_control.no_of_active_task++;

	Tref->OS_task_state = suspend;

	return error;



}
void MYRTOS_activate_task(OS_task_ref *tref){
	tref->OS_task_state =waiting;
	OS_svc_set_id(svc_task_activate);

}
void MYRTOS_terminate_task(OS_task_ref *tref){

	tref->OS_task_state =suspend;
	OS_svc_set_id(svc_task_terminate);
}

void MYRTOS_start(){

	OS_control.OS_mode=OS_running;

	OS_control.current_task=&OS_idle_task;
	MYRTOS_activate_task(&OS_idle_task);



	start_tick();
	OS_set_psp_address((OS_control.current_task->current_psp));

	OS_sp_to_psp;
	OS_SWITCH_to_unprivileged;
	OS_idle_task.p_task_function();




}

void MYRTOS_taskwait(uint32_t no_of_ticks,OS_task_ref* wait_ref){

	wait_ref->task_waiting.blocking=OS_blocking_enable;
	wait_ref->task_waiting.ticks_count=no_of_ticks;
	wait_ref->OS_task_state =suspend;
	OS_svc_set_id(svc_task_terminate);

}

MYRTOS_errorID MYRTOS_Aquire_mutex(OS_mutex* mutex , OS_task_ref* tref){

	if(mutex->current_muttex_user==NULL)// mutex is not taken by any task
	{
		mutex->current_muttex_user = tref;
	}


	else{
		if(mutex->next_mutex_user==NULL) //not pending request by another task
			{
			mutex->next_mutex_user = tref;
			//move to suspend state until it is released
			tref->OS_task_state =suspend;

			OS_svc_services(svc_task_terminate);

			}

		else{
			return cant_aquire_mutex;
		}



	}

	return no_error;

}
void MYRTOS_release_mutex(OS_mutex* mutex , OS_task_ref* tref){

	if(mutex->current_muttex_user != NULL)
	{

		mutex->current_muttex_user = mutex->next_mutex_user;
		mutex->next_mutex_user = NULL;
		mutex->next_mutex_user->OS_task_state =waiting;
		OS_svc_services(svc_task_activate);

	}
}





