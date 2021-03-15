/*
 * AnalogComparator.h
 *
 * Created: 2018/08/16 5:16:11
 *  Author: Milad
 */ 


#ifndef ANALOGCOMPARATOR_H_
#define ANALOGCOMPARATOR_H_

enum PhraseValues {
	AIN1, ADC0, ADC1,
	ADC2, ADC3, ADC4,
	ADC5, ADC6, ADC7,
	False, Toggle,
	FallingEdge, RisingEdge
		};

uint8_t AcInit(PhraseValues ve, PhraseValues interruptMode, bool inputCaptureMode)
{
	if (ve == AIN1)
	{
		SFIOR &= ~(1 << ACME);
		ACSR = 0x00;
	} 
	else
	{
		ADCSRA &= ~(1 << ADEN);
		SFIOR |= (1 << ACME);
		ACSR = 0x00;
		switch (ve)
		{
			case ADC0:
			ADMUX = 0b00000000;
			break;
			case ADC1:
			ADMUX = 0b00000001;
			break;
			case ADC2:
			ADMUX = 0b00000010;
			break;
			case ADC3:
			ADMUX = 0b00000011;
			break;
			case ADC4:
			ADMUX = 0b00000100;
			break;
			case ADC5:
			ADMUX = 0b00000101;
			break;
			case ADC6:
			ADMUX = 0b00000110;
			break;
			case ADC7:
			ADMUX = 0b00000111;
			break;
		}
	}
	if (interruptMode != False)
	{
		ACSR |= (1 << ACIE);
		switch (interruptMode)
		{
			case Toggle:
			ACSR &= ~(1 << ACIS0);
			ACSR &= ~(1 << ACIS1);
			break;
			case FallingEdge:
			ACSR &= ~(1 << ACIS0);
			ACSR |= (1 << ACIS1);
			break;
			case RisingEdge:
			ACSR = (1 << ACIS0)|(1 << ACIS1);
			break;
		}
	}
	if (inputCaptureMode)
	{
		ACSR |= (1 << ACIC);
	} 
	else
	{
		ACSR &= ~(1 << ACIC);
	}
	while (1)
	{
		if (ACSR & (1 << ACO))
		{
			return 1;
		} 
		else
		{
			return 0;
		}
	}
}

#endif /* ANALOGCOMPARATOR_H_ */
