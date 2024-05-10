/*
 * I2C_EEPROM_slave.c
 *
 *  Created on: Oct 20, 2023
 *      Author: abdalrahman salah
 */


#include "I2C_EEPROM_slave.h"

void EEPROM_init()
{
	I2Cx_config i2c_cnfg;

	i2c_cnfg.I2C_clock_speed = I2C_CLCK_SM_100K;
	i2c_cnfg.I2C_clock_stretching =I2C_stretch;
	i2c_cnfg.I2C_generalcall =I2C_GENERALCALL_EN;
	i2c_cnfg.I2C_mode = I2C_MODE_I2C;
	i2c_cnfg.P_IRQ_Callback = NULL;
	i2c_cnfg.I2C_Achnowledge =I2C_ACK;

	MCAL_I2C_GPIO_Set_Pins(I2C1);
	MCAL_I2C_Init(I2C1, &i2c_cnfg);

}
uint16_t EEPROM_write(uint16_t address,uint16_t*eeprom_buffer , uint16_t datalength){

	int i=0;

	uint8_t buffer[256];

	//setting first two bytes for slave address
	buffer[0] =(uint8_t) address>>8;
	buffer[1] =(uint8_t)address;

	//sending data
	for(i=2;i<(datalength+2);i++){

		buffer[i] =eeprom_buffer[i-2];
	}

	MCAL_master_TX(I2C1,  EEPROM_slave_addres, buffer, datalength+2, START, WITH_STOP);


	return 0;


}
uint16_t EEPROM_read(uint16_t address,uint16_t*eeprom_buffer , uint16_t datalength){



	uint8_t buffer[256];

	//setting first two bytes for slave address
	buffer[0] =(uint8_t) address>>8;
	buffer[1] =(uint8_t)address;

	//send slave address
    MCAL_master_TX(I2C1, EEPROM_slave_addres, &buffer, 2, START, WITHOUT_STOP);

    //recieve data

    MCAL_master_RX(I2C1, EEPROM_slave_addres, eeprom_buffer, datalength, REPEATED_START, WITH_STOP);

    return 0;
}


