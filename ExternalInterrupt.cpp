/*
 * ExternalInterrupt.cpp
 *
 * Created: 2018/08/01 7:36:56
 *  Author: Milad
 */ 

#include "ExternalInterrupt.h"


void ExInterrupt::interrptInit(intReq R , trigSty T)
{
	switch (R)
	{
		case Int0:
		DDRD &= ~(1 << PD2);
		PORTD |= (1 << PD2);
		GICR |= (1 << INT0);
		switch (T)
		{
			case level:
			MCUCR &= ~(1 << ISC00);
			MCUCR &= ~(1 << ISC01);
			break;
			
			case anyTrigger:
			MCUCR |= (1 << ISC00);
			MCUCR &= ~(1 << ISC01);
			break;
			
			case fallingEdge:
			MCUCR &= ~(1 << ISC00);
			MCUCR |= (1 << ISC01);
			break;
			
			case risingEdge:
			MCUCR = (1 << ISC00)|(1 << ISC01);
			break;
		}
		break;
		
		case Int1:
		GICR |= (1 << INT1);
		DDRD &= ~(1 << 3);
		PORTD |= (1 << 3);
		switch (T)
		{
			case level:
			MCUCR &= ~(1 << ISC10);
			MCUCR &= ~(1 << ISC11);
			break;
			
			case anyTrigger:
			MCUCR |= (1 << ISC10);
			MCUCR &= ~(1 << ISC11);
			break;
			
			case fallingEdge:
			MCUCR &= ~(1 << ISC10);
			MCUCR |= (1 << ISC11);
			break;
			
			case risingEdge:
			MCUCR |= (1 << ISC10);
			MCUCR |= (1 << ISC11);
			break;
		}
		break;
		
		case Int2:
		GICR |= (1 << INT2);
		DDRB &= ~(1 << 2);
		PORTB |= (1 << 2);
		switch (T)
		{	
			case fallingEdge:
			MCUCR &= ~(1 << ISC2);
			break;
			
			case risingEdge:
			MCUCR |= (1 << ISC2);
			break;
		}
		break;
	}
	sei();
	while(1);
}
