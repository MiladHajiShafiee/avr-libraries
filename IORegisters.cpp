/*
 * IORegisters.cpp
 *
 * Created: 2018/07/08 8:28:18 
 *  Author: Milad
 */ 

#include <avr/io.h>
#include "IORegisters.h"


void Registers::DdrRegisters(unsigned char rName , unsigned int rBeginnerNum , unsigned int rEnderNum , unsigned int rSituation)
{
	
	switch (rName)
	{
		case 'A' :
			switch (rSituation)
			{
				case 1 :
					for (unsigned int counter = rBeginnerNum ; counter <= rEnderNum ; counter ++)
					{
						DDRA |= (1 << counter);
					}
					break;
				case 0 :
					for (unsigned int counter = rBeginnerNum ; counter <= rEnderNum ; counter ++)
					{
						DDRA &= ~(1 << counter);
					}
					break;
			}
			break;
	
		case 'B' :
			switch (rSituation)
			{
				case 1 :
					for (unsigned int counter = rBeginnerNum ; counter <= rEnderNum ; counter ++)
					{
						DDRB |= (1 << counter);
					}
					break;
				case 0 :
					for (unsigned int counter = rBeginnerNum ; counter <= rEnderNum ; counter ++)
					{
						DDRB &= ~(1 << counter);
					}
					break;
			}
			break;
	
		case 'C' :
			switch (rSituation)
			{
				case 1 :
					for (unsigned int counter = rBeginnerNum ; counter <= rEnderNum ; counter ++)
					{
						DDRC |= (1 << counter);
					}
					break;
				case 0 :
					for (unsigned int counter = rBeginnerNum ; counter <= rEnderNum ; counter ++)
					{
						DDRC &= ~(1 << counter);
					}
					break;
			}
			break;
	
		case 'D' :
			switch (rSituation)
			{
				case 1 :
					for (unsigned int counter = rBeginnerNum ; counter <= rEnderNum ; counter ++)
					{
						DDRD |= (1 << counter);
					}
					break;
				case 0 :
					for (unsigned int counter = rBeginnerNum ; counter <= rEnderNum ; counter ++)
					{
						DDRD &= ~(1 << counter);
					}
					break;
			}
			break;
	}
}

void Registers::DdrRegisters(unsigned char rName , unsigned int rNum , unsigned int rSituation)
{
	switch (rName)
	{
		case 'A' :
			switch (rSituation)
			{
				case 1 :
					DDRA |= (1 << rNum);
					break;
				case 0 :
					DDRA &= ~(1 << rNum);
					break;
			}
			break;
			
		case 'B' :
			switch (rSituation)
			{
				case 1 :
					DDRB |= (1 << rNum);
					break;
				case 0 :
					DDRB &= ~(1 << rNum);
					break;
			}
			break;
			
		case 'C' :
			switch (rSituation)
			{
				case 1 :
					DDRC |= (1 << rNum);
					break;
				case 0 :
					DDRC &= ~(1 << rNum);
					break;
			}
			break;
			
		case 'D' :
			switch (rSituation)
			{
				case 1 :
					DDRD |= (1 << rNum);
					break;
				case 0 :
					DDRD &= ~(1 << rNum);
					break;
			}
			break;
	}
}

void Registers::DdrRegisters(unsigned char rName , unsigned int rSituation)
{
	switch (rName)
	{
		case 'A' :
			switch (rSituation)
			{
				case 1 :
					for (unsigned int counter = 0 ; counter <= 7 ; counter ++)
					{
						DDRA |= (1 << counter);
					}
					break;
				case 0 :
					for (unsigned int counter = 0 ; counter <= 7 ; counter ++)
					{
						DDRA &= ~(1 << counter);
					}
					break;
			}
			break;
		
		case 'B' :
			switch (rSituation)
			{
				case 1 :
					for (unsigned int counter = 0 ; counter <= 7 ; counter ++)
					{
						DDRB |= (1 << counter);
					}
					break;
				case 0 :
					for (unsigned int counter = 0 ; counter <= 7 ; counter ++)
					{
						DDRB &= ~(1 << counter);
					}
					break;
			}
			break;
		
		case 'C' :
			switch (rSituation)
			{
				case 1 :
					for (unsigned int counter = 0 ; counter <= 7 ; counter ++)
					{
						DDRC |= (1 << counter);
					}
					break;
				case 0 :
					for (unsigned int counter = 0 ; counter <= 7 ; counter ++)
					{
						DDRC &= ~(1 << counter);
					}
					break;
			}
			break;
		
		case 'D' :
			switch (rSituation)
			{
				case 1 :
					for (unsigned int counter = 0 ; counter <= 7 ; counter ++)
					{
						DDRD |= (1 << counter);
					}
					break;
				case 0 :
					for (unsigned int counter = 0 ; counter <= 7 ; counter ++)
					{
						DDRD &= ~(1 << counter);
					}
					break;
			}
			break;
	}
}


void Registers::PortRegisters(unsigned char rName , unsigned int rBeginnerNum , unsigned int rEnderNum , unsigned int rSituation)
{
	switch (rName)
	{
		case 'A' :
		switch (rSituation)
		{
			case 1 :
			for (unsigned int counter = rBeginnerNum ; counter <= rEnderNum ; counter ++)
			{
				PORTA |= (1 << counter);
			}
			break;
			case 0 :
			for (unsigned int counter = rBeginnerNum ; counter <= rEnderNum ; counter ++)
			{
				PORTA &= ~(1 << counter);
			}
			break;
		}
		break;
		
		case 'B' :
		switch (rSituation)
		{
			case 1 :
			for (unsigned int counter = rBeginnerNum ; counter <= rEnderNum ; counter ++)
			{
				PORTB |= (1 << counter);
			}
			break;
			case 0 :
			for (unsigned int counter = rBeginnerNum ; counter <= rEnderNum ; counter ++)
			{
				PORTB &= ~(1 << counter);
			}
			break;
		}
		break;
		
		case 'C' :
		switch (rSituation)
		{
			case 1 :
			for (unsigned int counter = rBeginnerNum ; counter <= rEnderNum ; counter ++)
			{
				PORTC |= (1 << counter);
			}
			break;
			case 0 :
			for (unsigned int counter = rBeginnerNum ; counter <= rEnderNum ; counter ++)
			{
				PORTC &= ~(1 << counter);
			}
			break;
		}
		break;
		
		case 'D' :
		switch (rSituation)
		{
			case 1 :
			for (unsigned int counter = rBeginnerNum ; counter <= rEnderNum ; counter ++)
			{
				PORTD |= (1 << counter);
			}
			break;
			case 0 :
			for (unsigned int counter = rBeginnerNum ; counter <= rEnderNum ; counter ++)
			{
				PORTD &= ~(1 << counter);
			}
			break;
		}
		break;
	}
}

void Registers::PortRegisters(unsigned char rName , unsigned int rNum , unsigned int rSituation)
{
	switch (rName)
	{
		case 'A' :
			switch (rSituation)
			{
				case 1 :
					PORTA |= (1 << rNum);
					break;
				case 0 :
					PORTA &= ~(1 << rNum);
					break;
			}
			break;
			
		case 'B' :
			switch (rSituation)
			{
				case 1 :
					PORTB |= (1 << rNum);
					break;
				case 0 :
					PORTB &= ~(1 << rNum);
					break;
			}
			break;
			
		case 'C' :
			switch (rSituation)
			{
				case 1 :
					PORTC |= (1 << rNum);
					break;
				case 0 :
					PORTC &= ~(1 << rNum);
					break;
			}
			break;
			
		case 'D' :
			switch (rSituation)
			{
				case 1 :
					PORTD |= (1 << rNum);
					break;
				case 0 :
					PORTD &= ~(1 << rNum);
					break;
			}
			break;
	}
}

void Registers::PortRegisters(unsigned char rName , unsigned int rSituation)
{
	switch (rName)
	{
		case 'A' :
			switch (rSituation)
			{
				case 1 :
					for (unsigned int counter = 0 ; counter <= 7 ; counter ++)
					{
						PORTA |= (1 << counter);
					}
					break;
				case 0 :
					for (unsigned int counter = 0 ; counter <= 7 ; counter ++)
					{
						PORTA &= ~(1 << counter);
					}
					break;
			}
			break;
		
		case 'B' :
			switch (rSituation)
			{
				case 1 :
					for (unsigned int counter = 0 ; counter <= 7 ; counter ++)
					{
						PORTB |= (1 << counter);
					}
					break;
				case 0 :
					for (unsigned int counter = 0 ; counter <= 7 ; counter ++)
					{
						PORTB &= ~(1 << counter);
					}
					break;
			}
			break;
		
		case 'C' :
			switch (rSituation)
			{
				case 1 :
					for (unsigned int counter = 0 ; counter <= 7 ; counter ++)
					{
						PORTC |= (1 << counter);
					}
					break;
				case 0 :
					for (unsigned int counter = 0 ; counter <= 7 ; counter ++)
					{
						PORTC &= ~(1 << counter);
					}
					break;
			}
			break;
		
		case 'D' :
			switch (rSituation)
			{
				case 1 :
					for (unsigned int counter = 0 ; counter <= 7 ; counter ++)
					{
						PORTD |= (1 << counter);
					}
					break;
				case 0 :
					for (unsigned int counter = 0 ; counter <= 7 ; counter ++)
					{
						PORTD &= ~(1 << counter);
					}
					break;
			}
			break;
	}
}
