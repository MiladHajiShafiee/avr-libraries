/*
 * Usart.cpp
 *
 * Created: 2018/07/31 8:03:34
 *  Author: Milad
 */ 

#define F_CPU 8000000UL


#include "Usart.h"


void USART::UsartInit(unsigned long int desiredBaudRate , unsigned int characterSize  , bool interrupt)
{
	unsigned int UbbrValue;
	if(interrupt)
	{
		UCSRB |= (1 << RXCIE);
	}
	UCSRB |= (1 << RXEN) | (1 << TXEN);
	UCSRC |= (1 << URSEL);
	switch (characterSize)
	{
		case 5:
			UCSRC &= ~(1 << UCSZ0);
			UCSRC &= ~(1 << UCSZ1);
		break;
		case 6:
			UCSRC |= (1 << UCSZ0);
			UCSRC &= ~(1 << UCSZ1);
		break;
		case 7:
			UCSRC |= (1 << UCSZ1);
			UCSRC &= ~(1 << UCSZ0);
		break;
		case 8:
			UCSRC = (1 << UCSZ0)|(1 << UCSZ1);
		break;
		case 9:
			UCSRC = (1 << UCSZ0)|(1 << UCSZ1)|(1 << UCSZ2);
		break;
	}
	
	UbbrValue = F_CPU / (desiredBaudRate * 16UL) - 1;
	
	UBRRL = UbbrValue;
	UBRRH = (UbbrValue >> 8);
}

void USART::UsartTransmiter(unsigned char character)
{
	while (! (UCSRA & (1<<UDRE)));
	UDR = character;
}

unsigned char USART::UsartReciever(void)
{
	while ((UCSRA & (1 << RXC)) == 0);
	return UDR;
}

void USART::UsartStringTransmiter(char *str)
{
	
	unsigned char i = 0;
	
	while (str[i] != 0)
	{
		UsartTransmiter(str[i]);
		i++;
	}
		
}
