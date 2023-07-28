/*
 * ca.h
 *
 *  Created on: Jul 28, 2023
 *      Author: abdalrahman salah
 */

#ifndef CA_H_
#define CA_H_
#include "state.h"

#include <stdio.h>
#include <stdlib.h>
#include "state.h"

enum{
	cv_waiting,
	cv_driving

}cv_state;

extern void (*PTR_STATE)();



STATE(CV_waiting);
STATE(CV_driving);


#endif /* CA_H_ */
