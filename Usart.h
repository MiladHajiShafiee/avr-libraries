/*
 * Usart.h
 *
 * Created: 2018/07/31 8:03:52
 *  Author: Milad
 */ 


#ifndef USART_H_
#define USART_H_

#include <avr/io.h>
#include <avr/interrupt.h>

class USART
{
	public:
	
	void UsartInit(unsigned long int desiredBaudRate , unsigned int  characterSize , bool interrupt);
	
	void UsartTransmiter(unsigned char character);
	
	unsigned char UsartReciever(void);
	
	void UsartStringTransmiter(char *str);
	
	};


#endif /* USART_H_ */
