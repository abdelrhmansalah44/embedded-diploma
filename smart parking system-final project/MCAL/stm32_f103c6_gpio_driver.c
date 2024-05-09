/*
 * stm32_f103c6_gpio_driver.c
 *
 *  Created on: Sep 18, 2023
 *      Author: abdalrahman salah
 */


#include "stm32_f103c6_gpio_driver.h"
/*
 @fc-MCAL_GPIO_INIT
 @brief-initialization for GPIO peripheral
 @param[in]- GPIO PORT
 @param[in]- pin configuration
 @returnval-none
 note- this driver is for LQFP48

 */


uint8_t get_pin_position(uint16_t pin)
{
	switch (pin) {
	case GPIO_PIN0:
			return 0;
			break;
		case GPIO_PIN1:
			return 4;
			break;
		case GPIO_PIN2:
			return 8;
			break;
		case GPIO_PIN3:
			return 12;
			break;
		case GPIO_PIN4:
			return 16;
			break;
		case GPIO_PIN5:
			return 20;
			break;
		case GPIO_PIN6:
			return 24;
			break;
		case GPIO_PIN7:
			return 28;
			break;
		case GPIO_PIN8:
			return 0;
			break;
		case GPIO_PIN9:
			return 4;
			break;
		case GPIO_PIN10:
			return 8;
			break;
		case GPIO_PIN11:
			return 12;
			break;
		case GPIO_PIN12:
			return 16;
			break;
		case GPIO_PIN13:
			return 20;
			break;
		case GPIO_PIN14:
			return 24;
			break;
		case GPIO_PIN15:
			return 28;
			break;
		}


	return -1;

}


void MCAL_GPIO_INIT(GPIOx_typedef *GPIOx, GPIO_CONFIGURATION *pin_config){

	volatile uint32_t *configregister = NULL;
     uint16_t val;
	//check if the pin lies in CRL range or CRH range -> CRL[0-7] CRH[8-15]

	configregister =((pin_config->GPIO_PIN_NUMBER) < GPIO_PIN8 ) ? &GPIOx->CRL : &GPIOx->CRH;

	//Clear  CNFy[1:0] MODEy[1:0] 4BITS OF THE PIN
	*configregister &= ~( 0xF<< get_pin_position(pin_config->GPIO_PIN_NUMBER) );

	//if the pin is in output mode
	if(pin_config->GPIO_PIN_MODE==GPIO_PUSHPULL_OUTPUT || pin_config->GPIO_PIN_MODE==GPIO_OPENDRAIN_OUTPUT || pin_config->GPIO_PIN_MODE==GPIO_AFIO_PP_OUTPUT  || pin_config->GPIO_PIN_MODE==GPIO_AFIO_OP_OUTPUT )
	{
		//set the values for CNF bits and MODEy
		val =(((pin_config->GPIO_PIN_MODE - 4) << 2 | pin_config->GPIO_OUTPUT_SPEED  )) & 0x0f;

	}

	//in case if the pin is input
	else
	{
		if(pin_config->GPIO_PIN_MODE == GPIO_FLOATING_INPUT || pin_config->GPIO_PIN_MODE == GPIO_ANALOG)
		{

			val =((pin_config->GPIO_PIN_MODE )<< 2 | (0x0)  ) & 0x0f;

		}

		else
		{
				val =((pin_config->GPIO_PIN_MODE)<<2) &0x0f;
			if(pin_config->GPIO_PIN_MODE == GPIO_PULLUP_INPUT)
			{
				GPIOx->ODR |= (pin_config->GPIO_PIN_NUMBER);

			}
			else
			{
				GPIOx->ODR &= ~(pin_config->GPIO_PIN_NUMBER);

			}

		}

	}


	*configregister |=(val << (get_pin_position(pin_config->GPIO_PIN_NUMBER)));

}
//===============================================================================
/*
 @fc-MCAL_GPIO_DeINIT
 @brief- for reseting the GPIO port
 @param[in]-GPIO port
 @returnval-none
 note- none
 */
void MCAL_GPIO_DeINIT(GPIOx_typedef *GPIOx){


	if(GPIOx == GPIOA)
	{
		RCC->APB2RSTR |=(1<<2);
		RCC->APB2RSTR &=~(1<<2);
	}

	else if(GPIOx == GPIOB)
	{
		RCC->APB2RSTR |=(1<<3);
		RCC->APB2RSTR &=~(1<<3);
	}

	else if(GPIOx == GPIOC)
	{
		RCC->APB2RSTR |=(1<<4);
		RCC->APB2RSTR &=~(1<<4);
	}

	else if(GPIOx == GPIOD)
	{
		RCC->APB2RSTR |=(1<<5);
		RCC->APB2RSTR &=~(1<<5);
	}

	else if(GPIOx == GPIOE)
	{
		RCC->APB2RSTR |=(1<<6);
		RCC->APB2RSTR &=~(1<<6);
	}


}

//=========================================================================
/*
 @fc-MCAL_GPIO_WRITE_PIN
 @brief- write on any pin
 @param[in]-GPIO port
 @param[in]-pin number
 @param[in]-value
 @returnval-none
 note- none
 */
void MCAL_GPIO_WRITE_PIN(GPIOx_typedef *GPIOx, uint16_t pin_number ,uint8_t value){


			if(value == GPIO_PIN_true)
			{
				GPIOx->BSRR =(uint32_t)pin_number;
			}

			else
			{
				GPIOx->BRR =(uint32_t)pin_number;
			}

}
//========================================================================
/*
 @fc-MCAL_GPIO_WRITE_PORT
 @brief-write on any port
 @param[in]-GPIO port
 @param[in]-value
 @returnval-none
 note- none
 */
void MCAL_GPIO_WRITE_PORT(GPIOx_typedef *GPIOx , uint8_t value){


       GPIOx->ODR =(uint32_t)value;

}

//=========================================================================
/*
 @fc-MCAL_GPIO_READ_PI
 @brief-read on any port
 @param[in]-GPIO port
 @param[in]-pin number
 @returnval-pin state
 note- none
 */
uint8_t MCAL_GPIO_READ_PIN(GPIOx_typedef *GPIOx, uint16_t pin_number){


	uint8_t statues;
	if((GPIOx->IDR & pin_number) !=(uint32_t)GPIO_PIN_false)
		statues =GPIO_PIN_true;

	else
		statues =GPIO_PIN_false;

            return statues;

}


//========================================================================
/*
 @fc-MCAL_GPIO_READ_PORT
 @brief-write on any port
 @param[in]-GPIO port
 @returnval-port state
 note- none
 note-
 */

uint16_t MCAL_GPIO_READ_PORT(GPIOx_typedef *GPIOx){


    return (uint16_t)(GPIOx->IDR);
}


//========================================================================
/*
 @fc-MCAL_GPIO_TOGGLE
 @brief- toggle the pin
 @param[in]-GPIO port
 @param[in]-pin number
 @returnval-none
 note- none
 */
void MCAL_GPIO_TOGGLE(GPIOx_typedef *GPIOx, uint16_t pin_number){


		GPIOx->ODR ^=pin_number;


}


//========================================================================
/*
 @fc-MCAL_GPIO_LOCKPIN
 @brief- locking the pin at its own state
 @param[in]-GPIO port
 @param[in]-pin number
 @returnval-none
 note- none
 */
uint8_t MCAL_GPIO_LOCKPIN(GPIOx_typedef *GPIOx, uint16_t pin_number){

	volatile uint32_t temp = (1<<16);

		//set the LCKy ( the number of bit you want to lock )

		temp |= pin_number;

		//write 1
		GPIOx->LCKR = temp;

		//write 0
		GPIOx->LCKR = pin_number;

		//write 1
		GPIOx->LCKR = temp;

		//read
		temp = GPIOx->LCKR;

		if((uint32_t)((GPIOx->LCKR>>16) &1) == GPIO_RETURN_LOCK_Enabled)
		{
			return GPIO_RETURN_LOCK_Enabled;
		}
		else
		{
			return GPIO_RETURN_LOCK_erorr;
		}


}
void MCAL_GPIO_WriteGroup(GPIOx_typedef * GPIOx,uint16_t Value,uint16_t Mask)
{
	GPIOx->ODR &= ~(Mask);				// clear the group
	GPIOx->ODR |= (Value & Mask);		// put the new value
}
//========================================================================
