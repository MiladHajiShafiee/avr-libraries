/*
 * IOComponents.h
 *
 * Created: 2018/07/08 9:09:12
 *  Author: Milad
 */ 

#ifndef LCD 2X16_H_
#define LCD 2X16_H_

#include <stdlib.h>
#include <util/delay.h>
#include <avr/io.h>

//LCD 2*16 Alphabet Commands define
#define GoSecondLine 0xc0
#define CursorAtHomePosition 0x80
#define ShiftEntireRight 0x18
#define ShiftEntireLeft 0x1C
#define FuncSet_8_Bit 0x38
#define EntryMode 0x06
#define	DisplayOff_CursorOff 0x08																		/* clearing display without clearing DDRAM content*/
#define DisplayOn_CursorOn 0x0E
#define DisplayOn_CursorOff 0x0C
#define DisplayOn_CursorBlinking 0x0F
#define MoveCursorLeftByOneCharacter 0x10
#define MoveCursorRighttByOneCharacter 0x14
#define ClearDisplay 0x01																				/* also clear DDRAM content*/
// Set DDRAM address or cursor position on display	0x80 + address*
// Set CGRAM address or set pointer to CGRAM location	0x40 + address**

#define RS PD0																							/* Define Register Select signal pin */
#define RW PC1																							/* Define Read/Write signal pin */
#define EN PD1																							/* Define Enable signal pin */


enum BaseWords{
	decimal, binary,
	octal, hexadecimal,
	};


class CustomCharacters
{
	public:
	
	
	unsigned char Alef[8] = {
		0x01,
		0x1F,
		0x10,
		0x04,
		0x04,
		0x04,
		0x04,
		0x04
	};
	unsigned char Be[8] = {
		0x00,
		0x00,
		0x00,
		0x11,
		0x1F,
		0x00,
		0x04,
		0x00
	};
	unsigned char Pe[8] = {
		0x00,
		0x00,
		0x11,
		0x1F,
		0x00,
		0x0A,
		0x04,
		0x00
	};
	unsigned char Te[8] =  {
		0x00,
		0x00,
		0x00,
		0x0A,
		0x00,
		0x11,
		0x1F,
		0x00
	};
	
			
	};

class Lcd_8_BitMode
{
	
	#define LCD_Data_Dir DDRB																			/* Define LCD data port direction */
	#define LCD_Command_Dir DDRC																		/* Define LCD command port direction register */
	#define LCD_Data_Port PORTB																			/* Define LCD data port */
	#define LCD_Command_Port PORTC																		/* Define LCD data port */
	
	public:
	
	void LcdCommand(unsigned char cmnd);

	void LcdInit (void);
	
	void LcdChar (unsigned char char_data);

	uint8_t LcdString (char *str);
	
	void LcdNum (uint16_t num, BaseWords base);
	
	void LcdStringXy (unsigned char row,unsigned char pos,char *str);
	
	void LcdGoXy (unsigned char row,unsigned char pos);

	void LcdClear();
	
	void LcdCustomChar (unsigned char loc, unsigned char *msg);
	
	};

class Lcd_4_BitMode
{
	
	#define LCD_Dir  DDRD																				/* Define LCD data port direction */
	#define LCD_Port PORTD																				/* Define LCD data port */
	
	public:
	
	void LcdCommand( unsigned char cmnd );

	void LcdChar( unsigned char data );

	void LcdInit (void);

	uint8_t LcdString (char *str);
	
	void LcdNum (uint16_t num, BaseWords base);

	void LcdStringXy (unsigned char row,unsigned char pos,char *str);
	
	void LcdGoXy (unsigned char row,unsigned char pos);

	void LcdClear();
	
	void LcdCustomChar (unsigned char loc, unsigned char *msg);
	
	};
	
	
#endif /* LCD 2X16_H_ */
