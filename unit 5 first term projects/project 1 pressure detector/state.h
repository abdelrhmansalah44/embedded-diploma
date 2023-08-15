/*
 * state.h
 *
 *  Created on: Aug 15, 2023
 *      Author: abdalrahman salah
 */

#ifndef STATE_H_
#define STATE_H_

#include<stdint.h>
#include<stdbool.h>
#include"driver.h"



// Automatic STATE Function generated
#define STATE_DEFINE(_StateFun_) void ST_##_StateFun_()
#define STATE(_StateFun_) ST_##_StateFun_

// states connection
void Set_Pressure_Val(unsigned int value);
void High_Pressure_Detected(unsigned int st_val);
void Start_Alarm();
void Stop_Alarm();


#endif /* STATE_H_ */
