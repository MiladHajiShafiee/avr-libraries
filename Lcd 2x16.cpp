/*
 * IOComponents.cpp
 *
 * Created: 2018/07/08 9:08:49
 *  Author: Milad
 */		


#include "Lcd 2x16.h"


void Lcd_8_BitMode::LcdCommand(unsigned char cmnd)
{
	LCD_Data_Port= cmnd;
	LCD_Command_Port &= ~(1 << RS);																			/* RS=0 command reg. */
	LCD_Command_Port &= ~(1 << RW);																			/* RW=0 Write operation */
	LCD_Command_Port |= (1 << EN);																			/* Enable pulse */
	_delay_us(1);
	LCD_Command_Port &= ~(1 << EN);
	_delay_ms(3);
}

void Lcd_8_BitMode::LcdInit (void)
{
		LCD_Command_Dir = 0xFF;																				/* Make LCD command port direction as o/p */
	 	LCD_Data_Dir = 0xFF;																				/* Make LCD data port direction as o/p */
	 	_delay_ms(20);																						/* LCD Power ON delay always >15ms */
	
		LcdCommand (0x38);																					/* Initialization of 16X2 LCD in 8bit mode */
	 	LcdCommand (0x0C);																					/* Display ON Cursor OFF */
	 	LcdCommand (0x06);																					/* Auto Increment cursor */
		LcdCommand (0x01);																					/* clear display */
	 	LcdCommand (0x80);																					/* Cursor at home position */
}

void Lcd_8_BitMode::LcdChar (unsigned char char_data)
{
	LCD_Data_Port = char_data;
	LCD_Command_Port |= (1 << RS);																			/* RS=1 Data reg. */
	LCD_Command_Port &= ~(1 << RW);																			/* RW=0 write operation */
	LCD_Command_Port |= (1 << EN);																			/* Enable Pulse */
	_delay_us(1);
	LCD_Command_Port &= ~(1 << EN);
	_delay_ms(1);																							/* Data write delay */
}

uint8_t Lcd_8_BitMode::LcdString (char *str)
{
	int i;
	for(i = 0 ; str[i] != 0; i++)																			/* Send each char of string till the NULL */
	{
		LcdChar (str[i]);
	}
	return i;
}

void Lcd_8_BitMode::LcdNum (uint16_t num, BaseWords base)
{
	char String[33];
	switch (base)
	{
		case binary:
		itoa(num, String, 2);
		break;
		case octal:
		itoa(num, String, 8);
		break;
		case decimal:
		itoa(num, String, 10);
		break;
		case hexadecimal:
		itoa(num, String, 16);
		LcdString("0x");
		break;
	}
	LcdString(String);
}

void Lcd_8_BitMode::LcdStringXy (unsigned char row, unsigned char pos, char *str)
{
	if (row == 0 && (pos < 16))
	LcdCommand((pos & 0x0F)|0x80);																			/* Command of first row and required position<16 */
	else if (row == 1 && (pos < 16))
	LcdCommand((pos & 0x0F)|0xC0);																			/* Command of first row and required position<16 */
	LcdString(str);																							/* Call LCD string function */																				
}

void Lcd_8_BitMode::LcdGoXy (unsigned char row, unsigned char pos)
{
	if (row == 0 && (pos < 16))
	LcdCommand((pos & 0x0F)|0x80);																			/* Command of first row and required position<16 */
	else if (row == 1 && (pos < 16))
	LcdCommand((pos & 0x0F)|0xC0);																			/* Command of first row and required position<16 */
}

void Lcd_8_BitMode::LcdClear()
{
	LcdCommand (0x01);																						/* clear display */
	LcdCommand (0x80);																						/* cursor at home position */
}

void Lcd_8_BitMode::LcdCustomChar (unsigned char loc, unsigned char *msg)
{
	unsigned char i;
	if(loc < 8)
	{
		LcdCommand (0x40 + (loc * 8));																		/* Command 0x40 and onwards forces the device to point CGRAM address */
		for(i = 0 ; i < 8 ; i++)																			/* Write 8 byte for generation of 1 character */
		LcdChar(msg[i]);
	}
}



void Lcd_4_BitMode::LcdCommand( unsigned char cmnd )
{
	LCD_Port = (LCD_Port & 0x0F) | (cmnd & 0xF0);															/* sending upper nibble */
	LCD_Port &= ~ (1<<RS);																					/* RS=0, command reg. */
	LCD_Port |= (1<<EN);																					/* Enable pulse */
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);

	_delay_us(200);

	LCD_Port = (LCD_Port & 0x0F) | (cmnd << 4);																/* sending lower nibble */
	LCD_Port |= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);
	_delay_ms(2);
}

void Lcd_4_BitMode::LcdChar( unsigned char data )
{
	LCD_Port = (LCD_Port & 0x0F) | (data & 0xF0);															/* sending upper nibble */
	LCD_Port |= (1<<RS);																					/* RS=1, data reg. */
	LCD_Port|= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);
	_delay_us(200);
	LCD_Port = (LCD_Port & 0x0F) | (data << 4);																/* sending lower nibble */
	LCD_Port |= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);
	_delay_ms(2);
}

void Lcd_4_BitMode::LcdInit (void)
{
	LCD_Dir = 0xFF;																							/* Make LCD port direction as o/p */
	_delay_ms(20);																							/* LCD Power ON delay always >15ms */
	
	LcdCommand(0x02);																						/* send for 4 bit initialization of LCD  */
	LcdCommand(0x28);																					    /* 2 line, 5*7 matrix in 4-bit mode */
	LcdCommand(0x0c);																				        /* Display on cursor off*/
	LcdCommand(0x06);																						/* Increment cursor (shift cursor to right)*/
	LcdCommand(0x01);																					    /* Clear display screen*/
	_delay_ms(2);
}

uint8_t Lcd_4_BitMode::LcdString (char *str)
{
	int i;
	for(i = 0 ; str[i] != 0; i ++)																			/* Send each char of string till the NULL */
	{
		LcdChar (str[i]);
	}
	return i;
}

void Lcd_4_BitMode::LcdNum (uint16_t num, BaseWords base)
{
	char String[33];
	switch (base)
	{
		case binary:
		itoa(num, String, 2);
		break;
		case octal:
		itoa(num, String, 8);
		break;
		case decimal:
		itoa(num, String, 10);
		break;
		case hexadecimal:
		itoa(num, String, 16);
		LcdString("0x");
		break;
	}
	LcdString(String);
}

void Lcd_4_BitMode::LcdStringXy (unsigned char row,unsigned char pos, char *str)
{
	if (row == 0 && pos<16)
	LcdCommand((pos & 0x0F)|0x80);																			/* Command of first row and required position<16 */
	else if (row == 1 && pos<16)
	LcdCommand((pos & 0x0F)|0xC0);																			/* Command of first row and required position<16 */
	LcdString(str);																							/* Call LCD string function */
}

void Lcd_4_BitMode::LcdGoXy (unsigned char row,unsigned char pos)
{
	if (row == 0 && pos<16)
	LcdCommand((pos & 0x0F)|0x80);																			/* Command of first row and required position<16 */
	else if (row == 1 && pos<16)
	LcdCommand((pos & 0x0F)|0xC0);																			/* Command of first row and required position<16 */
}

void Lcd_4_BitMode::LcdClear()
{
	LcdCommand (0x01);																						/* Clear display */
	_delay_ms(2);
	LcdCommand (0x80);																						/* Cursor at home position */
}

void Lcd_4_BitMode::LcdCustomChar (unsigned char loc, unsigned char *msg)
{
	unsigned char i;
	if(loc < 8)
	{
		LcdCommand (0x40 + (loc * 8));																		/* Command 0x40 and onwards forces the device to point CGRAM address */
		for(i = 0 ; i < 8 ; i++)																			/* Write 8 byte for generation of 1 character */
		LcdChar(msg[i]);
	}
}
