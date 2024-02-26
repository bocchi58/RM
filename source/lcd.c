/*
 * lcd.c
 *
 *  Created on: 2024年2月19日
 *      Author: 86155
 */
#include "lcd.h"
#include "fsl_gpio.h"
#include "peripherals.h"

void Delayms(uint16_t t)
{
	uint16_t tt,ttt;
	for(tt=0;tt<t;tt++)
	{
		for(ttt=0;ttt<250;ttt++);
	}

}
/********************************************************/
//清屏函数
/********************************************************/
void LCD_ClearScreen(void)
{

}
/********************************************************/
//
/********************************************************/
void LCD_WriteCommand(uint32_t command)
{
	GPIO_PinWrite(LCD_A0_GPIO,LCD_A0_PIN,0);  //表示发送命令
	LPSPI_WriteData(LPSPI4,command);
	//SPI通信
}
/********************************************************/
//
/********************************************************/
void LCD_WriteData(uint32_t data)
{
	GPIO_PinWrite(LCD_A0_GPIO,LCD_A0_PIN,1);  //表示发送数据
	LPSPI_WriteData(LPSPI4, data);
	//SPI通信
}
void LCD_Init(void)
{
//------------------------------------ST7735R Reset Sequence-----------------------------------------//
		//RES =1;
		GPIO_PinWrite(LCD_RES_GPIO,LCD_RES_PIN,1);
		Delayms (1);                                                              //Delay 1ms
		//RES =0;
		GPIO_PinWrite(LCD_RES_GPIO,LCD_RES_PIN,0);
		Delayms (1);                                                              //Delay 1ms
		//RES =1;
		GPIO_PinWrite(LCD_RES_GPIO,LCD_RES_PIN,1);
		Delayms (120);                                                              //Delay 120ms
//--------------------------------End ST7735R Reset Sequence --------------------------------------//
//--------------------------------End ST7735S Reset Sequence --------------------------------------//
		LCD_WriteCommand(0x11); //Sleep out
		Delayms(120);              //Delay 120ms
		//------------------------------------ST7735S Frame Rate-----------------------------------------//
		LCD_WriteCommand(0xB1);
		LCD_WriteData(0x05);
		LCD_WriteData(0x3C);
		LCD_WriteData(0x3C);
		LCD_WriteCommand(0xB2);
		LCD_WriteData(0x05);
		LCD_WriteData(0x3C);
		LCD_WriteData(0x3C);
		LCD_WriteCommand(0xB3);
		LCD_WriteData(0x05);
		LCD_WriteData(0x3C);
		LCD_WriteData(0x3C);
		LCD_WriteData(0x05);
		LCD_WriteData(0x3C);
		LCD_WriteData(0x3C);
		//------------------------------------End ST7735S Frame Rate---------------------------------//
		LCD_WriteCommand(0xB4); //Dot inversion
		LCD_WriteData(0x03);
		//------------------------------------ST7735S Power Sequence---------------------------------//
		LCD_WriteCommand(0xC0);
		LCD_WriteData(0x28);
		LCD_WriteData(0x08);
		LCD_WriteData(0x04);
		LCD_WriteCommand(0xC1);
		LCD_WriteData(0XC0);
		LCD_WriteCommand(0xC2);
		LCD_WriteData(0x0D);
		LCD_WriteData(0x00);
		LCD_WriteCommand(0xC3);
		LCD_WriteData(0x8D);
		LCD_WriteData(0x2A);
		LCD_WriteCommand(0xC4);
		LCD_WriteData(0x8D);
		LCD_WriteData(0xEE);
		//---------------------------------End ST7735S Power Sequence-------------------------------------//
		LCD_WriteCommand(0xC5); //VCOM
		LCD_WriteData(0x18);
		LCD_WriteCommand(0x36); //MX, MY, RGB mode
		LCD_WriteData(0xC0);
		//------------------------------------ST7735S Gamma Sequence---------------------------------//
		LCD_WriteCommand(0xE0);
		LCD_WriteData(0x04);
		LCD_WriteData(0x22);
		LCD_WriteData(0x07);
		LCD_WriteData(0x0A);
		LCD_WriteData(0x2E);
		LCD_WriteData(0x30);
		LCD_WriteData(0x25);
		LCD_WriteData(0x2A);
		LCD_WriteData(0x28);
		LCD_WriteData(0x26);
		LCD_WriteData(0x2E);
		LCD_WriteData(0x3A);
		LCD_WriteData(0x00);
		LCD_WriteData(0x01);
		LCD_WriteData(0x03);
		LCD_WriteData(0x13);
		LCD_WriteCommand(0xE1);
		LCD_WriteData(0x04);
		LCD_WriteData(0x16);
		LCD_WriteData(0x06);
		LCD_WriteData(0x0D);
		LCD_WriteData(0x2D);
		LCD_WriteData(0x26);
		LCD_WriteData(0x23);
		LCD_WriteData(0x27);
		LCD_WriteData(0x27);
		LCD_WriteData(0x25);
		LCD_WriteData(0x2D);
		LCD_WriteData(0x3B);
		LCD_WriteData(0x00);
		LCD_WriteData(0x01);
		LCD_WriteData(0x04);
		LCD_WriteData(0x13);
		//------------------------------------End ST7735S Gamma Sequence-----------------------------//
		LCD_WriteCommand(0x3A); //65k mode
		LCD_WriteData(0x05);
		LCD_WriteCommand(0x29); //Display on

}
//// 定义 LCD 初始化函数
//void  ST7735S_LAIBAO177_INITIAL ()
//
//{
////------------------------------------ST7735R Reset Sequence-----------------------------------------//
//	//RES =1;
//	GPIO_PinWrite(LCD_RES_GPIO,LCD_RES_PIN,1);
//	Delayms (1);                                                              //Delay 1ms
//	//RES =0;
//	GPIO_PinWrite(LCD_RES_GPIO,LCD_RES_PIN,0);
//	Delayms (1);                                                              //Delay 1ms
//	//RES =1;
//	GPIO_PinWrite(LCD_RES_GPIO,LCD_RES_PIN,1);
//	Delayms (120);                                                              //Delay 120ms
////--------------------------------End ST7735R Reset Sequence --------------------------------------//
//
////--------------------------------End ST7735S Reset Sequence --------------------------------------//
//LCD_WriteCommand(0x11); //Sleep out
//Delayms(120);              //Delay 120ms
////------------------------------------ST7735S Frame Rate-----------------------------------------//
//LCD_WriteCommand(0xB1);
//LCD_WriteData(0x05);
//LCD_WriteData(0x3C);
//LCD_WriteData(0x3C);
//LCD_WriteCommand(0xB2);
//LCD_WriteData(0x05);
//LCD_WriteData(0x3C);
//LCD_WriteData(0x3C);
//LCD_WriteCommand(0xB3);
//LCD_WriteData(0x05);
//LCD_WriteData(0x3C);
//LCD_WriteData(0x3C);
//LCD_WriteData(0x05);
//LCD_WriteData(0x3C);
//LCD_WriteData(0x3C);
////------------------------------------End ST7735S Frame Rate---------------------------------//
//LCD_WriteCommand(0xB4); //Dot inversion
//LCD_WriteData(0x03);
////------------------------------------ST7735S Power Sequence---------------------------------//
//LCD_WriteCommand(0xC0);
//LCD_WriteData(0x28);
//LCD_WriteData(0x08);
//LCD_WriteData(0x04);
//LCD_WriteCommand(0xC1);
//LCD_WriteData(0XC0);
//LCD_WriteCommand(0xC2);
//LCD_WriteData(0x0D);
//LCD_WriteData(0x00);
//LCD_WriteCommand(0xC3);
//LCD_WriteData(0x8D);
//LCD_WriteData(0x2A);
//LCD_WriteCommand(0xC4);
//LCD_WriteData(0x8D);
//LCD_WriteData(0xEE);
////---------------------------------End ST7735S Power Sequence-------------------------------------//
//LCD_WriteCommand(0xC5); //VCOM
//LCD_WriteData(0x18);
//LCD_WriteCommand(0x36); //MX, MY, RGB mode
//LCD_WriteData(0xC0);
////------------------------------------ST7735S Gamma Sequence---------------------------------//
//LCD_WriteCommand(0xE0);
//LCD_WriteData(0x04);
//LCD_WriteData(0x22);
//LCD_WriteData(0x07);
//LCD_WriteData(0x0A);
//LCD_WriteData(0x2E);
//LCD_WriteData(0x30);
//LCD_WriteData(0x25);
//LCD_WriteData(0x2A);
//LCD_WriteData(0x28);
//LCD_WriteData(0x26);
//LCD_WriteData(0x2E);
//LCD_WriteData(0x3A);
//LCD_WriteData(0x00);
//LCD_WriteData(0x01);
//LCD_WriteData(0x03);
//LCD_WriteData(0x13);
//LCD_WriteCommand(0xE1);
//LCD_WriteData(0x04);
//LCD_WriteData(0x16);
//LCD_WriteData(0x06);
//LCD_WriteData(0x0D);
//LCD_WriteData(0x2D);
//LCD_WriteData(0x26);
//LCD_WriteData(0x23);
//LCD_WriteData(0x27);
//LCD_WriteData(0x27);
//LCD_WriteData(0x25);
//LCD_WriteData(0x2D);
//LCD_WriteData(0x3B);
//LCD_WriteData(0x00);
//LCD_WriteData(0x01);
//LCD_WriteData(0x04);
//LCD_WriteData(0x13);
////------------------------------------End ST7735S Gamma Sequence-----------------------------//
//LCD_WriteCommand(0x3A); //65k mode
//LCD_WriteData(0x05);
//LCD_WriteCommand(0x29); //Display on
//
//}
