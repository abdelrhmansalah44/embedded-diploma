/*
 * keypad.c
 *
 * Created: 4/22/2021 6:32:10 PM
 *  Author: Marco
 */

#include "../HAL.c/inc/keypad.h"

int Key_padRow[] = { R0, R1, R2, R3 }; //rows of the keypad
int Key_padCol[] = { C0, C1, C2, C3 }; //columns

void delay_mss(uint32_t time) {
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++)
			;
}

void Keypad_init() {
//	DataDir_KEYPAD_PORT &= ~((1 << R0) | (1 << R1) | (1 << R2) | (1 << R3));
//	DataDir_KEYPAD_PORT |= ((1 << C0) | (1 << C1) | (1 << C2) | (1 << C3));
//	KEYPAD_PORT = 0xFF;
	GPIO_CONFIGURATION Pincnfg_;

	Pincnfg_.GPIO_PIN_MODE = GPIO_PUSHPULL_OUTPUT;
	Pincnfg_.GPIO_OUTPUT_SPEED=GPIO_OUTPUT_10MHz;
	Pincnfg_.GPIO_PIN_NUMBER = R0;
	MCAL_GPIO_INIT(KEYPAD_PORT, &Pincnfg_);

	Pincnfg_.GPIO_PIN_MODE = GPIO_PUSHPULL_OUTPUT;
	Pincnfg_.GPIO_OUTPUT_SPEED=GPIO_OUTPUT_10MHz;
	Pincnfg_.GPIO_PIN_NUMBER = R1;
	MCAL_GPIO_INIT(KEYPAD_PORT, &Pincnfg_);

	Pincnfg_.GPIO_PIN_MODE = GPIO_PUSHPULL_OUTPUT;
	Pincnfg_.GPIO_OUTPUT_SPEED=GPIO_OUTPUT_10MHz;
	Pincnfg_.GPIO_PIN_NUMBER = R2;
	MCAL_GPIO_INIT(KEYPAD_PORT, &Pincnfg_);

	Pincnfg_.GPIO_PIN_MODE = GPIO_PUSHPULL_OUTPUT;
	Pincnfg_.GPIO_OUTPUT_SPEED=GPIO_OUTPUT_10MHz;
	Pincnfg_.GPIO_PIN_NUMBER = R3;
	MCAL_GPIO_INIT(KEYPAD_PORT, &Pincnfg_);

	Pincnfg_.GPIO_PIN_MODE = GPIO_PUSHPULL_OUTPUT;
	Pincnfg_.GPIO_OUTPUT_SPEED=GPIO_OUTPUT_10MHz;
	Pincnfg_.GPIO_PIN_NUMBER = C0;
	MCAL_GPIO_INIT(KEYPAD_PORT, &Pincnfg_);

	Pincnfg_.GPIO_PIN_MODE = GPIO_PUSHPULL_OUTPUT;
	Pincnfg_.GPIO_OUTPUT_SPEED=GPIO_OUTPUT_10MHz;
	Pincnfg_.GPIO_PIN_NUMBER = C1;
	MCAL_GPIO_INIT(KEYPAD_PORT, &Pincnfg_);

	Pincnfg_.GPIO_PIN_MODE = GPIO_PUSHPULL_OUTPUT;
	Pincnfg_.GPIO_OUTPUT_SPEED=GPIO_OUTPUT_10MHz;
	Pincnfg_.GPIO_PIN_NUMBER = C2;
	MCAL_GPIO_INIT(KEYPAD_PORT, &Pincnfg_);

	Pincnfg_.GPIO_PIN_MODE = GPIO_PUSHPULL_OUTPUT;
	Pincnfg_.GPIO_OUTPUT_SPEED=GPIO_OUTPUT_10MHz;
	Pincnfg_.GPIO_PIN_NUMBER = C3;
	MCAL_GPIO_INIT(KEYPAD_PORT, &Pincnfg_);







	MCAL_GPIO_WRITE_PORT(KEYPAD_PORT, 0xFF);

}

char Keypad_getkey() {
	int i, j;
	for (i = 0; i < 4; i++) {
//		KEYPAD_PORT |= ((1 << Key_padCol[0]) | (1 << Key_padCol[1])
//				| (1 << Key_padCol[2]) | (1 << Key_padCol[3]));
//		KEYPAD_PORT &= ~(1 << Key_padCol[i]);
		MCAL_GPIO_WRITE_PIN(KEYPAD_PORT, Key_padCol[0], GPIO_PIN_true);
		MCAL_GPIO_WRITE_PIN(KEYPAD_PORT, Key_padCol[1], GPIO_PIN_true);
		MCAL_GPIO_WRITE_PIN(KEYPAD_PORT, Key_padCol[2], GPIO_PIN_true);
		MCAL_GPIO_WRITE_PIN(KEYPAD_PORT, Key_padCol[3], GPIO_PIN_true);
		MCAL_GPIO_WRITE_PIN(KEYPAD_PORT, Key_padCol[i], GPIO_PIN_false);
		for (j = 0; j < 4; j++) {
			if (MCAL_GPIO_READ_PIN(KEYPAD_PORT, Key_padRow[j]) == 0) {
				while (MCAL_GPIO_READ_PIN(KEYPAD_PORT, Key_padRow[j]) == 0)
					;
				switch (i) {
				case (0):
					if (j == 0)
						return '7';
					else if (j == 1)
						return '4';
					else if (j == 2)
						return '1';
					else if (j == 3)
						return '?';
					break;
				case (1):
					if (j == 0)
						return '8';
					else if (j == 1)
						return '5';
					else if (j == 2)
						return '2';
					else if (j == 3)
						return '0';
					break;
				case (2):
					if (j == 0)
						return '9';
					else if (j == 1)
						return '6';
					else if (j == 2)
						return '3';
					else if (j == 3)
						return '=';
					break;
				case (3):
					if (j == 0)
						return '/';
					else if (j == 1)
						return '*';
					else if (j == 2)
						return '-';
					else if (j == 3)
						return '+';
					break;
				}
			}
		}
	}
	return 'A';
}
