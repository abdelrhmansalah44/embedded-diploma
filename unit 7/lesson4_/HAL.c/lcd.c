/*
 * lcd.c
 *
 * Created: 4/22/2021 3:01:11 PM
 *  Author: Marco
 */

#include "../HAL.c/inc/lcd.h"

GPIO_CONFIGURATION pincnfg;

void delay_ms(uint32_t time) {
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++)
			;
}

void LCD_GPIO_init() {
	pincnfg.GPIO_PIN_NUMBER = RS_SWITCH;
	pincnfg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_10MHz;
	pincnfg.GPIO_PIN_MODE = GPIO_PUSHPULL_OUTPUT;
	MCAL_GPIO_INIT(LCD_CTRL, &pincnfg);

	pincnfg.GPIO_PIN_NUMBER = RW_SWITCH;
	pincnfg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_10MHz;
	pincnfg.GPIO_PIN_MODE = GPIO_PUSHPULL_OUTPUT;
	MCAL_GPIO_INIT(LCD_CTRL, &pincnfg);

	pincnfg.GPIO_PIN_NUMBER = EN_SWITCH;
	pincnfg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_10MHz;
	pincnfg.GPIO_PIN_MODE = GPIO_PUSHPULL_OUTPUT;
	MCAL_GPIO_INIT(LCD_CTRL, &pincnfg);

	pincnfg.GPIO_PIN_NUMBER = GPIO_PIN0;
	pincnfg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_10MHz;
	pincnfg.GPIO_PIN_MODE = GPIO_PUSHPULL_OUTPUT;
	MCAL_GPIO_INIT(LCD_CTRL, &pincnfg);

	pincnfg.GPIO_PIN_NUMBER = GPIO_PIN1;
	pincnfg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_10MHz;
	pincnfg.GPIO_PIN_MODE = GPIO_PUSHPULL_OUTPUT;
	MCAL_GPIO_INIT(LCD_CTRL, &pincnfg);

	pincnfg.GPIO_PIN_NUMBER = GPIO_PIN2;
	pincnfg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_10MHz;
	pincnfg.GPIO_PIN_MODE = GPIO_PUSHPULL_OUTPUT;
	MCAL_GPIO_INIT(LCD_CTRL, &pincnfg);

	pincnfg.GPIO_PIN_NUMBER = GPIO_PIN3;
	pincnfg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_10MHz;
	pincnfg.GPIO_PIN_MODE = GPIO_PUSHPULL_OUTPUT;
	MCAL_GPIO_INIT(LCD_CTRL, &pincnfg);

	pincnfg.GPIO_PIN_NUMBER = GPIO_PIN4;
	pincnfg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_10MHz;
	pincnfg.GPIO_PIN_MODE = GPIO_PUSHPULL_OUTPUT;
	MCAL_GPIO_INIT(LCD_CTRL, &pincnfg);

	pincnfg.GPIO_PIN_NUMBER = GPIO_PIN5;
	pincnfg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_10MHz;
	pincnfg.GPIO_PIN_MODE = GPIO_PUSHPULL_OUTPUT;
	MCAL_GPIO_INIT(LCD_CTRL, &pincnfg);

	pincnfg.GPIO_PIN_NUMBER = GPIO_PIN6;
	pincnfg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_10MHz;
	pincnfg.GPIO_PIN_MODE = GPIO_PUSHPULL_OUTPUT;
	MCAL_GPIO_INIT(LCD_CTRL, &pincnfg);

	pincnfg.GPIO_PIN_NUMBER = GPIO_PIN7;
	pincnfg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_10MHz;
	pincnfg.GPIO_PIN_MODE = GPIO_PUSHPULL_OUTPUT;
	MCAL_GPIO_INIT(LCD_CTRL, &pincnfg);





	//	DataDir_LCD_CTRL |= (1 << EN_SWITCH | 1 << RS_SWITCH | 1 << RW_SWITCH);
	MCAL_GPIO_WRITE_PIN(LCD_CTRL, RS_SWITCH,GPIO_PIN_true );
	MCAL_GPIO_WRITE_PIN(LCD_CTRL, RW_SWITCH,GPIO_PIN_true );
	MCAL_GPIO_WRITE_PIN(LCD_CTRL, EN_SWITCH,GPIO_PIN_true );

}

void LCD_clear_screen() {
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}

void LCD_lcd_kick() {
	MCAL_GPIO_WRITE_PIN(LCD_CTRL,EN_SWITCH,GPIO_PIN_true);
	delay_ms(50);
	MCAL_GPIO_WRITE_PIN(LCD_CTRL,EN_SWITCH,GPIO_PIN_false);
}

void LCD_GOTO_XY(unsigned char line, unsigned char position) {
	if (line == 1) {
		if (position < 16 && position >= 0) {
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW + position);
		}
	}
	if (line == 2) {
		if (position < 16 && position >= 0) {
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW + position);
		}
	}
}

void LCD_INIT() {

	delay_ms(20);
	// SET THE FIRST 3 PINS AS OUPUT
	LCD_GPIO_init();
//	LCD_CTRL &= ~(1 << EN_SWITCH | 1 << RS_SWITCH | 1 << RW_SWITCH);
//	DataDir_LCD_PORT = 0xFF;
	delay_ms(15);

	LCD_clear_screen();
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
}

void LCD_check_lcd_isbusy() {
//	DataDir_LCD_PORT &= ~(0xFF << DATA_shift);


	pincnfg.GPIO_PIN_MODE = GPIO_FLOATING_INPUT;
	pincnfg.GPIO_PIN_NUMBER = GPIO_PIN0;
	MCAL_GPIO_INIT(LCD_CTRL, &pincnfg);

	pincnfg.GPIO_PIN_MODE = GPIO_FLOATING_INPUT;
	pincnfg.GPIO_PIN_NUMBER = GPIO_PIN1;
	MCAL_GPIO_INIT(LCD_CTRL, &pincnfg);

	pincnfg.GPIO_PIN_MODE = GPIO_FLOATING_INPUT;
	pincnfg.GPIO_PIN_NUMBER = GPIO_PIN2;
	MCAL_GPIO_INIT(LCD_CTRL, &pincnfg);

	pincnfg.GPIO_PIN_MODE = GPIO_FLOATING_INPUT;
	pincnfg.GPIO_PIN_NUMBER = GPIO_PIN3;
	MCAL_GPIO_INIT(LCD_CTRL, &pincnfg);

	pincnfg.GPIO_PIN_MODE = GPIO_FLOATING_INPUT;
	pincnfg.GPIO_PIN_NUMBER = GPIO_PIN4;
	MCAL_GPIO_INIT(LCD_CTRL, &pincnfg);

	pincnfg.GPIO_PIN_MODE = GPIO_FLOATING_INPUT;
	pincnfg.GPIO_PIN_NUMBER = GPIO_PIN5;
	MCAL_GPIO_INIT(LCD_CTRL, &pincnfg);

	pincnfg.GPIO_PIN_MODE = GPIO_FLOATING_INPUT;
	pincnfg.GPIO_PIN_NUMBER = GPIO_PIN6;
	MCAL_GPIO_INIT(LCD_CTRL, &pincnfg);

	pincnfg.GPIO_PIN_MODE = GPIO_FLOATING_INPUT;
	pincnfg.GPIO_PIN_NUMBER = GPIO_PIN7;
	MCAL_GPIO_INIT(LCD_CTRL, &pincnfg);






	MCAL_GPIO_WRITE_PIN(LCD_CTRL, RW_SWITCH, GPIO_PIN_true);
	MCAL_GPIO_WRITE_PIN(LCD_CTRL, RS_SWITCH, GPIO_PIN_false);
//	LCD_CTRL |= (1 << RW_SWITCH);
//	LCD_CTRL &= ~(1 << RS_SWITCH);
	LCD_lcd_kick();
//	DataDir_LCD_PORT |= (0xFF << DATA_shift);
	MCAL_GPIO_WRITE_PIN(LCD_CTRL, RW_SWITCH, GPIO_PIN_false);
//	LCD_CTRL &= ~(1 << RW_SWITCH);

}

void LCD_WRITE_COMMAND(unsigned char command) {
//	LCD_check_lcd_isbusy();
	MCAL_GPIO_WRITE_PORT(LCD_CTRL, command);
//	LCD_CTRL->BRR = (LCD_CTRL->BRR & 0x00FF) | (command);
//	LCD_CTRL->CRL ^= (LCD_CTRL->CRL ^ command) & 0x00ff;
//	LCD_CTRL->CRL = command;
//	LCD_CTRL ^= (LCD_CTRL-> ^ command) & 0x00ff;
	MCAL_GPIO_WRITE_PIN(LCD_CTRL, RW_SWITCH, GPIO_PIN_false);
	MCAL_GPIO_WRITE_PIN(LCD_CTRL, RS_SWITCH, GPIO_PIN_false);
//	LCD_CTRL &= ~((1 << RS_SWITCH) | (1<<RW_SWITCH));
	delay_ms(1);
	LCD_lcd_kick();

}

void LCD_WRITE_CHAR(unsigned char character) {
//	LCD_check_lcd_isbusy();
//	LCD_CTRL->CRL = character;
//	LCD_CTRL->CRL ^= (LCD_CTRL->CRL ^ character) & 0x00ff;
	MCAL_GPIO_WRITE_PORT(LCD_CTRL, character);
//	LCD_CTRL ^= (LCD_CTRL ^ character) & 0x00ff;
	MCAL_GPIO_WRITE_PIN(LCD_CTRL, RW_SWITCH, GPIO_PIN_false);
	MCAL_GPIO_WRITE_PIN(LCD_CTRL, RS_SWITCH, GPIO_PIN_true);
//	LCD_CTRL &= ~(1 << RW_SWITCH);
//	LCD_CTRL |= (1 << RS_SWITCH);
	delay_ms(1);
	LCD_lcd_kick();
}

void LCD_WRITE_STRING(char *string) {
	int count = 0;
	while (*string > 0) {
		count++;
		LCD_WRITE_CHAR(*string++);
		if (count == 16) {
			LCD_GOTO_XY(2, 0);
		} else if (count == 32) {
			LCD_clear_screen();
			LCD_GOTO_XY(1, 0);
			count = 0;
		}
	}
}
