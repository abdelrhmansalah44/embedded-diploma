/*
 * stm32_f103c6_uart_driver.c
 *
 *  Created on: Sep 30, 2023
 *      Author: abdalrahman salah
 */

#include "stm32_f103c6_uart_driver.h"


UART_config *Global_UART_Config = NULL;
/*
 * ===============================================
 * Generic Functions definitions
 * ===============================================
 */


void MCAL_uart_init(UART_typedef * UARTx, UART_config * config)
{

	Global_UART_Config =config;
	uint16_t fclk ;

	if (UARTx == UART1) {
		RCC_USART1_CLK_EN;

	} else if (UARTx == UART2) {
		RCC_USART2_CLK_EN;
	}

	else if (UARTx == UART3) {

		RCC_USART3_CLK_EN;
	}

//	 Enable the USART by writing the UE bit in USART_CR1 register to 1.
	UARTx->CR1 |= (1 << 13);


//configure uart mode TX or RX
	UARTx->CR1 |=config->uart_mode;

//Program the M bit in USART_CR1 to define the word length.
	UARTx->CR1 |= config->uart_payload_length;

//CONFIGURE parity
	UARTx->CR1 |=config->uart_parity;

//Program the number of stop bits in USART_CR2.
	UARTx->CR2 |=config->uart_stopbits;


//configure flow control
	UARTx->CR3 |=config->flow_ctrl;


//Select the desired baud rate using the USART_BRR register

    if(UARTx == UART1)

    {
    	fclk = MCAL_RCC_GetPCLK2Freq();
    }
    else
    {
    	fclk=MCAL_RCC_GetPCLK1Freq();
    }

    UARTx->BRR = (UART_BRR_Register(fclk,config->uart_baudrate));

//configure irq

	if (config->uart_IRQ_enable != uart_irq_NONE) {
		UARTx->CR1 |= config->uart_IRQ_enable;

		//NVIC enable
		if (UARTx == UART1) {
			NVIC_USART1_IRQ_ENABLE;
		} else if (UARTx == UART2) {
			NVIC_USART2_IRQ_ENABLE;
		} else if (UARTx == UART3) {
			NVIC_USART3_IRQ_ENABLE;
		}
	}

}
void MCAL_uart_deinit(UART_typedef * UARTx)
{

	if(UARTx == UART1)
	{
	RCC_USART1_CLK_DIS;
	NVIC_USART1_IRQ_DISABLE;

	}

	else if(UARTx == UART2)
	{
	RCC_USART2_CLK_DIS;
	NVIC_USART2_IRQ_DISABLE;

	}
	else if(UARTx == UART3)
	{
	RCC_USART3_CLK_DIS;
	NVIC_USART3_IRQ_DISABLE;

	}

}
void MCAL_GPIO_uart_init(UART_typedef * UARTx)
{
	GPIO_CONFIGURATION gpio_config;


	if(UARTx == UART1)
	{
	//uart1   pa9 tx , pa10 rx, pa11 cts, pa12 rts

	//tx
	gpio_config.GPIO_PIN_NUMBER = GPIO_PIN9 ;
	gpio_config.GPIO_PIN_MODE = GPIO_PUSHPULL_OUTPUT;
	gpio_config.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_10MHz;
	MCAL_GPIO_INIT(GPIOA, &gpio_config);


	//rx
	gpio_config.GPIO_PIN_NUMBER = GPIO_PIN10 ;
	gpio_config.GPIO_PIN_MODE = GPIO_FLOATING_INPUT;
	MCAL_GPIO_INIT(GPIOA, &gpio_config);


	if(Global_UART_Config->flow_ctrl == uart_flowctrl_RTS || Global_UART_Config->flow_ctrl == uart_flowctrl_CTS_RTS)
	{
	//rts
	gpio_config.GPIO_PIN_NUMBER = GPIO_PIN12 ;
	gpio_config.GPIO_PIN_MODE = GPIO_PUSHPULL_OUTPUT;
	gpio_config.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_10MHz;
	MCAL_GPIO_INIT(GPIOA, &gpio_config);
	}

	else if(Global_UART_Config->flow_ctrl == uart_flowctrl_CTS || Global_UART_Config->flow_ctrl == uart_flowctrl_CTS_RTS)
	{
	//cts
	gpio_config.GPIO_PIN_NUMBER = GPIO_PIN11 ;
	gpio_config.GPIO_PIN_MODE = GPIO_FLOATING_INPUT;
	MCAL_GPIO_INIT(GPIOA, &gpio_config);

	}



	}
	else if (UARTx == UART2) {
		//uart2   pa0 cts , pa1 rts , pa3 rx , pa2 tx

		//tx

		gpio_config.GPIO_PIN_NUMBER = GPIO_PIN2;
		gpio_config.GPIO_PIN_MODE = GPIO_PUSHPULL_OUTPUT;
		gpio_config.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_10MHz;
		MCAL_GPIO_INIT(GPIOA, &gpio_config);

		//rx
		gpio_config.GPIO_PIN_NUMBER = GPIO_PIN3;
		gpio_config.GPIO_PIN_MODE = GPIO_FLOATING_INPUT;
		MCAL_GPIO_INIT(GPIOA, &gpio_config);

		if (Global_UART_Config->flow_ctrl == uart_flowctrl_RTS || Global_UART_Config->flow_ctrl == uart_flowctrl_CTS_RTS) {
			//rts
			gpio_config.GPIO_PIN_NUMBER = GPIO_PIN1;
			gpio_config.GPIO_PIN_MODE = GPIO_PUSHPULL_OUTPUT;
			gpio_config.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_10MHz;
			MCAL_GPIO_INIT(GPIOA, &gpio_config);
		}

		else if (Global_UART_Config->flow_ctrl == uart_flowctrl_CTS || Global_UART_Config->flow_ctrl == uart_flowctrl_CTS_RTS) {
			//cts
			gpio_config.GPIO_PIN_NUMBER = GPIO_PIN0;
			gpio_config.GPIO_PIN_MODE = GPIO_FLOATING_INPUT;
			MCAL_GPIO_INIT(GPIOA, &gpio_config);

		}

	}

	else if (UARTx == UART2) {
	//uart3   pb10 tx, pb11 rx ,pb13 cts, pb14 rts

		//tx

		gpio_config.GPIO_PIN_NUMBER = GPIO_PIN10;
		gpio_config.GPIO_PIN_MODE = GPIO_PUSHPULL_OUTPUT;
		gpio_config.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_10MHz;
		MCAL_GPIO_INIT(GPIOB, &gpio_config);

		//rx
		gpio_config.GPIO_PIN_NUMBER = GPIO_PIN11;
		gpio_config.GPIO_PIN_MODE = GPIO_FLOATING_INPUT;
		MCAL_GPIO_INIT(GPIOB, &gpio_config);

		if (Global_UART_Config->flow_ctrl == uart_flowctrl_RTS || Global_UART_Config->flow_ctrl == uart_flowctrl_CTS_RTS) {
			//rts
			gpio_config.GPIO_PIN_NUMBER = GPIO_PIN14;
			gpio_config.GPIO_PIN_MODE = GPIO_PUSHPULL_OUTPUT;
			gpio_config.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_10MHz;
			MCAL_GPIO_INIT(GPIOB, &gpio_config);
		}

		else if (Global_UART_Config->flow_ctrl == uart_flowctrl_CTS || Global_UART_Config->flow_ctrl == uart_flowctrl_CTS_RTS) {
			//cts
			gpio_config.GPIO_PIN_NUMBER = GPIO_PIN13;
			gpio_config.GPIO_PIN_MODE = GPIO_FLOATING_INPUT;
			MCAL_GPIO_INIT(GPIOB, &gpio_config);

		}


	}


}
void MCAL_uart_send(UART_typedef * UARTx,uint16_t *TX_buffer ,  Polling_mechanism polling)
{


	if(polling == polling_enable)
	{
		while(!((UARTx->SR)&(1<<7)));
	}

	if(Global_UART_Config->uart_payload_length == uart_payload_9bit)
	{
		//9it
		UARTx->DR = (*TX_buffer & (uint16_t)0x01ff);

	}
	else

	{  //8bit
		UARTx->DR = (*TX_buffer & (uint8_t)0xff);


	}


}
void MCAL_uart_recieve(UART_typedef * UARTx,uint16_t *RX_buffer, Polling_mechanism polling)
{


	if(polling == polling_enable)
		{
			while(!((UARTx->SR)&(1<<5)));
		}

if(Global_UART_Config->uart_payload_length == uart_payload_9bit)
	{

	if(Global_UART_Config->uart_parity == uart_parity_none)

		{
			*((uint16_t*)RX_buffer) = UARTx->DR;
		}
	else
	{
		*((uint16_t*)RX_buffer) = UARTx->DR & (uint8_t)(0xff);

	}
	}

	else
		{

		if(Global_UART_Config->uart_parity == uart_parity_none)

			{
				*((uint16_t*)RX_buffer) = (UARTx->DR & (uint8_t)(0xff));
			}
		else
		{
			*((uint16_t*)RX_buffer) = (UARTx->DR & (uint8_t)(0x7f));

		}


	}


}
void MCAL_uart_waiting(UART_typedef * UARTx)
{

	while(!((UARTx->SR)&(1<<6)));
}



//ISR

void USART1_IRQHandler(void)
{
	/* USART1 global interrupt */
	Global_UART_Config->P_IRQ_callback();
}

void USART2_IRQHandler(void)
{
	/* USART2 global interrupt */
	Global_UART_Config->P_IRQ_callback ();
}

void USART3_IRQHandler(void)
{
	/* USART3 global interrupt */
	Global_UART_Config->P_IRQ_callback ();
}
