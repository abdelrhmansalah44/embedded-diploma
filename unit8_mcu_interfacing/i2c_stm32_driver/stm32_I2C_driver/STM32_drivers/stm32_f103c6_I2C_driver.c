/*
 * stm32_f103c6_I2C_driver.c
 *
 *  Created on: Oct 17, 2023
 *      Author: abdalrahman salah
 */


#include "stm32_f103c6_I2C_driver.h"



I2Cx_config GLOBAL_I2C_CNFG[2] = {NULL,NULL};

#define I2C1_index   0
#define I2C2_index   1


void MCAL_I2C_Init(I2Cx_typedef *I2Cx ,I2Cx_config *I2C_cfg )
{

	uint16_t tempreg=0 , freqrange=0 , result=0;
	uint32_t pclk1 =0;
//	The following is the required sequence in master mode.
//	• Program the peripheral input clock in I2C_CR2 Register in order to generate correct
//	timings
//	• Configure the clock control registers
//	• Configure the rise time register
//	• Program the I2C_CR1 register to enable the peripheral
//	• Set the START bit in the I2C_CR1 register to generate a Start condition
//	The peripheral input clock frequency must be at least:
//	• 2 MHz in Sm mode
//	• 4 MHz in Fm mode

	//**********checking I2C used and enabling clock***************

	if(I2Cx ==I2C1 )
	{
		GLOBAL_I2C_CNFG[I2C1_index] = *I2C_cfg;
		RCC_I2C1_CLK_EN;

	}
	else{
		GLOBAL_I2C_CNFG[I2C2_index] = *I2C_cfg;

		RCC_I2C2_CLK_EN;

	}

	if(I2C_cfg->I2C_mode == I2C_MODE_I2C)
	{
		//**********clock configuration***************
			tempreg = I2Cx->CR2;
			//clear freq[0:5]
			tempreg &=~(I2C_CR2_FREQ_Msk);

			pclk1 = MCAL_RCC_GetPCLK1Freq();

			freqrange = (uint16_t)(pclk1/1000000);
			tempreg|=freqrange;
			I2Cx->CR2 = tempreg;


			//disable peripheral
			I2Cx->CR1 &=~(I2C_CR1_PE);

			tempreg = 0; // we are going to use another register now

			if(I2C_cfg->I2C_clock_speed == I2C_CLCK_SM_50K  ||  I2C_cfg->I2C_clock_speed == I2C_CLCK_SM_100K)
				{
			result = (uint16_t)( pclk1 / (I2C_cfg->I2C_clock_speed <<1));
			tempreg |=result;
			I2Cx->CCR =tempreg;


			//**** TRISE config****

			I2Cx->TRISE = freqrange+1; //modi (|)

				}

		else{

			//fast mode not supported
		}


		//***********writing on CR1 register

				tempreg = I2Cx->CR1;
				tempreg |= I2C_cfg->I2C_Achnowledge | I2C_cfg->I2C_clock_stretching | I2C_cfg->I2C_generalcall |I2C_cfg->I2C_mode;
				I2Cx->CR1 = tempreg;


		//======================configure OAR1 and OAR2 register=================================
				tempreg =0;

				if(I2C_cfg->I2C_slave_address.Enable_Dual_Add == 1) // means writing two slave addresses
				{
					tempreg =I2C_OAR2_ENDUAL;
					tempreg |=I2C_cfg->I2C_slave_address.Secondary_Slave_Add << I2C_OAR2_ADD2_Pos;
					I2Cx->OAR2 =tempreg;

				}

				 	 	tempreg = 0;
						tempreg |= I2C_cfg->I2C_slave_address.Primary_Slave_Add << 1;
						tempreg |= I2C_cfg->I2C_slave_address.Addressing_Slave_Mode;
						I2Cx->OAR1 = tempreg;


	}
	else{

		//SMBUS not supported in this driver
	}

//Interrupt enable for slave

	if(I2C_cfg->P_IRQ_Callback !=NULL)
	{
		I2Cx->CR2 |= I2C_CR2_ITBUFEN;
		I2Cx->CR2 |= I2C_CR2_ITERREN;
		I2Cx->CR2 |= I2C_CR2_ITEVTEN;

		if(I2Cx == I2C1)
		{
			NVIC_IRQ31_I2C1_EV_Enable();
			NVIC_IRQ32_I2C1_ER_Enable();

		}

		else
		{
			NVIC_IRQ33_I2C2_EV_Enable();
			NVIC_IRQ34_I2C2_ER_Enable();

		}

			I2Cx->SR1 =0;
			I2Cx->SR2 =0;

	}

// enabling the I2C peripheral
	I2Cx->CR1 |=(I2C_CR1_PE);

}
void MCAL_I2C_DeInit(I2Cx_typedef *I2Cx )
{

if(I2Cx ==I2C1)
{
		RCC_I2C1_CLK_DIS;
		NVIC_IRQ31_I2C1_EV_DISABLE();
		NVIC_IRQ32_I2C1_ER_DISABLE();
}

else {
		RCC_I2C2_CLK_DIS;
		NVIC_IRQ33_I2C2_EV_DISABLE();
		NVIC_IRQ34_I2C2_ER_DISABLE();

}



}
void MCAL_I2C_GPIO_Set_Pins(I2Cx_typedef *I2Cx )
{
	GPIO_CONFIGURATION gpio_cnfg;
	if(I2Cx == I2C1)
	{
		//scl PB6
		//sda PB7
		gpio_cnfg.GPIO_PIN_MODE = GPIO_AFIO_OP_OUTPUT;
		gpio_cnfg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_10MHz;
		gpio_cnfg.GPIO_PIN_NUMBER = GPIO_PIN6;
		MCAL_GPIO_INIT(GPIOB, &gpio_cnfg);

		gpio_cnfg.GPIO_PIN_MODE = GPIO_AFIO_OP_OUTPUT;
		gpio_cnfg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_10MHz;
		gpio_cnfg.GPIO_PIN_NUMBER = GPIO_PIN7;
		MCAL_GPIO_INIT(GPIOB, &gpio_cnfg);

	}

	else{
		//scl PB6
		//sda PB7
		gpio_cnfg.GPIO_PIN_MODE = GPIO_AFIO_OP_OUTPUT;
		gpio_cnfg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_10MHz;
		gpio_cnfg.GPIO_PIN_NUMBER = GPIO_PIN10;
		MCAL_GPIO_INIT(GPIOB, &gpio_cnfg);

		gpio_cnfg.GPIO_PIN_MODE = GPIO_AFIO_OP_OUTPUT;
		gpio_cnfg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_10MHz;
		gpio_cnfg.GPIO_PIN_NUMBER = GPIO_PIN11;
		MCAL_GPIO_INIT(GPIOB, &gpio_cnfg);




	}
}

void MCAL_master_TX(I2Cx_typedef *I2Cx ,  uint16_t dataaddress , uint16_t *TX_buffer , uint16_t datalengh ,Repeated_Start start,Stop_Condition stop )
{

	int i=0;
	//generating start bit
	I2C_generate_start(I2Cx, Enable, START);

	//checking if start bit is generated (EV5)
	while(!(I2C_flag_status(I2Cx, EV5)));

	//send slave address
	I2C_send_address(I2Cx, dataaddress, Transmit);//------>

	//checking for EV6
	while(!(I2C_flag_status(I2Cx, EV6)));

	while(!(I2C_flag_status(I2Cx, master_byte_transmitter)));



	//checking for EV8_1
	//while(!(I2C_flag_status(I2Cx, EV8_1))); //modi


	//sending data

	for(i=0;i<datalengh;i++)
	{
		I2Cx->DR = TX_buffer[i];

		while(!(I2C_flag_status(I2Cx, EV8)));

	}



	//generating stop bit
	if(stop == WITH_STOP)
	{
	I2C_generate_stop(I2Cx, Enable);
	}



}

void MCAL_master_RX(I2Cx_typedef *I2Cx ,  uint16_t dataaddress , uint16_t *RX_buffer , uint16_t datalengh ,Repeated_Start start ,Stop_Condition stop)
{
	int i = 0;

	uint8_t index = (I2Cx ==I2C1) ? I2C1_index:I2C2_index;

	//generating start bit
	I2C_generate_start(I2Cx, Enable, START);

	//checking if start bit is generated (EV5)
	while (!(I2C_flag_status(I2Cx, EV5)));

	//send slave address

	I2C_send_address(I2Cx, dataaddress, Receive);

	//checking for EV6
	while (!(I2C_flag_status(I2Cx, EV6)));

	//I2Cx->CR1 |=I2C_CR1_ACK;

	if(datalengh){
	for(i=datalengh;i>1;i--)
		{

			while(!(I2C_flag_status(I2Cx, EV7)));
			*RX_buffer=I2Cx->DR;

			RX_buffer++;
		}

//	I2Cx->CR1 &=~I2C_CR1_ACK;
	}

	//generating stop bit
		if(stop == WITH_STOP)
		{
		I2C_generate_stop(I2Cx, Enable);
		}


		//regenerating ACK

		if(GLOBAL_I2C_CNFG[index].I2C_Achnowledge == I2C_ACK)
		{
			I2Cx->CR1 |=I2C_CR1_ACK;

		}





}

void I2C_send_address(I2Cx_typedef *I2Cx ,uint16_t address ,I2C_Direction direction)
{


	//this driver doesnt support 10-bit address only 7-bit
	address = address<<1;

	if(direction ==Transmit)
	{
		address |=(1<<0);
	}
	else{
		address &=~(1<<0);
	}

	I2Cx->DR= address;

}

void I2C_generate_start(I2Cx_typedef *I2Cx,FunctionalState fun_state,Repeated_Start start)
{

	if(start != REPEATED_START)
	{
		while(I2C_flag_status(I2Cx, I2C_busy) );
	}

	if(fun_state != Disable)
	{
		I2Cx->CR1 |=I2C_CR1_START;
	}

	else{

		I2Cx->CR1 &= ~I2C_CR1_START;

	}

}
void I2C_generate_stop(I2Cx_typedef *I2Cx,FunctionalState fun_state)
{

//	Bit 9 STOP: Stop generation
//	The bit is set and cleared by software, cleared by hardware when a Stop condition is
//	detected, set by hardware when a timeout error is detected.
//	In Master Mode:
//	0: No Stop generation.
//	1: Stop generation after the current byte transfer or after the current Start condition is sent.
//	In Slave mode:
//	0: No Stop generation.
//	1: Release the SCL and SDA lines after the current byte transfer
	if(fun_state ==Enable)
	{
		I2Cx->CR1 |=I2C_CR1_STOP;

	}
	else
	{
		I2Cx->CR1 &=~I2C_CR1_STOP;
	}


}

Flag_Status I2C_flag_status(I2Cx_typedef *I2Cx,I2C_status status )
{

	Flag_Status flag=RESET;
	uint32_t flag1,flag2 , lastevent;

	switch(status)
	{
	case I2C_busy:
	{
//		Bit 1 BUSY: Bus busy
//		0: No communication on the bus
//		1: Communication ongoing on the bus
//		– Set by hardware on detection of SDA or SCL low
//		– cleared by hardware on detection of a Stop condition.
//		It indicates a communication in progress on the bus. This information is still updated when
//		the interface is disabled (PE=0).

		if ((I2Cx->SR2) & (I2C_SR2_BUSY))
			flag = SET;
		else
			flag = RESET;
		break;
	}
	case EV5:
	{
//		Bit 0 SB: Start bit (Master mode)
//		0: No Start condition
//		1: Start condition generated.
//		– Set when a Start condition generated.
//		– Cleared by software by reading the SR1 register followed by writing the DR register, or by
//		hardware when PE=0

		if ((I2Cx->SR1) & (I2C_SR1_SB))
			flag = SET;
		else
			flag = RESET;
		break;
	}
	case EV6:
	{
//		Bit 1 ADDR: Address sent (master mode)/matched (slave mode)
//		This bit is cleared by software reading SR1 register followed reading SR2, or by hardware
//		when PE=0.
//		Address matched (Slave)
//		0: Address mismatched or not received.
//		1: Received address matched.

		if ((I2Cx->SR1) & I2C_SR1_ADDR)
			flag = SET;
		else
			flag = RESET;
		break;
	}
	case master_byte_transmitter:
	{

		// TRA, BUSY, MSL and TXE flags
		flag1 = I2Cx->SR1;
		flag2 = I2Cx->SR2;
		flag2 = flag2<<16;

		lastevent = (flag1 |flag2) &((uint32_t)(0x00ffff));

		if((lastevent &status) == status)
			flag =SET;

		else
			flag =RESET;
		break;
	}
	case EV8_1:
	{
//		Bit 7 TxE: Data register empty (transmitters)
//		0: Data register not empty
//		1: Data register empty
//		– Set when DR is empty in transmission. TxE is not set during address phase.
//		– Cleared by software writing to the DR register or by hardware after a start or a stop condition
//		or when PE=0.
//		TxE is not set if either a NACK is received, or if next byte to be transmitted is PEC (PEC=1)
//		Note: TxE is not cleared by writing the first data being transmitted, or by writing data when
//		BTF is set, as in both cases the data register is still empty

		if ((I2Cx->SR1) & I2C_SR1_TXE)
			flag = SET;
		else
			flag = RESET;
		break;
	}

	case EV8 :
	{
		if ((I2Cx->SR1) & I2C_SR1_TXE)
			flag=SET ;
		else
			flag=RESET ;
		break;

	}
	case EV7:
	{
//		Bit 6 RxNE: Data register not empty (receivers)
//		0: Data register empty
//		1: Data register not empty
//		– Set when data register is not empty in receiver mode. RxNE is not set during address phase.
//		– Cleared by software reading or writing the DR register or by hardware when PE=0.
//		RxNE is not set in case of ARLO event.
//		Note: RxNE is not cleared by reading data when BTF is set, as the data register is still full
		if((I2Cx->SR1) & I2C_SR1_RXNE)
			flag = SET;
		else
			flag = RESET;
		break;
	}

	}

	return flag; //modi

}

uint8_t MCAL_I2C_SLAVE_RX(I2Cx_typedef *I2Cx )
{
	return (uint8_t)I2Cx->DR;

}

void MCAL_I2C_SLAVE_TX(I2Cx_typedef *I2Cx ,uint8_t DATA)
{
	I2Cx->DR = DATA;
}






