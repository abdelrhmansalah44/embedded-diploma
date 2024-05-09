/*
 * app.c
 *
 *  Created on: Nov 30, 2023
 *      Author: abdalrahman salah
 */


#include "app.h"

	uint8_t approved_id[3];
	uint8_t enteredID_buffer[20];
	uint8_t free_slots=3;
	uint16_t recieve_buff[20];
	uint8_t freeslot_buff[20];


	s_LCD_Config_t LCD_admin={
			.s_LCDCtrlPins = {GPIOB, GPIO_PIN11, GPIO_PIN10},
			.s_LCDDataPins = {GPIOB, GPIO_PIN12},
			.e_EntryMode = NOSHIFT_DECREMENT,
			.e_DispCtrl = ONDISP_BLINKCURSOR,
			.e_OperMode = FOURBIT_2LINE_10DOT,

	};

	s_LCD_Config_t LCD_user={
			.s_LCDCtrlPins = {GPIOA, GPIO_PIN5, GPIO_PIN6},
			.s_LCDDataPins = {GPIOA, GPIO_PIN12},
			.e_EntryMode = NOSHIFT_DECREMENT,
			.e_DispCtrl = ONDISP_OFFCURSOR,
			.e_OperMode = FOURBIT_2LINE_10DOT,

	};

void MCAL_init()
{

	RCC_GPIOA_CLOCK_ENABLE;
	RCC_GPIOB_CLOCK_ENABLE;
	RCC_AFIO_ENABLE;
	Timer2_init();

}

void HAL_init()
{


	LCD_init(&LCD_user);
	LCD_init(&LCD_admin);
	Keypad_init();
	PIR_init();
	led_init();
	Servo1_Entry_Gate_Init();
	Servo2_Exit_Gate_Init();

}

void parking_init()
{
	LCD_gotoxy(&LCD_admin, 0, 0);
	LCD_sendstring(&LCD_admin, (const char*) "welcome");
	delay_ms(500);
	LCD_clearscreen(&LCD_admin);

	LCD_gotoxy(&LCD_admin, 0, 0);
	LCD_sendstring(&LCD_admin, (const char*) "enter the ID");
	delay_ms(300);
	for (int i = 0; i < 3; i++) {
		LCD_gotoxy(&LCD_admin, 0, i + 1);
		sprintf(enteredID_buffer, "ENTER ID:[%d]", i + 1);
		LCD_sendstring(&LCD_admin, (const char*) enteredID_buffer);

		do {
			approved_id[i] == Keypad_getkey();
		} while (approved_id[i] == 0);
		LCD_sendchar(&LCD_admin, approved_id, DATA);
	}
	LCD_clearscreen(&LCD_admin);
	LCD_gotoxy(&LCD_admin, 0, 0);
	LCD_sendstring(&LCD_admin, (const char*) "allowed IDS:");

	for (int i = 0; i < 3; i++) {
		LCD_gotoxy(&LCD_admin, 0, i + 1);
		sprintf(enteredID_buffer, "ID[%d]: %c", i, approved_id[i]);
		LCD_sendstring(&LCD_admin, (const char*) enteredID_buffer);

	}

}
void parking_entry() {
	uint8_t flag = 1;

	uart1_config();

	LCD_gotoxy(&LCD_user, 0, 0);
	LCD_sendstring(&LCD_user, (const char*) "welcome");
	delay_ms(500);
	LCD_clearscreen(&LCD_user);

	LCD_gotoxy(&LCD_user, 0, 0);
	LCD_sendstring(&LCD_user, (const char*) "Enter your id");

	MCAL_uart_recieve(UART1, recieve_buff, polling_enable);
	for (int i = 0; i < 3; i++) {
		if (recieve_buff[i] == approved_id[i]) {
			flag = 1;

		} else {

			flag = 0;

		}
	}



	if (free_slots != 0) {

		if (flag == 1) {
			LCD_gotoxy(&LCD_user, 0, 1);
			LCD_sendstring(&LCD_user, (const char*) "  ID is true  ");
			delay_ms(300);
			free_slots--;
			sprintf(freeslot_buff,"freeslots:%d",free_slots);
			delay_ms(500);
			LCD_gotoxy(&LCD_user, 0, 2);
			LCD_sendstring(&LCD_user, (const char*) freeslot_buff);

			led__green_on();
			delay_ms(1000);
			Servo1_Entry_Gate(UP);
			delay_ms(200);
			led_green_off();

			while (PIR_Entergate());

			Servo1_Entry_Gate(Down);
		} else if (flag == 0) {
			LCD_gotoxy(&LCD_user, 0, 1);
			led__red_on();
			LCD_sendstring(&LCD_user, (const char*) "  ID is wrong  ");
			delay_ms(2000);
			led_red_off();
			LCD_clearscreen(&LCD_user);
		}

	} else {

		LCD_gotoxy(&LCD_user, 0, 1);
		LCD_sendstring(&LCD_user, "Parking is full");
	}

	delay_ms(2000);
	LCD_clearscreen(&LCD_user);


}

void parking_exit() {
		uint8_t flag = 1;

		uart2_config();

		LCD_gotoxy(&LCD_user, 0, 0);
		LCD_sendstring(&LCD_user, (const char*) "welcome");
		delay_ms(500);
		LCD_clearscreen(&LCD_user);

		LCD_gotoxy(&LCD_user, 0, 0);
		LCD_sendstring(&LCD_user, (const char*) "Enter your id");

		MCAL_uart_recieve(UART1, recieve_buff, polling_enable);
		for (int i = 0; i < 3; i++) {
			if (recieve_buff[i] == approved_id[i]) {
				flag = 1;

			} else {

				flag = 0;

			}
		}

		LCD_clearscreen(&LCD_user);


			if (flag == 1) {
				LCD_gotoxy(&LCD_user, 0, 1);
				LCD_sendstring(&LCD_user, (const char*) "  ID is true  ");
				delay_ms(300);
				free_slots++;
				sprintf(freeslot_buff, "freeslots:%d", free_slots);
				delay_ms(500);
				LCD_gotoxy(&LCD_user, 0, 2);
				LCD_sendstring(&LCD_user, (const char*) freeslot_buff);
				led__green_on();
				delay_ms(2000);
				Servo1_Entry_Gate(UP);
				delay_ms(200);
				led_green_off();

				while (PIR_Entergate());

				Servo1_Entry_Gate(Down);

			} else if (flag == 0) {
				LCD_gotoxy(&LCD_user, 0, 1);
				led__red_on();
				LCD_sendstring(&LCD_user, (const char*) "  ID is wrong  ");
				delay_ms(2000);
				led_red_off();
				LCD_clearscreen(&LCD_user);
			}



}

void uart1_config() {
	UART_config U1_config;
	U1_config.uart_mode = uart_mode_TX_RX;
	U1_config.flow_ctrl = uart_flowctrl_none;
	U1_config.uart_baudrate = uart_baud_9600;
	U1_config.uart_parity = uart_parity_none;
	U1_config.uart_payload_length = uart_payload_8bit;
	U1_config.uart_stopbits = stopbit_1;
	U1_config.P_IRQ_callback = NULL;
	U1_config.uart_IRQ_enable = uart_irq_NONE;

	MCAL_GPIO_uart_init(UART1);
	MCAL_uart_init(UART1, &U1_config);

}
void uart2_config() {
	UART_config U2_config;
	U2_config.uart_mode = uart_mode_TX_RX;
	U2_config.flow_ctrl = uart_flowctrl_none;
	U2_config.uart_baudrate = uart_baud_9600;
	U2_config.uart_parity = uart_parity_none;
	U2_config.uart_payload_length = uart_payload_8bit;
	U2_config.uart_stopbits = stopbit_1;
	U2_config.P_IRQ_callback = NULL;
	U2_config.uart_IRQ_enable = uart_irq_NONE;

	MCAL_GPIO_uart_init(UART2);
	MCAL_uart_init(UART2, &U2_config);

}
