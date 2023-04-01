/*
 * lcd.h
 *
 *  Created on: Feb 13, 2023
 *      Author: Belal
 */

#ifndef LCD_H_
#define LCD_H_


#include "stm32f1xx_hal.h"
#include "stm32f1xx.h"
#include "stm32f1xx_hal_cortex.h"
#include "stm32f1xx_hal_def.h"
#include "stm32_hal_legacy.h"
#include "stm32f1xx_hal_exti.h"
#include "stm32f1xx_hal_gpio.h"
#include "stm32f1xx_hal_gpio_ex.h"
#include "stm32f1xx_hal_rcc.h"
#include "stm32f1xx_hal_rcc_ex.h"
#include "stm32f1xx_hal_conf.h"
#include "stm32f1xx_hal_tim.h"
#include "stm32f1xx_hal_tim_ex.h"
#include "stm32f1xx_it.h"
#include "stm32f103x6.h"

/***********************/
/***4 bit mode***/
#define RS_PORT GPIOA
#define RS_PIN GPIO_PIN_1
#define RW_PORT GPIOA
#define RW_PIN GPIO_PIN_2
#define EN_PORT GPIOA
#define EN_PIN GPIO_PIN_3
#define D4_PORT GPIOA
#define D4_PIN GPIO_PIN_4
#define D5_PORT GPIOA
#define D5_PIN GPIO_PIN_5
#define D6_PORT GPIOA
#define D6_PIN GPIO_PIN_6
#define D7_PORT   GPIOA
#define D7_PIN  GPIO_PIN_7

#define timer htim1






/***************************/
#define LCD_CTRL       GPIOA
#define RS_SWITCH      GPIO_PIN_8
#define RW_SWITCH      GPIO_PIN_9
#define EN_SWITCH      GPIO_PIN_10

#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)


GPIO_InitTypeDef*  PCFG;




void lcd_init (void);
void lcd_put_cur(int row, int col);
void lcd_send_data (char data);
void lcd_send_cmd (char cmd);
void send_to_lcd (char data, int rs);
void lcd_send_string(char * str);
void lcd_clear(void);

void LCD_init  (void);
void lcd_send_string(char str[]);
#endif /* LCD_H_ */
