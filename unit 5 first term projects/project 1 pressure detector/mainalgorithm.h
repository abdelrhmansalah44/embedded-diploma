/*
 * mainalgorithm.h
 *
 *  Created on: Aug 15, 2023
 *      Author: abdalrahman salah
 */

#ifndef MAINALGORITHM_H_
#define MAINALGORITHM_H_

#include "state.h"
extern void (*main_pointer)();

enum{

    MA_pressure_detected
}MA_state;



STATE_DEFINE(MA_high_pressure_detected);

#endif /* MAINALGORITHM_H_ */
