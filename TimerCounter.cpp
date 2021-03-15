/*
 * TimerCounter.cpp
 *
 * Created: 2018/07/30 8:54:45
 *  Author: Milad
 */ 

#include "TimerCounter.h"



void TC::delayGenerator(uint16_t delayValue , uint8_t FoscValue , PhraseVariable WMode , bool timerOverFlowinterrupt)
{
	uint16_t preScalerValue;
	uint16_t preScalerValues[5] = { 1024 , 456 , 64 , 8 , 1 };
	uint8_t timerCycle;
	float timerCyclePosibleValues[5];
	
	for (uint8_t count = 0 ; count <= 4 ; count ++)
	{
		timerCyclePosibleValues[count] = (delayValue * FoscValue * 1000)/(preScalerValues[count]);
	}
	
	for (uint8_t count = 0 ; count <= 4 ; count ++)
	{
		if (timerCyclePosibleValues[count] < 256)
		{
			continue;
		}
		else if (((int)(timerCyclePosibleValues[count])) == 255)
		{
			preScalerValue = preScalerValues[count];
			timerCycle = timerCyclePosibleValues[count];
			break;
		}
		else if (timerCyclePosibleValues[count] > 256)
		{
			if (count == 0)
			{
				
			}
			else if (count > 0)
			{
				preScalerValue = preScalerValues[count - 1];
				timerCycle = timerCyclePosibleValues[count - 1];
			}
		}
	}
	
	if (timerOverFlowinterrupt)
	{
		sei();
		TIMSK |= (1 << TOIE0);
	}
	
	switch (preScalerValue)
	{
		case 8:
		TCCR0 |= (1 << CS01);
		break;
		
		case 64:
		TCCR0 = (1 << CS00)|(1 << CS01);
		break;
		
		case 256:
		TCCR0 |= (1 << CS02);
		break;
		
		case 1024:
		TCCR0 = (1 << CS00)|(1 << CS02);
	}
	
	switch (WMode)
	{
		case Normal:
		TCCR0 &= ~((1 << WGM00)|(1 << WGM01));
		break;
		case CTC:
		TCCR0 |= (1 << WGM01);
		TCCR0 &= ~(1 << WGM00);
		break;
		case PhaseCorrectPWM:
		TCCR0 |= (1 << WGM00);
		TCCR0 &= ~(1 << WGM01);
		break;
		case FastPWM:
		TCCR0 |= (1 << WGM00)|(1 << WGM01);
		break;
	}
	
	TCNT0 = 256 - timerCycle;
	while ((TIFR & 0x01) == 0);
	TCCR0 &= ~(1 << TCCR0);
	TIFR = 0x1;
	
}

void TC::CounterMode(PhraseVariable clockOnWhat , PhraseVariable timerx)
{
	switch (timerx)
	{
		case Timer0:
		switch (clockOnWhat)
		{
			case FallingEdge:
			TCCR0 = (1 << CS01)|(1 << CS02);
			break;
			case RisingEdge:
			TCCR0 = (1 << CS00)|(1 << CS01)|(1 << CS02);
		}
		break;
		case Timer1:
		
		break;
		Timer2:
		
		break;
	}
}

void TC::TimerMode(PhraseVariable timerx , PhraseVariable waveFormGeneration , PhraseVariable workMode , uint16_t preScaler , uint16_t initialValue , uint16_t specificValue , bool timerOverFlowinterrupt , bool timerCompareInterrupt)
{
	switch (timerx)
	{
		
//------------------Timer0-----------------:
		
		case Timer0:
		DDRB |= (1 << PB3);
		switch (preScaler)
		{
			TCCR0 |= (1 << CS00);
			case 1:
			break;
			case 8:
			TCCR0 |= (1 << CS01);
			break;
			case 64:
			TCCR0 = (1 << CS00)|(1 << CS01);
			break;
			case 256:
			TCCR0 |= (1 << CS02);
			break;
			case 1024:
			TCCR0 = (1 << CS00)|(1 << CS02);
			break;
		}
		switch (workMode)
		{
			case Disconnenct:
			TCCR0 &= ~(1 << COM00);
			TCCR0 &= ~(1 << COM01);
			break;
			case Toggle:
			TCCR0 |= (1 << COM00);
			TCCR0 &= ~(1 << COM01);
			break;
			case Clear:
			TCCR0 &= ~(1 << COM00);
			TCCR0 |= (1 << COM01);
			break;
			case Set:
			TCCR0 = (1 << COM00)|(1 << COM01);
			break;
			case Inverted:
			TCCR0 = (1 << COM00)|(1 << COM01);
			break;
			case NonInverted:
			TCCR0 |= (1 << COM01);
			TCCR0 &= ~(1 << COM00);
			break;
		}
		switch (waveFormGeneration)
		{
			case Normal:
			TCNT0 = initialValue;
			OCR0 = specificValue;
			while((TIFR & (1 << TOV0)) == 0);
			TIFR |= (1 << TOV0);
			break;
			case CTC:
			OCR0 = specificValue;
			TCCR0 |= (1 << WGM01);
			while ((TIFR & (1 << OCF0)) == 0);
			TIFR |= (1 << OCF0);
			break;
			case PhaseCorrectPWM:
			TCCR0 |= (1 << WGM00);
			break;
			case FastPWM:
			TCCR0 = (1 << WGM00)|(1 << WGM01);
			OCR0 = (specificValue * 256) / 100;
			break;
		}
		if (timerOverFlowinterrupt)
		{
			sei();
			TIMSK |= (1 << TOIE0);
		}
		if (timerCompareInterrupt)
		{
			sei();
			TIMSK |= (1 << OCIE0);
		}
		break;
		
//------------------Timer1--------------------- :

		case Timer1:
		if (waveFormGeneration == Normal_ChannelA || waveFormGeneration == CTC_ChannelA || waveFormGeneration == FastPWM_ChannelA || waveFormGeneration == PhaseAndFrequensyCorrectPWM_ChannelA)
		{
			DDRD |= (1 << PD5);
		}
		else if (waveFormGeneration == Normal_ChannelB || waveFormGeneration == CTC_ChannelB || waveFormGeneration == FastPWM_ChannelB || waveFormGeneration == PhaseAndFrequensyCorrectPWM_ChannelB)
		{
			DDRD |= (1 << PD4);
		}
		switch (preScaler)
		{
			case 1:
			TCCR1B |= (1 << CS10);
			break;
			case 8:
			TCCR1B |= (1 << CS11);
			break;
			case 64:
			TCCR1B = (1 << CS10)|(1 << CS11);
			break;
			case 256:
			TCCR1B |= (1 << CS12);
			break;
			case 1024:
				TCCR1B = (1 << CS10)|(1 << CS12);
			break;
		}
		switch (workMode)
		{
			case Disconnenct:
			TCCR1A &= ~(1 << COM1B0);
			TCCR1A &= ~(1 << COM1B1);
			TCCR1A &= ~(1 << COM1A0);
			TCCR1A &= ~(1 << COM1A1);
			break;
			case Toggle:
			if (waveFormGeneration == CTC_ChannelA || waveFormGeneration == Normal_ChannelA)
			{
				TCCR1A |= (1 << COM1A0);
			}
			else if (waveFormGeneration == CTC_ChannelB || waveFormGeneration == Normal_ChannelB)
			{
				TCCR1A |= (1 << COM1B0);
			}
			break;
			case Clear:
			if (waveFormGeneration == CTC_ChannelA || waveFormGeneration == Normal_ChannelA || waveFormGeneration == PhaseAndFrequensyCorrectPWM_ChannelA)
			{
				TCCR1A |= (1 << COM1A1);
			}
			else if (waveFormGeneration == CTC_ChannelB || waveFormGeneration == Normal_ChannelB)
			{
				TCCR1A |= (1 << COM1B1);
			}
			break;
			case Set:
			if (waveFormGeneration == CTC_ChannelA || waveFormGeneration == Normal_ChannelA || waveFormGeneration == PhaseAndFrequensyCorrectPWM_ChannelA)
			{
				TCCR1A = (1 << COM1A0)|(1 << COM1A1);
			}
			else if (waveFormGeneration == CTC_ChannelB || waveFormGeneration == Normal_ChannelB || waveFormGeneration == PhaseAndFrequensyCorrectPWM_ChannelB)
			{
				TCCR1A = (1 << COM1B0)|(1 << COM1B1);
			}
			break;
			case Inverted:
			if (waveFormGeneration == FastPWM_ChannelA)
			{
				TCCR1A = (1 << COM1A0)|(1 << COM1A1);
			}
			else if (waveFormGeneration == FastPWM_ChannelB)
			{
				TCCR1A = (1 << COM1B0)|(1 << COM1B1);
			}
			break;
			case NonInverted:
			if (waveFormGeneration == FastPWM_ChannelA)
			{
				TCCR1A |= (1 << COM1A1);
			}
			else if (waveFormGeneration == FastPWM_ChannelB)
			{
				TCCR1A |= (1 << COM1B1);
			}
			break;
		}
		switch (waveFormGeneration)
		{
			case Normal_ChannelA:
			TCNT1 = initialValue;
			OCR1A = specificValue;
			while((TIFR & (1 << TOV1)) == 0);
			TIFR |= (1 << TOV1);
			break;
			case Normal_ChannelB:
			TCNT1 = initialValue;
			OCR1B = specificValue;
			while((TIFR & (1 << TOV1)) == 0);
			TIFR |= (1 << TOV1);
			break;
			case CTC_ChannelA:
			TCNT1 = initialValue;
			OCR1A = specificValue;
			TCCR1B |= (1 << WGM12);
			while ((TIFR & (1 << OCF1A)) == 0);
			TIFR |= (1 << OCF1A);
			break;
			case CTC_ChannelB:
			TCNT1 = initialValue;
			OCR1B = specificValue;
			TCCR1B = (1 << WGM12);
			while ((TIFR & (1 << OCF1B)) == 0);
			TIFR |= (1 << OCF1B);
			break;
			case PhaseCorrectPWM_ChannelA:
			TCCR1A = (1 << WGM10)|(1 << WGM11);
			TCCR1B |= (1 << WGM13);
			OCR1A = (specificValue * 65536) / 100;
			break;
			case PhaseCorrectPWM_ChannelB:
			TCCR1A = (1 << WGM10)|(1 << WGM11);
			TCCR1B |= (1 << WGM13);
			OCR1B = (specificValue * 65536) / 100;
			break;
			case FastPWM_ChannelA:
			TCCR1A = (1 << WGM10)|(1 << WGM11);
			TCCR1B = (1 << WGM12)|(1 << WGM13);
			OCR1A = (specificValue * 65536) / 100;
			break;
			case FastPWM_ChannelB:
			TCCR1A = (1 << WGM10)|(1 << WGM11);
			TCCR1B = (1 << WGM12)|(1 << WGM13);
			OCR1B = (specificValue * 65536) / 100;
			break;
		}
		if (timerOverFlowinterrupt)
		{
			sei();
			TIMSK |= (1 << TOIE1);
		}
		if (timerCompareInterrupt)
		{
			sei();
			switch (waveFormGeneration)
			{
				case CTC_ChannelA:
				TIMSK |= (1 << OCIE1A);
				break;
				case CTC_ChannelB:
				TIMSK |= (1 << OCIE1B);
				break;
			}
		}
		break;
		
//----------------Timer2---------------------:
		
		case Timer2:
		DDRD |= (1 << PD7);
		switch (preScaler)
		{
			case 1:
			TCCR2 |= (1 << CS20);
			break;
			case 8:
			TCCR2 |= (1 << CS21);
			break;
			case 64:
			TCCR2 = (1 << CS20)|(1 << CS21);
			break;
			case 256:
			TCCR2 |= (1 << CS22);
			break;
			case 1024:
			TCCR2 = (1 << CS20)|(1 << CS22);
			break;
		}
		switch (workMode)
		{
			case Disconnenct:
			TCCR2 &= ~(1 << COM20);
			TCCR2 &= ~(1 << COM21);
			break;
			case Toggle:
			TCCR2 |= (1 << COM20);
			TCCR2 &= ~(1 << COM21);
			break;
			case Clear:
			TCCR2 &= ~(1 << COM20);
			TCCR2 |= (1 << COM21);
			break;
			case Set:
			TCCR2 = (1 << COM20)|(1 << COM21);
			break;
			case Inverted:
			TCCR2 = (1 << COM20)|(1 << COM21);
			break;
			case NonInverted:
			TCCR2 |= (1 << COM21);
			TCCR2 &= ~(1 << COM20);
			break;
		}
		switch (waveFormGeneration)
		{
			case Normal:
			TCNT2 = initialValue;
			OCR2 = specificValue;
			while((TIFR & (1 << TOV2)) == 0);
			TIFR |= (1 << TOV2);
			break;
			case CTC:
			TCNT2 = initialValue;
			OCR2 = specificValue;
			TCCR2 |= (1 << WGM21);
			while ((TIFR & (1 << OCF2)) == 0);
			TIFR |= (1 << OCF2);
			break;
			case PhaseCorrectPWM:
			TCCR2 |= (1 << WGM20);
			break;
			case FastPWM:
			TCCR2 = (1 << WGM20)|(1 << WGM21);
			OCR2 = (specificValue * 256) / 100;
			break;
		}
		if (timerOverFlowinterrupt)
		{
			sei();
			TIMSK |= (1 << TOIE2);
		}
		if (timerCompareInterrupt)
		{
			sei();
			TIMSK |= (1 << OCIE2);
		}
		break;
	}
}
