/*
 * stm32_f103c6_I2C_driver.h
 *
 *  Created on: Oct 17, 2023
 *      Author: abdalrahman salah
 */

#ifndef INC_STM32_F103C6_I2C_DRIVER_H_
#define INC_STM32_F103C6_I2C_DRIVER_H_

#include "stm32f013x6.h"
#include "stm32_f103c6_gpio_driver.h"
#include "RCC_clock_configuration.h"
#include "stdio.h"
#include "stdint.h"

struct S_I2C_SLAVE_DEVICE_ADDRESS{

	uint16_t	Enable_Dual_Add;
	uint16_t	Primary_Slave_Add;
	uint16_t	Secondary_Slave_Add;
	uint32_t	Addressing_Slave_Mode; 	//@ref I2C_ADD_SLAVE_MODE

};

typedef enum{
	I2C_EV_STOP,
	I2C_ERROR_AF,
	I2C_EV_ADDR_MATCHED,
	I2C_EV_DATA_REQ,    //the app layer should send the data (I2C_SlaveSendData) in this state
	I2C_EV_DATA_REC     //the app layer should read the data (I2C_SlaveReceiveData) in this state
}SLAVE_STATE;



typedef struct {

	uint32_t I2C_clock_speed;  //@ref I2C_clock_config


	uint32_t I2C_Achnowledge; 	//@ref I2C_Achnowledge_config


	uint32_t I2C_clock_stretching;		//@ref I2C_clock_stretching_config

	uint32_t I2C_generalcall;		//@ref I2C_generalcall_config

	struct S_I2C_SLAVE_DEVICE_ADDRESS I2C_slave_address;  //@ref I2C_slave_address_config

	uint32_t  I2C_mode;		//@ref I2C_mode_config


	void(*P_IRQ_Callback)(SLAVE_STATE state);
}I2Cx_config;




//************************************************
//				reference macros
//************************************************

//@ref I2C_clock_config

//this driver supports standard mode I2C only
#define	I2C_CLCK_SM_50K		    50000UL
#define	I2C_CLCK_SM_100K	    100000UL
#define	I2C_CLCK_FM_200K	    200000UL
#define	I2C_CLCK_FM_400K	    400000UL


//@ref I2C_Achnowledge_config
#define I2C_ACK				I2C_CR1_ACK
#define I2C_NACK			0x00000000

//@ref I2C_clock_stretching_config
#define I2C_NOstretch			I2C_CR1_NOSTRETCH
#define I2C_stretch				0x00000000

//@ref I2C_generalcall_config
#define I2C_GENERALCALL_EN			I2C_CR1_ENGC
#define I2C_GENERALCALL_DIS 		0x00000000

//@ref I2C_slave_address_config
#define I2C_slave_address_7bit		0x00000000
#define I2C_slave_address_10bit		(1<<15)

//@ref I2C_mode_config
#define 	I2C_MODE_I2C		0x00000000
#define 	I2C_MODE_SMBUS     I2C_CR1_SMBUS

typedef enum{
	Disable = 0,
	Enable = 1
}FunctionalState;


typedef enum
{
	WITH_STOP,
	WITHOUT_STOP
}Stop_Condition;


typedef enum{

	I2C_busy, //checking if the bus is busy or not
	EV5,  // SB=1,cleared by reading SR1 register followed by writing DR register with Address
	EV6 , // ADDR=1, cleared by reading SR1 register followed by reading SR2.
	EV8_1, //TxE=1, shift register not empty, d. ata register empty, cleared by writing DR register
	EV8, //EV8: TxE=1, shift register not empty, d. ata register empty, cleared by writing DR register
	EV7,// RXNE=1,cleared by reading DR register
    master_byte_transmitter = (uint32_t)(0x00070080),    // TRA, BUSY, MSL and TXE flags


}I2C_status;

typedef enum
{
	START,
	REPEATED_START
}Repeated_Start;


typedef enum{
	RESET,
	SET
}Flag_Status;


typedef enum{
	Transmit = 0,
	Receive = 1
}I2C_Direction;


//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-
// APIS Supported by "MCAL I2C DRIVER"
//-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-

void MCAL_I2C_Init(I2Cx_typedef *I2Cx ,I2Cx_config *I2C_cfg );
void MCAL_I2C_DeInit(I2Cx_typedef *I2Cx );
void MCAL_I2C_GPIO_Set_Pins(I2Cx_typedef *I2Cx );


void MCAL_master_TX(I2Cx_typedef *I2Cx ,  uint16_t dataaddress , uint16_t *TX_buffer , uint16_t datalengh ,Repeated_Start start,Stop_Condition stop );
void MCAL_master_RX(I2Cx_typedef *I2Cx , uint16_t dataaddress , uint16_t *RX_buffer , uint16_t datalengh ,Repeated_Start start ,Stop_Condition stop);



Flag_Status I2C_flag_status(I2Cx_typedef *I2Cx,I2C_status status );

void I2C_generate_start(I2Cx_typedef *I2Cx,FunctionalState fun_state,Repeated_Start start);
void I2C_generate_stop(I2Cx_typedef *I2Cx,FunctionalState fun_state);


void I2C_send_address(I2Cx_typedef *I2Cx ,uint16_t address ,I2C_Direction direction);


void MCAL_I2C_SLAVE_TX(I2Cx_typedef *I2Cx ,uint8_t DATA);
uint8_t MCAL_I2C_SLAVE_RX(I2Cx_typedef *I2Cx );

#endif /* INC_STM32_F103C6_I2C_DRIVER_H_ */
