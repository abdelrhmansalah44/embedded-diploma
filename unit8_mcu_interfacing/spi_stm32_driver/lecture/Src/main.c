/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "stm32_f103c6_SPI_driver.h"
#include "stm32_f103c6_gpio_driver.h"
#include "stm32_f103c6_uart_driver.h"

#define SPI_mode_master
//#define SPI_mode_slave

uint8_t ch;
void uart_irq_callback()
{
#ifdef SPI_mode_master
	MCAL_uart_recieve(UART1, &ch,polling_disable );
	MCAL_uart_send(UART1, &ch, polling_enable);


	MCAL_GPIO_WRITE_PIN(GPIOA, GPIO_PIN4, 0);
	MCAL_SPI_TX_RX_DATA(SPI1, &ch, enable);
	MCAL_GPIO_WRITE_PIN(GPIOA, GPIO_PIN4, 1);

#endif
}

void clock_init();


int main(void)
{
	clock_init();
	GPIO_CONFIGURATION gpio_cnfg;

	UART_config uart_cnfg;
	//UART configuration
	uart_cnfg.uart_baudrate = uart_baud_115200;
	uart_cnfg.uart_mode = uart_mode_TX_RX;
	uart_cnfg.uart_parity =uart_parity_none;
	uart_cnfg.uart_payload_length =uart_payload_8bit;
	uart_cnfg.uart_stopbits = stopbit_1;

	uart_cnfg.P_IRQ_callback=uart_irq_callback;  //
	uart_cnfg.flow_ctrl = uart_flowctrl_none;
	uart_cnfg.uart_IRQ_enable =uart_irq_enable_RXNE;

	MCAL_uart_init(UART1,&uart_cnfg);
	MCAL_GPIO_uart_init(UART1);



	SPI_config spi_cnfg;
	//----spi configuration----

	//common configuration

	spi_cnfg.clock_phase =spi_clk_phase_secondedge;
	spi_cnfg.clock_polarity = spi_clk_polarity_high;
	spi_cnfg.spi_frame = spi_frame_MSB;
	spi_cnfg.spi_datasize =spi_datasize_8bit;
	spi_cnfg.spi_communiction_mode = spi_DIRECTION_2line; //full duplex
	spi_cnfg.spi_baudrate =spi_bauderate_8;


#ifdef SPI_mode_master

	spi_cnfg.spi_mode = spi_master_mode;
	spi_cnfg.spi_NSS= spi_NSS_internalsoftware_set;
	spi_cnfg.p_IRQ_callback = NULL;
	spi_cnfg.IRQ_enable =spi_IRQ_none;


#endif

	MCAL_SPI_INIT(SPI1, &spi_cnfg);
	MCAL_GPIO_SPI_PINCONFIG(SPI1);

	gpio_cnfg.GPIO_PIN_MODE =GPIO_PUSHPULL_OUTPUT;
	gpio_cnfg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_10MHz;
	gpio_cnfg.GPIO_PIN_NUMBER=GPIO_PIN4;
	MCAL_GPIO_INIT(GPIOA, &gpio_cnfg);

	MCAL_GPIO_WRITE_PIN(GPIOA, GPIO_PIN4, 1);



   while(1){

   }
}


void clock_init()
{

	RCC_GPIOA_CLOCK_ENABLE;
	RCC_GPIOB_CLOCK_ENABLE;
	RCC_AFIO_ENABLE;

	RCC_SPI1_CLK_EN;
	RCC_USART1_CLK_EN;




}
