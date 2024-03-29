/*
 * LCD.c
 *
 *  Created on: Jan 18, 2023
 *      Author: Belal
 */



#include "LCD.h"

void delay_ms(uint32_t time) {
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++)
			;
}

void LCD_INIT()
{
	PCFG->GPIO_PinNumber = EN_SWITCH;
	PCFG->GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	PCFG->GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, PCFG);

	PCFG->GPIO_PinNumber = RS_SWITCH;
	PCFG->GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	PCFG->GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, PCFG);

	PCFG->GPIO_PinNumber = RW_SWITCH;
	PCFG->GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	PCFG->GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, PCFG);

	delay_ms(50);

	PCFG->GPIO_PinNumber    = GPIO_PIN_0;
	PCFG->GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	PCFG->GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, PCFG);

	PCFG->GPIO_PinNumber    = GPIO_PIN_1;
	PCFG->GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	PCFG->GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, PCFG);

	PCFG->GPIO_PinNumber    = GPIO_PIN_2;
	PCFG->GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	PCFG->GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, PCFG);

	PCFG->GPIO_PinNumber    = GPIO_PIN_3;
	PCFG->GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	PCFG->GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, PCFG);

	PCFG->GPIO_PinNumber    = GPIO_PIN_4;
	PCFG->GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	PCFG->GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, PCFG);

	PCFG->GPIO_PinNumber    = GPIO_PIN_5;
	PCFG->GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	PCFG->GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, PCFG);

	PCFG->GPIO_PinNumber    = GPIO_PIN_6;
	PCFG->GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	PCFG->GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, PCFG);

	PCFG->GPIO_PinNumber    = GPIO_PIN_7;
	PCFG->GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	PCFG->GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, PCFG);

	//Clear screan
	//entry mode
	delay_ms(50);
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);

	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
	delay_ms(50);

}



void LCD_WRITE_COMMAND(unsigned char command)
{
	MCAL_GPIO_WritePort(LCD_CTRL, command);

	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);

	LCD_lcd_kick();

}
void LCD_WRITE_CHAR(unsigned char character)
{
	PCFG->GPIO_PinNumber    = GPIO_PIN_0;
	PCFG->GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	PCFG->GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, PCFG);

	PCFG->GPIO_PinNumber    = GPIO_PIN_1;
	PCFG->GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	PCFG->GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, PCFG);

	PCFG->GPIO_PinNumber    = GPIO_PIN_2;
	PCFG->GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	PCFG->GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, PCFG);

	PCFG->GPIO_PinNumber    = GPIO_PIN_3;
	PCFG->GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	PCFG->GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, PCFG);

	PCFG->GPIO_PinNumber    = GPIO_PIN_4;
	PCFG->GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	PCFG->GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, PCFG);

	PCFG->GPIO_PinNumber    = GPIO_PIN_5;
	PCFG->GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	PCFG->GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, PCFG);

	PCFG->GPIO_PinNumber    = GPIO_PIN_6;
	PCFG->GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	PCFG->GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, PCFG);

	PCFG->GPIO_PinNumber    = GPIO_PIN_7;
	PCFG->GPIO_MODE         = GPIO_MODE_OUTPUT_PP;
	PCFG->GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, PCFG);


	MCAL_GPIO_WritePort(LCD_CTRL, character);
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_SET);

	LCD_lcd_kick();

}
void LCD_WRITE_STRING(char* string)
{
	int count=0;
	while(*string > 0){
		count++;
		LCD_WRITE_CHAR(*string++);
		if(count ==16){
			LCD_GOTO_XY(1, 0);
		}
		if(count == 32 || count==33){
			LCD_clear_screen();
			LCD_GOTO_XY(0, 0);
			count=0;
		}
	}
}
void LCD_check_lcd_isbusy(void)
{
	PCFG->GPIO_PinNumber    = GPIO_PIN_0;
	PCFG->GPIO_MODE         = GPIO_MODE_INPUT_FLO;
	PCFG->GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, PCFG);

	PCFG->GPIO_PinNumber    = GPIO_PIN_1;
	PCFG->GPIO_MODE         = GPIO_MODE_INPUT_FLO;

	MCAL_GPIO_Init(LCD_CTRL, PCFG);

	PCFG->GPIO_PinNumber    = GPIO_PIN_2;
	PCFG->GPIO_MODE         = GPIO_MODE_INPUT_FLO;

	MCAL_GPIO_Init(LCD_CTRL, PCFG);

	PCFG->GPIO_PinNumber    = GPIO_PIN_3;
	PCFG->GPIO_MODE         = GPIO_MODE_INPUT_FLO;

	MCAL_GPIO_Init(LCD_CTRL, PCFG);

	PCFG->GPIO_PinNumber    = GPIO_PIN_4;
	PCFG->GPIO_MODE         = GPIO_MODE_INPUT_FLO;

	MCAL_GPIO_Init(LCD_CTRL, PCFG);

	PCFG->GPIO_PinNumber    = GPIO_PIN_5;
	PCFG->GPIO_MODE         = GPIO_MODE_INPUT_FLO;

	MCAL_GPIO_Init(LCD_CTRL, PCFG);

	PCFG->GPIO_PinNumber    = GPIO_PIN_6;
	PCFG->GPIO_MODE         = GPIO_MODE_INPUT_FLO;

	MCAL_GPIO_Init(LCD_CTRL, PCFG);

	PCFG->GPIO_PinNumber    = GPIO_PIN_7;
	PCFG->GPIO_MODE         = GPIO_MODE_INPUT_FLO;

	MCAL_GPIO_Init(LCD_CTRL, PCFG);


	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_SET);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);
	LCD_lcd_kick();
}
void LCD_lcd_kick(void)
{
	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_SET);
	delay_ms(50);
	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_RESET);

}

void LCD_clear_screen()
{
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}
void LCD_GOTO_XY(unsigned char line, unsigned char position)
{
	if(line == 0)
	{
		if(position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW + position);
		}
	}

	if(line == 1)
	{
		if(position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW + position);
		}
	}
}
