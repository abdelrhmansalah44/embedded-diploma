/*
 * stm32_f103c6_uart_driver.h
 *
 *  Created on: Sep 30, 2023
 *      Author: abdalrahman salah
 */

#ifndef INC_STM32_F103C6_UART_DRIVER_H_
#define INC_STM32_F103C6_UART_DRIVER_H_

#include "stm32f013x6.h"
#include "stm32_f103c6_gpio_driver.h"
#include "RCC_clock_configuration.h"



//***************************************************************
//				UART CONFIGURATION
//***************************************************************

typedef struct {

	uint8_t uart_mode;     //specify Tx/Rx  enable/disable
							//this parameter must be set based on @ref UART_MODE_define


	uint32_t uart_baudrate;   //specify baud rate
	   	   	   	   	   	   	   	 //this parameter must be set based on @ref UART_baudrate

	uint8_t uart_parity;   		 //specify parity enable or disable and parity mode
	   	   	   	 	 	 	 	 //this parameter must be set based on @ref UART_parity

	uint8_t uart_payload_length;  	//specify no of bits to store data
	 	 	 	 	 	 	 	 	 	 //this parameter must be set based on @ref UART_payload


	uint8_t uart_stopbits;   	//specify no of stop bits
								//this parameter must be set based on @ref UART_stopbits


	uint8_t uart_IRQ_enable;   //specify IRQ enable
									//this parameter must be set based on @ref uart_IRQ_enable


	uint8_t flow_ctrl;; 		 //specify the flow control bits CTS/RTS enabled/disabled
	  	  	  	  	  	  	  	  //this parameter can be a value of @ref UART_FlowCtrl_define



	void(* P_IRQ_callback)(void) ; //pointer to function that called when IRQ happen


}UART_config;



typedef enum{

	polling_enable,
	polling_disable
}Polling_mechanism;





//***************************************************************
//				UART @ref defines
//***************************************************************

//@ref UART_MODE_define

#define uart_mode_TX  		(uint32_t)(1<<3)
#define uart_mode_RX   		(uint32_t)(1<<2)
#define uart_mode_TX_RX   	(uint32_t)(1<<3 | 1<<2)

//@ref UART_baudrate

#define uart_baud_2400         2400
#define uart_baud_9600         9600
#define uart_baud_19200        19200
#define uart_baud_57600        57600
#define uart_baud_115200       115200
#define uart_baud_230400       230400
#define uart_baud_460800       460800
#define uart_baud_921600       921600
#define uart_baud_2250000      2250000
#define uart_baud_4500000      4500000


//@ref UART_parity

#define uart_parity_odd    				(uint32_t)(1<<10 | 1<<9)
#define uart_parity_even				(uint32_t)(1<<10)
#define uart_parity_none				(uint32_t)(0)


//@ref UART_payload_length
#define uart_payload_8bit				(uint32_t)(0)
#define uart_payload_9bit               (uint32_t)(1<<12)


//@ref UART_stopbits
#define stopbit_1   					(uint32_t)(0)
#define stopbit_half  					(uint32_t)(1<<12)
#define stopbit_2   					(uint32_t)(2<<12)
#define stopbit_1_half   					(uint32_t)(3<<12)


//@ref uart_IRQ_enable
#define uart_irq_NONE     	   			(uint32_t)(0)
#define uart_irq_enable_TC     			(uint32_t)(1<<6)
#define uart_irq_enable_PE     			(uint32_t)(1<<8)
#define uart_irq_enable_TXE     		(uint32_t)(1<<7)
#define uart_irq_enable_RXNE    		(uint32_t)(1<<5)


//@ref UART_FlowCtrl_define

#define uart_flowctrl_none				(uint32_t)(0)
#define uart_flowctrl_CTS				(uint32_t)(1<<9)
#define uart_flowctrl_RTS				(uint32_t)(1<<8)
#define uart_flowctrl_CTS_RTS			(uint32_t)((1<<8) | (1<<9))

//=================================================================================================================


//#define USARTDIV(_fck_, _baud_)			    (uint32_t)((_fck_)/(16*_baud_))
//#define USARTDIV_MUL100(_fck_, _baud_)      (uint32_t)((25*_fck_)/(4*_baud_))
//#define DIVMANTISSA_MUL100(_fck_,_baud_)    (uint32_t)USARTDIV(_fck_, _baud_)*100
//#define MANTISSA(_fck_,_baud_)				(uint32_t)(USARTDIV(_fck_, _baud_))
//#define DIV_FRACTION(_fck_,_baud_)			(uint32_t)(((USARTDIV_MUL100(_fck_, _baud_) -USARTDIV_MUL100(_fck_, _baud_))*16)/100)
//#define UART_BRR_REG(_fck_,_baud_)			((MANTISSA(_fck_,_baud_) )<<4) | (DIV_FRACTION(_fck_,_baud_)) & 0XF)


#define USARTDIV(_PCLK_, _BAUD_)							(uint32_t) (_PCLK_/(16 * _BAUD_ ))
#define USARTDIV_MUL100(_PCLK_, _BAUD_)						(uint32_t) ( (25 * _PCLK_ ) / (4  * _BAUD_ ))
#define Mantissa_MUL100(_PCLK_, _BAUD_)						(uint32_t) (USARTDIV(_PCLK_, _BAUD_) * 100)
#define Mantissa(_PCLK_, _BAUD_)							(uint32_t) (USARTDIV(_PCLK_, _BAUD_) )
#define DIV_Fraction(_PCLK_, _BAUD_)						(uint32_t) (((USARTDIV_MUL100(_PCLK_, _BAUD_) -  Mantissa_MUL100(_PCLK_, _BAUD_) ) * 16 ) / 100 )
#define UART_BRR_Register(_PCLK_, _BAUD_)					(( Mantissa (_PCLK_, _BAUD_) ) <<4 )|( (DIV_Fraction(_PCLK_, _BAUD_)) & 0xF )


//***************************************************************
//				UART APIS
//***************************************************************





/**================================================================
 * @Fn            - MCAL_uart_init
 * @brief         - Initialize UART
 * @param [in]    - USARTx: where x can be 1 - 3 (depending on device used) to select the USART peripheral
 * @param [in]    - UART_Config: all UART configuration
 * @retval        - none
 * Note           - none
 */
void MCAL_uart_init(UART_typedef * UARTx,UART_config * config);

/**================================================================

 * @Fn            - MCAL_uart_deinit
 * @brief         - Reseting uart
 * @param [in]    - USARTx: where x can be 1 - 3 (depending on device used) to select the USART peripheral
 * @param [in]    - none
 * @retval        - none
 * Note           - none
 */
void MCAL_uart_deinit(UART_typedef * UARTx);

/**================================================================

 * @Fn            - MCAL_GPIO_uart_init
 * @brief         - configure uart pin
 * @param [in]    - USARTx: where x can be 1 - 3 (depending on device used) to select the USART peripheral
 * @param [in]    - none
 * @retval        - none
 * Note           - none
 */
void MCAL_GPIO_uart_init(UART_typedef * UARTx);

/**================================================================

 * @Fn            - MCAL_uart_send
 * @brief         - sending data in tx buffer
 * @param [in]    - USARTx: where x can be 1 - 3 (depending on device used) to select the USART peripheral
 * @param [in]    - TX_buffer : data transmit buffer
 * @param [in]    - polling mechanism : can be enabled or disabled
 * @retval        - none
 * Note           - none
 */
void MCAL_uart_send(UART_typedef * UARTx,uint16_t *TX_buffer , Polling_mechanism polling);

/**================================================================

 * @Fn            - MCAL_uart_recieve
 * @brief         - recieving data in rx buffer
 * @param [in]    - USARTx: where x can be 1 - 3 (depending on device used) to select the USART peripheral
 * @param [in]    - RX_buffer : data recieve buffer
 * @param [in]    - polling mechanism : can be enabled or disabled
 * @retval        - none
 * Note           - none
 */
void MCAL_uart_recieve(UART_typedef * UARTx,uint16_t *RX_buffer, Polling_mechanism polling);

/**================================================================

 * @Fn            - MCAL_uart_waiting
 * @brief         - until the TC flag is enabled which indicates the end of transmission
 * @param [in]    - USARTx: where x can be 1 - 3 (depending on device used) to select the USART peripheral
 * @retval        - none
 * Note           - optional to use
 */
void MCAL_uart_waiting(UART_typedef * UARTx);



#endif /* INC_STM32_F103C6_UART_DRIVER_H_ */
