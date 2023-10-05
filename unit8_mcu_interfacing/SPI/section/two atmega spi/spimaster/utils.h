/*
 * utils.h
 *
 *  Created on: Sep 17, 2023
 *      Author: abdalrahman salah
 */

#ifndef UTILS_H_
#define UTILS_H_

//to set or clear any port or registers
#define set_bit(reg,bit) reg|=(1<<bit)
#define clear_bit(reg,bit) reg&=~(1<<bit)
#define read_bit(reg,bit) ((reg>>bit)&1)

#endif /* UTILS_H_ */
