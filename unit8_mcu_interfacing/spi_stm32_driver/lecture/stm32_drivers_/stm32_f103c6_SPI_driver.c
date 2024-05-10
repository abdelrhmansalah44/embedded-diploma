/*
 * stm32_f103c6_SPI_driver.c
 *
 *  Created on: Oct 7, 2023
 *      Author: abdalrahman salah
 */

#include "stm32_f103c6_SPI_driver.h"
#include "stm32_f103c6_gpio_driver.h"


//**************************************************************************
//					GLOBAL VARIABLES
//**************************************************************************

SPI_config *Global_config[2] = {NULL,NULL};
SPI_config Global_SPI1;
SPI_config Global_SPI2;


//**************************************************************************
//					GENERIC MACROS
//**************************************************************************

#define SPI1_index     0
#define SPI2_index 	   1

#define spi_sr_txe    ((uint32_t)(1<<1))
#define spi_sr_rxe    ((uint32_t)(1<<0))



void MCAL_SPI_INIT(SPIx_typedef *spix , SPI_config *confg)
{

	//safety
//	uint16_t tmp_reg_CR1=0;
//	uint16_t tmp_reg_CR2=0;

	if(spix == SPI1)
	{
		RCC_SPI1_CLK_EN;
		Global_SPI1 = *confg;
		Global_config[SPI1_index] = &Global_SPI1;


	}
	else if(spix == SPI2)
	{
		RCC_SPI2_CLK_EN;
		Global_SPI2 = *confg;
		Global_config[SPI2_index]=&Global_SPI2;

	}



	//spi_mode (slave or master)
	spix->CR1 |= confg->spi_mode;

	//communication mode configuration
	spix->CR1 |= confg->spi_communiction_mode;

	//frame
	spix->CR1 |= confg->spi_frame;

	//data size
	spix->CR1 |= confg->spi_datasize;

	//clock polarity
	spix->CR1 |= confg->clock_polarity;

	//clock_phase
	spix->CR1 |= confg->clock_phase;

//===========================NSS================================================

	if(confg->spi_NSS == spi_NSS_hardware_output_enable)
	{
		spix->CR2 |= confg->spi_NSS;

	}
	else if(confg->spi_NSS == spi_NSS_hardware_output_disable)
	{
		spix->CR2 &= confg->spi_NSS;
	}
	else
	{
		spix->CR1 &= confg->spi_NSS;

	}

//=======================baudrate prescaler================================
	spix->CR1 |= confg->spi_baudrate;

//==============irq_enable==========================================

	if(confg->IRQ_enable !=spi_IRQ_none)
	{
		spix->CR2 |= confg->IRQ_enable;

		if(spix ==SPI1)
		{
			NVIC_IRQ35_SPI1_ENABLE;
		}
		else if(spix ==SPI2)
		{
			NVIC_IRQ36_SPI2_ENABLE;

		}

	}

//	spix->CR1 =tmp_reg_CR1;
//	spix->CR2 =tmp_reg_CR2;


	//spi enable
	spix->CR1 |=(1<<6);
}
void MCAL_SPI_DEinit(SPIx_typedef *spix){

	if(spix == SPI1)
	{
		RCC_SPI1_CLK_DIS;
		NVIC_IRQ35_SPI1_DISABLE;

	}
	else if(spix == SPI2)
	{
		RCC_SPI2_CLK_DIS;
		NVIC_IRQ36_SPI2_DISABLE;
	}

}
void MCAL_GPIO_SPI_PINCONFIG(SPIx_typedef *spix){


		GPIO_CONFIGURATION gpio_confg;

	if(spix == SPI1)
	{
		if(Global_config[SPI1_index]->spi_mode==spi_master_mode)
		{

			switch(Global_config[SPI1_index]->spi_NSS)
			{
				//NSS  PA4
			case spi_NSS_hardware_output_disable:
				gpio_confg.GPIO_PIN_MODE = GPIO_FLOATING_INPUT;
				gpio_confg.GPIO_PIN_NUMBER = GPIO_PIN4;
				MCAL_GPIO_INIT(GPIOA, &gpio_confg);
				break;


			case spi_NSS_hardware_output_enable:
				gpio_confg.GPIO_PIN_MODE = GPIO_AFIO_PP_OUTPUT;
				gpio_confg.GPIO_PIN_NUMBER = GPIO_PIN4;
				gpio_confg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_10MHz;
				MCAL_GPIO_INIT(GPIOA, &gpio_confg);
				break;
			}
		//SCK  PA5
			gpio_confg.GPIO_PIN_MODE =GPIO_AFIO_PP_OUTPUT;
			gpio_confg.GPIO_PIN_NUMBER = GPIO_PIN5;
			gpio_confg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_10MHz;
			MCAL_GPIO_INIT(GPIOA, &gpio_confg);


		//MOSI PA7
			gpio_confg.GPIO_PIN_MODE = GPIO_AFIO_PP_OUTPUT;
			gpio_confg.GPIO_PIN_NUMBER = GPIO_PIN7;
			gpio_confg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_10MHz;
			MCAL_GPIO_INIT(GPIOA, &gpio_confg);

		//MISO PA6
			gpio_confg.GPIO_PIN_MODE = GPIO_FLOATING_INPUT;
			gpio_confg.GPIO_PIN_NUMBER = GPIO_PIN6;
			MCAL_GPIO_INIT(GPIOA, &gpio_confg);


		}
		else{
			//slave

			if(Global_config[SPI1_index]->spi_NSS==spi_NSS_hardware_slave)
			{
			//NSS  PA4

			gpio_confg.GPIO_PIN_MODE = GPIO_FLOATING_INPUT;
			gpio_confg.GPIO_PIN_NUMBER = GPIO_PIN4;
			MCAL_GPIO_INIT(GPIOA, &gpio_confg);

			}


			//SCK  PA5
				gpio_confg.GPIO_PIN_MODE = GPIO_FLOATING_INPUT;
				gpio_confg.GPIO_PIN_NUMBER = GPIO_PIN5;
				MCAL_GPIO_INIT(GPIOA, &gpio_confg);


			//MOSI PA7
				gpio_confg.GPIO_PIN_MODE = GPIO_FLOATING_INPUT;
				gpio_confg.GPIO_PIN_NUMBER = GPIO_PIN7;
				MCAL_GPIO_INIT(GPIOA, &gpio_confg);

			//MISO PA6
			gpio_confg.GPIO_PIN_MODE = GPIO_AFIO_PP_OUTPUT;
			gpio_confg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_10MHz;
			gpio_confg.GPIO_PIN_NUMBER = GPIO_PIN6;
			MCAL_GPIO_INIT(GPIOA, &gpio_confg);


		}




	}

	else if (spix == SPI2) {

		if (Global_config[SPI2_index]->spi_mode == spi_master_mode) {

			switch (Global_config[SPI2_index]->spi_NSS) {

			//NSS  PB12
			case spi_NSS_hardware_output_disable:
				gpio_confg.GPIO_PIN_MODE = GPIO_FLOATING_INPUT;
				gpio_confg.GPIO_PIN_NUMBER = GPIO_PIN12;
				MCAL_GPIO_INIT(GPIOB, &gpio_confg);
				break;

			case spi_NSS_hardware_output_enable:
				gpio_confg.GPIO_PIN_MODE = GPIO_AFIO_PP_OUTPUT;
				gpio_confg.GPIO_PIN_NUMBER = GPIO_PIN12;
				gpio_confg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_10MHz;
				MCAL_GPIO_INIT(GPIOA, &gpio_confg);
				break;
			}
		    //SCK  PB13

			gpio_confg.GPIO_PIN_MODE = GPIO_PUSHPULL_OUTPUT;
			gpio_confg.GPIO_PIN_NUMBER = GPIO_PIN13;
			gpio_confg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_10MHz;
			MCAL_GPIO_INIT(GPIOB, &gpio_confg);

			//MOSI PB15
			gpio_confg.GPIO_PIN_MODE = GPIO_AFIO_PP_OUTPUT;
			gpio_confg.GPIO_PIN_NUMBER = GPIO_PIN5;
			gpio_confg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_10MHz;
			MCAL_GPIO_INIT(GPIOB, &gpio_confg);

			//MISO PB14
			gpio_confg.GPIO_PIN_MODE = GPIO_FLOATING_INPUT;
			gpio_confg.GPIO_PIN_NUMBER = GPIO_PIN14;
			MCAL_GPIO_INIT(GPIOB, &gpio_confg);

		} else {
			//slave

			if (Global_config[SPI2_index] == spi_NSS_hardware_slave) {
				//NSS  PB12

				gpio_confg.GPIO_PIN_MODE = GPIO_FLOATING_INPUT;
				gpio_confg.GPIO_PIN_NUMBER = GPIO_PIN12;
				MCAL_GPIO_INIT(GPIOB, &gpio_confg);

				//SCK  PB13
				gpio_confg.GPIO_PIN_MODE = GPIO_FLOATING_INPUT;
				gpio_confg.GPIO_PIN_NUMBER = GPIO_PIN13;
				MCAL_GPIO_INIT(GPIOB, &gpio_confg);

				//MOSI PB15
				gpio_confg.GPIO_PIN_MODE = GPIO_FLOATING_INPUT;
				gpio_confg.GPIO_PIN_NUMBER = GPIO_PIN15;
				MCAL_GPIO_INIT(GPIOB, &gpio_confg);

				//MISO PB14
				gpio_confg.GPIO_PIN_MODE = GPIO_AFIO_PP_OUTPUT;
				gpio_confg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_10MHz;
				gpio_confg.GPIO_PIN_NUMBER = GPIO_PIN14;
				MCAL_GPIO_INIT(GPIOB, &gpio_confg);

			}

		}



		}




}
void MCAL_SPI_SEND_DATA(SPIx_typedef *spix , uint16_t *TXbuff ,polling_mechanism polling )
{

	if(polling ==enable)

	{
		while(!((spix->SR )& spi_sr_txe));
	}

		spix->DR = *TXbuff;


}
void MCAL_SPI_recieve_DATA(SPIx_typedef *spix , uint16_t *TXbuff  ,polling_mechanism polling ){

	if(polling ==enable){


		while(!((spix->SR) & spi_sr_rxe));
	}

	*TXbuff =spix->DR ;



}
void MCAL_SPI_TX_RX_DATA(SPIx_typedef *spix , uint16_t *TXbuff  ,polling_mechanism polling ){

	if (polling == enable)
	{
		while(!((spix->SR) & spi_sr_txe));
	}
	else{
	spix->DR = *TXbuff ;
	}

	if (polling == enable)
	{
		while(!((spix->SR) & spi_sr_rxe));
	}
	*TXbuff  = spix->DR;

}

void SPI1_IRQHandler()
{
	struct spi_IRQ_src irq_src;

	irq_src.TXE = ((SPI1->SR & (1<<1)) >> 1);
	irq_src.RXNEIE = ((SPI1->SR & (1<<0)) >> 0);
	irq_src.ERRIE = ((SPI1->SR & (1<<4)) >> 4);

	Global_config[SPI1_index]->p_IRQ_callback(irq_src);


}
void SPI2_IRQHandler()
{
	struct spi_IRQ_src irq_src;

	irq_src.TXE = ((SPI2->SR & (1<<1)) >> 1);
		irq_src.RXNEIE = ((SPI2->SR & (1<<0)) >> 0);
		irq_src.ERRIE = ((SPI2->SR & (1<<4)) >> 4);

	Global_config[SPI2_index]->p_IRQ_callback(irq_src);

}



