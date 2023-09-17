/*
 * utils.h
 *
 *  Created on: Sep 17, 2023
 *      Author: abdalrahman salah
 */

#ifndef UTILS_H_
#define UTILS_H_


#define set_bit(port,bit) port|=(1<<bit)
#define clear_bit(port,bit) port&=~(1<<bit)
#define read_bit(port,bit) ((port>>bit)&1)

#endif /* UTILS_H_ */
