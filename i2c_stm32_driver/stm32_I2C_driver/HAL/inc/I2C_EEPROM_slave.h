/*
 * I2C_EEPROM_slave.h
 *
 *  Created on: Oct 20, 2023
 *      Author: abdalrahman salah
 */

#ifndef INC_I2C_EEPROM_SLAVE_H_
#define INC_I2C_EEPROM_SLAVE_H_

#include "stm32_f103c6_I2C_driver.h"

#define EEPROM_slave_addres 0x2A


void EEPROM_init();
uint16_t EEPROM_write(uint16_t address,uint16_t*buffer , uint16_t datalength);
uint16_t EEPROM_read(uint16_t address,uint16_t*buffer , uint16_t datalength);

#endif /* INC_I2C_EEPROM_SLAVE_H_ */
