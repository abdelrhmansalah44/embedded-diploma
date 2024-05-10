/*
 * stm32_f103c6_SPI_driver.h
 *
 *  Created on: Oct 7, 2023
 *      Author: abdalrahman salah
 */

#ifndef STM32_F103C6_SPI_DRIVER_H_
#define STM32_F103C6_SPI_DRIVER_H_

#include "stm32f013x6.h"
#include "stm32_f103c6_gpio_driver.h"

struct spi_IRQ_src{

	uint16_t TXE:1;
	uint16_t RXNEIE:1;
	uint16_t ERRIE:1;
	uint16_t reserved:5;

};

typedef struct{

	uint16_t spi_mode;     					// configuring spi if it is in slave mode or master mode
											// look into @ref spi_mode_config

	uint16_t spi_communiction_mode;   // look into @ref spi_communiction_mode

	uint16_t spi_frame;     //configuring spi frame if its is MSB or LSB
	 	 	 	 	 	 	 // look into @ref spi_frame_config


	uint16_t spi_datasize;    //configuring spi datasize if it is 8-bit or 16-bit
							 // look into @ref spi_datasize_config


	uint16_t spi_baudrate;		//configuring spi baud rate
	 	 	 	 	 	 	 	 // look into @ref spi_baudrate_config
								// note: spi baud rate configuration depends on the bus clock of SPIx which is then will have a maximum
								// clock rate of FCK/2 , can be configured as well


	uint16_t clock_phase;      // configuring spi clock phase
								// look into @ref spi_clock_phase_config



	uint16_t clock_polarity;		 // configuring spi clock phase
									// look into @ref spi_clock_polarity_config

	uint16_t spi_NSS;				// configuring spi NSS PIN
									// look into @ref spi_NSS_config



	uint16_t IRQ_enable;        // look into @ref spi_IRQ_enable_config

	void (*p_IRQ_callback)(struct spi_IRQ_src irq_src);



}SPI_config;

typedef enum{

	disable,
	enable

}polling_mechanism;




//*****************************************************************
//				REFERENCE MACROS
//*****************************************************************


//@ref spi_mode_config
#define spi_master_mode			 				(1<<2)
#define spi_slave_mode						   (0x00000000U)


//@ref spi_communiction_mode

#define spi_2lines_RXonly          				(1<<10)
#define spi_1lines_RXonly          				(1<<15)
#define spi_1lines_TXonly          				((1<<15) | (1<<14))
#define spi_DIRECTION_2line       				(0x00000000)



// @ref spi_frame_config
#define spi_frame_MSB						   (0x00000000U)
#define spi_frame_LSB			 				(1<<7)


// @ref spi_datasize_config
#define spi_datasize_8bit   				  (0x00000000U)
#define spi_datasize_16bit   	 				(1<<11)


//@ref spi_clock_phase_config
#define spi_clk_phase_firstedge    				(0x00000000U)
#define spi_clk_phase_secondedge				 (1<<0)


//@ref spi_clock_polarity_config
#define spi_clk_polarity_low					(0x00000000U)
#define spi_clk_polarity_high	  				 (1<<1)


//@ref spi_NSS_config
#define spi_NSS_hardware_slave					 (0x00000000U)
#define spi_NSS_hardware_output_enable		 	 (1<<2)
#define spi_NSS_hardware_output_disable			(0x00000000U)
#define spi_NSS_internalsoftware_reset 		     (1<<9)
#define spi_NSS_internalsoftware_set	         ((1<<9) | (1<<8))

//@ref spi_IRQ_enable_config
#define spi_IRQ_TXEIE_enable					 (uint32_t)(1<<7)
#define spi_IRQ_RXNEIE_enable					 (uint32_t)(1<<6)
#define spi_IRQ_ERRIE_enable					 (uint32_t)(1<<5)
#define spi_IRQ_none						 	 (0x00000000U)


//@ref spi_baudrate_config
#define spi_bauderate_2							 (0x00000000)
#define spi_bauderate_4							 (0b001<<3)
#define spi_bauderate_8							 (0b010<<3)
#define spi_bauderate_16						 (0b011<<3)
#define spi_bauderate_32						 (0b100<<3)
#define spi_bauderate_64						 (0b101<<3)
#define spi_bauderate_128						 (0b110<<3)
#define spi_bauderate_256						 (0b111<<3)



//******************************************************************************
//							APIS
//******************************************************************************


void MCAL_SPI_INIT(SPIx_typedef *spix , SPI_config *confg);
void MCAL_SPI_DEinit(SPIx_typedef *spix);
void MCAL_GPIO_SPI_PINCONFIG(SPIx_typedef *spix);
void MCAL_SPI_SEND_DATA(SPIx_typedef *spix , uint16_t *TXbuff ,polling_mechanism polling );
void MCAL_SPI_recieve_DATA(SPIx_typedef *spix , uint16_t *RXbuff ,polling_mechanism polling );
void MCAL_SPI_TX_RX_DATA(SPIx_typedef *spix , uint16_t *TX_RX_buff ,polling_mechanism polling );





#endif /* STM32_F103C6_SPI_DRIVER_H_ */
