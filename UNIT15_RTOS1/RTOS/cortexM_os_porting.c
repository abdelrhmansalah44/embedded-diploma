/*
 * cortexM_os_porting.c
 *
 *  Created on: Jul 5, 2024
 *      Author: abdalrahman salah
 */

#include "cortexM_os_porting.h"
#include "core_cm3 (1).h"


void HardFault_Handler() {
	while (1) {

	}
}
void MemManage_Handler() {
	while (1) {

	}
}
void BusFault_Handler() {
	while (1) {

	}
}
void UsageFault_Handler() {
	while (1) {

	}
}


__attribute ((naked)) void SVC_Handler()
{
	//	SWITCH_CPU_AccessLevel (privileged);
	__asm ("tst lr, #4 \n\t"
			"ITE EQ \n\t" //To execute Thumb instructions conditionally, you can either use an IT instruction, or a conditional branch instruction.
			"mrseq r0,MSP \n\t "
			"mrsne r0,PSP \n\t"
			"B OS_svc_services");
}


void HAL_init()
{

	 __NVIC_SetPriority(PendSV_IRQn, 15);


}
void trigger_OS_PendSV()
{
	SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk ;

}


void start_tick(){


	SysTick_Config(8000);
	//imilli second

}

