/*
 * Adc.cpp
 *
 * Created: 2018/07/29 7:33:10
 *  Author: Milad
 */ 

#include "IORegisters.h"
#include "Adc.h"

Registers IORegister;

void Adc::AdcInit(unsigned char adcPort , unsigned int AdcChannel , unsigned int ADCSRAFrequency , const char *Vref)
{
	IORegister.setDdrRegisters(adcPort , AdcChannel , 0);
	ADCSRA |= (1 << ADSC);
	switch (ADCSRAFrequency)
	{
		case 2 :
			ADCSRA = (1 << ADEN)|(1 << ADPS0);
		break;
	
		case 4 :
			ADCSRA =  (1 << ADEN)|(1 << ADPS1);
		break;
	
		case 8 :
			ADCSRA =  (1 << ADEN)|(1 << ADPS0)|(1 << ADPS1);
		break;
	
		case 16 :
			ADCSRA =  (1 << ADEN)|(1 << ADPS2);
		break;
	
		case 32 :
			ADCSRA =  (1 << ADEN)|(1 << ADPS0)|(1 << ADPS2);
		break;
	
		case 64 :
			ADCSRA =  (1 << ADEN)|(1 << ADPS1)|(1 << ADPS2);
		break;
	
		case 128 :
			ADCSRA =  (1 << ADEN)|(1 << ADPS0)|(1 << ADPS1)|(1 << ADPS2);
		break;
	}
	
	if (Vref == "AREF")
	{
		ADMUX &= ~(1 << REFS0);
		ADMUX &= ~(1 << REFS1);
	}
	else if (Vref == "AVcc")
	{
			ADMUX |= (1 << REFS0);
			ADMUX &= ~(1 << REFS1);
	}
	else if (Vref == "Internal")
	{
		ADMUX |= (1 << REFS0);
		ADMUX |= (1 << REFS1);
	}
	
}

unsigned int Adc::AdcRead(void)
{
	ADCSRA = (1 << ADSC)|(1 << ADEN);
	while (ADIF == 0);
	ADCSRA |= (1 << ADIF);
	return ADCW;
}
