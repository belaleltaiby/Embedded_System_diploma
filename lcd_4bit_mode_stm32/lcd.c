/*
 * lcd.c
 *
 *  Created on: Feb 13, 2023
 *      Author: Belal
 */


#include "lcd.h"


#define timer htim1

extern TIM_HandleTypeDef timer;
void delay_mine (uint16_t us)
{
	__HAL_TIM_SET_COUNTER(&timer, 0);
	while (__HAL_TIM_GET_COUNTER(&timer) < us);
}




/******************************    4 bit mode *****************************************************************/
void lcd_init(void)
{
	delay_mine(20);

	HAL_GPIO_WritePin(RS_PORT, RS_PIN, 0);  // rs = 1 for data, rs=0 for command
	HAL_GPIO_WritePin(RS_PORT, RW_PIN, 0);
	delay_mine(10);
	HAL_GPIO_WritePin(EN_PORT, EN_PIN, 1);
	delay_mine (5);
	GPIOA->ODR &= 0xff0f;
	GPIOA->ODR |= 0x30 ;
	delay_mine(10);
	HAL_GPIO_WritePin(EN_PORT, EN_PIN, 0);


	delay_mine(10);

	HAL_GPIO_WritePin(RS_PORT, RS_PIN, 0);  // rs = 1 for data, rs=0 for command
	HAL_GPIO_WritePin(RS_PORT, RW_PIN, 0);
	delay_mine(10);
	HAL_GPIO_WritePin(EN_PORT, EN_PIN, 1);
	delay_mine (5);
	GPIOA->ODR &= 0xff0f;
	GPIOA->ODR |= 0x30 ;
	delay_mine(10);
	HAL_GPIO_WritePin(EN_PORT, EN_PIN, 0);

	delay_mine(1);

	HAL_GPIO_WritePin(RS_PORT, RS_PIN, 0);  // rs = 1 for data, rs=0 for command
	HAL_GPIO_WritePin(RS_PORT, RW_PIN, 0);
	delay_mine(10);
	HAL_GPIO_WritePin(EN_PORT, EN_PIN, 1);
	delay_mine (5);
	GPIOA->ODR &= 0xff0f;
	GPIOA->ODR |= 0x30 ;
	delay_mine(10);
	HAL_GPIO_WritePin(EN_PORT, EN_PIN, 0);

	delay_mine(1);

	HAL_GPIO_WritePin(RS_PORT, RS_PIN, 0);  // rs = 1 for data, rs=0 for command
	HAL_GPIO_WritePin(RS_PORT, RW_PIN, 0);
	delay_mine(10);
	HAL_GPIO_WritePin(EN_PORT, EN_PIN, 1);
	delay_mine (5);
	GPIOA->ODR &= 0xff0f;
	GPIOA->ODR |= 0x20 ;
	delay_mine(10);
	HAL_GPIO_WritePin(EN_PORT, EN_PIN, 0);


	lcd_send_cmd(0x2C);
	delay_mine(5);
	lcd_send_cmd(0x0C);
	delay_mine(5);
	lcd_send_cmd(0x01);
	delay_mine(5);
	lcd_send_cmd(0x02);
	delay_mine(5);
}




void lcd_send_cmd (char cmd)
{

	HAL_GPIO_WritePin(RS_PORT, RS_PIN, 0);  // rs = 1 for data, rs=0 for command
	HAL_GPIO_WritePin(RS_PORT, RW_PIN, 0);
	delay_mine(10);

	HAL_GPIO_WritePin(EN_PORT, EN_PIN, 1);
	delay_mine (5);
	GPIOA->ODR &= 0xff0f;
	GPIOA->ODR |= (cmd & 0x00f0);
	delay_mine(10);
	HAL_GPIO_WritePin(EN_PORT, EN_PIN, 0);

	delay_mine (20);

	HAL_GPIO_WritePin(EN_PORT, EN_PIN, 1);
	delay_mine (5);
	GPIOA->ODR &= 0xff0f;
	GPIOA->ODR |= ( (cmd << 4) & 0x00f0);
	delay_mine(10);
	HAL_GPIO_WritePin(EN_PORT, EN_PIN, 0);

}



void lcd_send_data (char data)
{

	HAL_GPIO_WritePin(RS_PORT, RS_PIN, 1);  // rs = 1 for data, rs=0 for command
	HAL_GPIO_WritePin(RS_PORT, RW_PIN, 0);
	delay_mine(10);
	HAL_GPIO_WritePin(EN_PORT, EN_PIN, 1);
	delay_mine (5);
	GPIOA->ODR &= 0xff0f;
	GPIOA->ODR |= (data & 0x00f0);
	delay_mine(10);
	HAL_GPIO_WritePin(EN_PORT, EN_PIN, 0);

	delay_mine (20);

	HAL_GPIO_WritePin(EN_PORT, EN_PIN, 1);
	delay_mine (5);
	GPIOA->ODR &= 0xff0f;
	GPIOA->ODR |= ( (data << 4) & 0x00f0);
	delay_mine(10);
	HAL_GPIO_WritePin(EN_PORT, EN_PIN, 0);

}

void lcd_put_cur(int row, int col)
{
	switch (row)
	{
	case 0:
		col |= 0x80;
		break;
	case 1:
		col |= 0xC0;
		break;
	}
	lcd_send_cmd (col);
}

/***********************/



//void LCD_init (void)
//{
//	// 4 bit initialisation
//	HAL_Delay(50);  // wait for >40ms
//	lcd_send_cmd (0x30);
//	HAL_Delay(5);  // wait for >4.1ms
//	lcd_send_cmd (0x30);
//	HAL_Delay(1);  // wait for >100us
//	lcd_send_cmd (0x30);
//	HAL_Delay(10);
//	lcd_send_cmd (0x20);  // 4bit mode
//	HAL_Delay(10);
//
//	// dislay initialisation
//	lcd_send_cmd (0x28); // Function set --> DL=0 (4 bit mode), N = 1 (2 line display) F = 0 (5x8 characters)
//	HAL_Delay(1);
//	lcd_send_cmd (0x08); //Display on/off control --> D=0,C=0, B=0  ---> display off
//	HAL_Delay(1);
//	lcd_send_cmd (0x01);  // clear display
//	HAL_Delay(1);
//	HAL_Delay(1);
//	lcd_send_cmd (0x06); //Entry mode set --> I/D = 1 (increment cursor) & S = 0 (no shift)
//	HAL_Delay(1);
//	lcd_send_cmd (0x0C); //Display on/off control --> D = 1, C and B = 0. (Cursor and blink, last two bits)
//}


void lcd_send_string(char str[])
{
	int i=0;
	while(str[i]){
		lcd_send_data(str[i]);
				i++;
				delay_mine(100);
	}
}

void lcd_clear()
{
	lcd_send_cmd(0x01);
	HAL_Delay(2);
}










