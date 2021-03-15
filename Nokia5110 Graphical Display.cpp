/*
 * Nokia5110_Graphical_Display.cpp
 *
 * Created: 2018/08/24 8:52:42
 *  Author: Milad
 */ 

#include "Nokia5110 Graphical Display.h"


void NokiaDisplay::Command(char DATA)
{
	PORTB &= ~(1 << DC);												/* make DC pin to logic zero for command operation */
	spi.SSEnable();														/* enable SS pin to slave selection */
	spi.Write(DATA);													/* send data on data register */
	PORTB |= (1 << DC);													/* make DC pin to logic high for data operation */
	spi.SSDisable();
}

void NokiaDisplay::Print(char *DATA)
{
	PORTB |= (1 << DC);													/* make DC pin to logic high for data operation */
	spi.SSEnable();														/* enable SS pin to slave selection */
	int lenan = strlen(DATA);											/* measure the length of data */
	for (uint8_t g = 0; g < lenan; g++)
	{
		for (uint8_t index = 0; index < 5; index++)
		{
			spi.Write(ASCII[DATA[g] - 0x20][index]);					/* send the data on data register */
		}
		spi.Write(0x00);
	}
	spi.SSDisable();
}

void NokiaDisplay::Reset()												/* reset the Display at the beginning of initialization */
{
	PORTB &= ~(1 << RST);
	_delay_ms(100);
	PORTB |= (1 << RST);
}

void NokiaDisplay::Init()
{
	Reset();															/* reset the display */
	Command(0x21);														/* command set in addition mode */
	Command(0xC0);														/* set the voltage by sending C0 means VOP = 5V */
	Command(0x07);														/* set the temp. coefficient to 3 */
	Command(0x13);														/* set value of Voltage Bias System */
	Command(0x20);														/* command set in basic mode */
	Command(0x0C);														/* display result in normal mode */
}

void NokiaDisplay::SetXy(char x, char y)								/* set the column and row */
{
	Command(x);
	Command(y);
}

void NokiaDisplay::Clear()												/* clear the Display */
{
	spi.SSEnable();
	PORTB |= (1 << DC);
	for (uint16_t k = 0; k <= 503; k++)
	{
		spi.Write(0x00);
	}
	PORTB &= ~(1 << DC);
	spi.SSDisable();
}

void NokiaDisplay::Image(const unsigned char *image_data)				/* clear the Display */
{
	spi.SSEnable();
	PORTB |= (1 << DC);
	for (uint16_t k = 0; k <= 503; k++)
	{
		spi.Write(image_data[k]);
	}
	PORTB &= ~(1 << DC);
	spi.SSDisable();
}