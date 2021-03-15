/*
 * IOComponents.cpp
 *
 * Created: 2018/07/08 9:08:49
 *  Author: Milad
 */		

#include "IOComponents.h"

Registers keyRegisters;


void Button::InstanseEffectButton (unsigned char operatorPin , unsigned operatorPinNum , unsigned char operandPort ,unsigned int operandPortNum , bool capUse)
{
	
	keyRegisters.DdrRegisters(operatorPin , operatorPinNum , 0);
	keyRegisters.DdrRegisters(operandPort , operandPortNum , 1);
	
	switch (operatorPin)
	{
		case 'A':
			switch (capUse)
			{
				case true :
					if (!(PINA & (1 << operatorPinNum)))
					{
						keyRegisters.PortRegisters(operandPort , operandPortNum , 1);
					}
					else 
					{
						keyRegisters.PortRegisters(operandPort , operandPortNum , 0);
					}
					break;
		
				case false :
					if (!(PINA & (1 << operatorPinNum)))
					{
						keyRegisters.PortRegisters(operandPort , operandPortNum , 1);
						_delay_ms(200);
					}
					else 
					{
						keyRegisters.PortRegisters(operandPort , operandPortNum , 0);
					}
					break;
			}
			break;
			
		case 'B':
			switch (capUse)
			{
				case true :
					if (!(PINB & (1 << operatorPinNum)))
					{
						keyRegisters.PortRegisters(operandPort , operandPortNum , 1);
					}
					else 
					{
						keyRegisters.PortRegisters(operandPort , operandPortNum , 0);
					}
					break;
		
				case false :
					if (!(PINB & (1 << operatorPinNum)))
					{
						keyRegisters.PortRegisters(operandPort , operandPortNum , 1);
						_delay_ms(200);
					}
					else 
					{
						keyRegisters.PortRegisters(operandPort , operandPortNum , 0);
					}
					break;
			}
			break;
			
		case 'C':
			switch (capUse)
			{
				case true :
					if (!(PINC & (1 << operatorPinNum)))
					{
						keyRegisters.PortRegisters(operandPort , operandPortNum , 1);
					}
					else 
					{
						keyRegisters.PortRegisters(operandPort , operandPortNum , 0);
					}
					break;
		
				case false :
					if (!(PINC & (1 << operatorPinNum)))
					{
						keyRegisters.PortRegisters(operandPort , operandPortNum , 1);
						_delay_ms(200);
					}
					else 
					{
						keyRegisters.PortRegisters(operandPort , operandPortNum , 0);
					}
					break;
			}
			break;
			
		case 'D':
			switch (capUse)
			{
				case true :
					if (!(PIND & (1 << operatorPinNum)))
					{
						keyRegisters.PortRegisters(operandPort , operandPortNum , 1);
					}
					else 
					{
						keyRegisters.PortRegisters(operandPort , operandPortNum , 0);
					}
					break;
		
				case false :
					if (!(PIND & (1 << operatorPinNum)))
					{
						keyRegisters.PortRegisters(operandPort , operandPortNum , 1);
						_delay_ms(200);
					}
					else 
					{
						keyRegisters.PortRegisters(operandPort , operandPortNum , 0);
					}
					break;
			}
			break;
	}
	
}

void Button::ContinueousEffectButton (unsigned char operatorPin , unsigned operatorPinNum , unsigned char operandPort ,unsigned int operandPortNum , bool capUse)
{
	keyRegisters.DdrRegisters(operatorPin , operatorPinNum , 0);
	keyRegisters.DdrRegisters(operandPort , operandPortNum , 1);
	
	switch (operatorPin)
	{
		case 'A':
			switch (capUse)
			{
				case true :
					if (!(PINA & (1 << operatorPinNum)))
					{
						if (flag)
						{
							keyRegisters.PortRegisters(operandPort , operandPortNum , 1);
							start = !start;
							flag = false;
						}
					}
					else 
					{
						flag = true;
					}
					if (start)
					{
						keyRegisters.PortRegisters(operandPort , operandPortNum , 0);
					}
					break;
		
				case false :
					if (!(PINA & (1 << operatorPinNum)))
					{
						if (flag)
						{
							keyRegisters.PortRegisters(operandPort , operandPortNum , 1);
							_delay_ms(200);
							start = !start;
							flag = false;
						}
					}
					else 
					{
						flag = true;
					}
					if (start)
					{
						keyRegisters.PortRegisters(operandPort , operandPortNum , 0);
					}

					break;
			}
			break;
			
		case 'B':
			switch (capUse)
			{
				case true :
					if (!(PINB & (1 << operatorPinNum)))
					{
						if (flag)
						{
							keyRegisters.PortRegisters(operandPort , operandPortNum , 1);
							start = !start;
							flag = false;
						}
					}
					else 
					{
						flag = true;
					}
					if (start)
					{
						keyRegisters.PortRegisters(operandPort , operandPortNum , 0);
					}
					break;
		
				case false :
					if (!(PINB & (1 << operatorPinNum)))
					{
						if (flag)
						{
							keyRegisters.PortRegisters(operandPort , operandPortNum , 1);
							_delay_ms(200);
							start = !start;
							flag = false;
						}
					}
					else 
					{
						flag = true;
					}
					if (start)
					{
						keyRegisters.PortRegisters(operandPort , operandPortNum , 0);
					}

					break;
			}
			break;
			
		case 'C':
			switch (capUse)
			{
				case true :
					if (!(PINC & (1 << operatorPinNum)))
					{
						if (flag)
						{
							keyRegisters.PortRegisters(operandPort , operandPortNum , 1);
							start = !start;
							flag = false;
						}
					}
					else 
					{
						flag = true;
					}
					if (start)
					{
						keyRegisters.PortRegisters(operandPort , operandPortNum , 0);
					}
					break;
		
				case false :
					if (!(PINC & (1 << operatorPinNum)))
					{
						if (flag)
						{
							keyRegisters.PortRegisters(operandPort , operandPortNum , 1);
							_delay_ms(200);
							start = !start;
							flag = false;
						}
					}
					else 
					{
						flag = true;
					}
					if (start)
					{
						keyRegisters.PortRegisters(operandPort , operandPortNum , 0);
					}

					break;
			}
			break;
			
		case 'D':
			switch (capUse)
			{
				case true :
					if (!(PIND & (1 << operatorPinNum)))
					{
						if (flag)
						{
							keyRegisters.PortRegisters(operandPort , operandPortNum , 1);
							start = !start;
							flag = false;
						}
					}
					else 
					{
						flag = true;
					}
					if (start)
					{
						keyRegisters.PortRegisters(operandPort , operandPortNum , 0);
					}
					break;
		
				case false :
					if (!(PIND & (1 << operatorPinNum)))
					{
						if (flag)
						{
							keyRegisters.PortRegisters(operandPort , operandPortNum , 1);
							_delay_ms(200);
							start = !start;
							flag = false;
						}
					}
					else 
					{
						flag = true;
					}
					if (start)
					{
						keyRegisters.PortRegisters(operandPort , operandPortNum , 0);
					}

					break;
			}
			break;
	}
}

unsigned int Button::Keypad(unsigned char rowPort , unsigned char columnPin , unsigned int row , unsigned int column , unsigned char operandPort)
{
	
	keyRegisters.DdrRegisters(columnPin , 0 , (column - 1) , 0);
	keyRegisters.DdrRegisters(rowPort , column , (row + column) , 1);
	keyRegisters.DdrRegisters(operandPort , 1);
	
	//----ROW1----
	keyRegisters.PortRegisters(rowPort , 3 , 0);
	_delay_ms(2);
	for (unsigned int pinCounter = 0 ; pinCounter < column ; pinCounter ++)
	{
		if (!(PIND & (1 << pinCounter)))
		{
			key = pinCounter + 1;
		}
	}
	keyRegisters.PortRegisters(rowPort , 3 , 1);
	
	//----ROW2----
	keyRegisters.PortRegisters(rowPort , 4 , 0);
	_delay_ms(2);
	for (unsigned int pinCounter = 0 ; pinCounter < column ; pinCounter ++)
	{
		if (!(PIND & (1 << pinCounter)))
		{
			key = pinCounter + 4;
		}
	}
	keyRegisters.PortRegisters(rowPort , 4 , 1);
	
	//----ROW3----
	keyRegisters.PortRegisters(rowPort , 5 , 0);
	_delay_ms(2);
	for (unsigned int pinCounter = 0 ; pinCounter < column ; pinCounter ++)
	{
		if (!(PIND & (1 << pinCounter)))
		{
			key = pinCounter + 7;
		}
	}
	keyRegisters.PortRegisters(rowPort , 5 , 1);
	
	//----ROW4----
	keyRegisters.PortRegisters(rowPort , 6 , 0);
	_delay_ms(2);
	if (!(PIND & (1 << 0))) key = 10;
	if (!(PIND & (1 << 1))) key = 0;
	if (!(PIND & (1 << 2))) key = 11;
	keyRegisters.PortRegisters(rowPort , 6 , 1);
	
	switch (key)
	{
		case (1) :
		keyRegisters.PortRegisters('A' , key , 1);
		break;
		case (2) :
		keyRegisters.PortRegisters('A' , key , 1);
		break;		
		case (3) :
		keyRegisters.PortRegisters('A' , key , 1);
		break;
		case (4) :
		keyRegisters.PortRegisters('A' , key , 1);
		break;
		case (5) :
		keyRegisters.PortRegisters('A' , key , 1);
		break;
		case (6) :
		keyRegisters.PortRegisters('A' , key , 1);
		break;
		case (7) :
		keyRegisters.PortRegisters('A' , key , 1);
		break;
		case (0) :
		keyRegisters.PortRegisters('A' , key , 1);
		break;
	}
	return key;
}

/*void Button::Keypad (unsigned char rowPort , unsigned char columnPin , unsigned int row , unsigned int column , unsigned char operandPort)
{
	
	keyRegisters.setDdrRegisters(columnPin , 0 , (column - 1) , 0);
	keyRegisters.setDdrRegisters(rowPort , column , (row + column) , 1);
	keyRegisters.setDdrRegisters(operandPort , 1);
	
	for (unsigned int rowCounter = column ; rowCounter < (row + column) ; rowCounter ++)
	{
		keyRegisters.setPortRegisters(rowPort , rowCounter , 0);
		_delay_ms(2);
		for (unsigned int pinCounter = 0 ; pinCounter < column ; pinCounter ++)
		{
			if (!(PIND & (1 << pinCounter)))
			{
				switch (rowCounter)
				{
					case 3:
					key = pinCounter + 1;
					break;
					case 4:
					key = pinCounter + 4;
					break;
					case 5:
					key = pinCounter + 7;
					break;
					case 6:
					key = pinCounter + 10;
					break;
				}
			}
		}
	}
	switch (key)
	{
		case (0) :
		keyRegisters.setPortRegisters(operandPort , key , 1);
		break;
		case (1) :
		keyRegisters.setPortRegisters(operandPort , key , 1);
		break;
		case (2) :
		keyRegisters.setPortRegisters(operandPort , key , 1);
		break;
		case (3) :
		keyRegisters.setPortRegisters(operandPort , key , 1);
		break;
		case (4) :
		keyRegisters.setPortRegisters(operandPort , key , 1);
		break;
		case (5) :
		keyRegisters.setPortRegisters(operandPort , key , 1);
		break;
		case (6) :
		keyRegisters.setPortRegisters(operandPort , key , 1);
		break;
		case (7) :
		keyRegisters.setPortRegisters(operandPort , key , 1);
		break;
	}
}*/
