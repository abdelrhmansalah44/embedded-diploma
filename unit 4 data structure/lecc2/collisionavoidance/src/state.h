/*
 * state.h
 *
 *  Created on: Jul 28, 2023
 *      Author: abdalrahman salah
 */

#ifndef STATE_H_
#define STATE_H_

#define STATE(_state_) void S_##_state_()
#define state(_state_) S_##_state_


void us_set_distance(int d);
void dc_motor_set(int s);
int random_testdata(int l,int r,int count);

#endif /* STATE_H_ */
