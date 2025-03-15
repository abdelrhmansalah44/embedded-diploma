/*
 * cortexM_os_porting.h
 *
 *  Created on: Jul 5, 2024
 *      Author: abdalrahman salah
 */

#ifndef INC_CORTEXM_OS_PORTING_H_
#define INC_CORTEXM_OS_PORTING_H_


#include "schedular.h"

//implement conversion from sp to psp
#define OS_sp_to_psp   __asm volatile("mrs r0, CONTROL \n\t mov r1,#0x02 \n\t orr r0,r0,r1 \n\t msr CONTROL,r0")
//implement conversion from sp to msp
#define OS_sp_to_msp  __asm volatile("mrs r0, CONTROL \n\t mov r1,#0x05 \n\t and r0,r0,r1 \n\t msr CONTROL,r0")
//set psp address
#define OS_set_psp_address(add)   __asm volatile("mov r0,%0 \n\t msr PSP,r0" : : "r" (add))
//get psp address
#define OS_get_psp_address(add)  __asm volatile("mrs r0,PSP \n\t mov %0,r0"   : "=r" (add))


#define OS_SWITCH_to_privileged   		__asm(" mrs r3, CONTROL  \n\t" \
										" lsr r3,r3,#0x1   \n\t"       \
										" lsl r3,r3,#0x1   \n\t"	   \
										" msr CONTROL, r3");

//set Bit 0 CONTROL register
#define OS_SWITCH_to_unprivileged		__asm(" mrs r3, CONTROL  \n\t" \
											  " orr r3,r3,#0x1   \n\t" \
											  " msr CONTROL, r3 ");


extern int _estack;
extern int _Min_Heap_Size;
#define	   OS_main_stack_size 	3027





void HAL_init();
void trigger_OS_PendSV();
void start_tick();
#endif /* INC_CORTEXM_OS_PORTING_H_ */
