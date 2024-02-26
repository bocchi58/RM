/*
 * lcd.h
 *
 *  Created on: 2024年2月19日
 *      Author: 86155
 */

#ifndef LCD_H_
#define LCD_H_

#include "fsl_lpspi.h"
/* 定义 LCD 控制引脚 */
#define LCD_SCREEN_DC_GPIO GPIO_3
#define LCD_SCREEN_DC_PIN 4
#define LCD_RES_GPIO GPIO3
#define LCD_RES_PIN 7
#define LCD_CS_GPIO GPIO3
#define LCD_CS_PIN 1
#define LCD_A0_GPIO GPIO3
#define LCD_A0_PIN 4

void LCD_ClearScreen(void);
void Delayms(uint16_t t);
void LCD_WriteCommand(uint32_t command);
void LCD_WriteData(uint32_t data);
void LCD_Init(void);

#endif /* LCD_H_ */
