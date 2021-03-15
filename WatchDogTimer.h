/*
 * WatchDogTimer.h
 *
 * Created: 2018/08/01 1:36:24
 *  Author: Milad
 */ 

#include <avr/io.h>
#include <util/delay.h>


#ifndef WATCHDOGTIMER_H_
#define WATCHDOGTIMER_H_

void WdtOn(float timeOutPeriod)
{
	WDTCR |= (1 << WDE);
	if (timeOutPeriod == 16.3)
	{
		WDTCR &= ~(1 << WDP0);
		WDTCR &= ~(1 << WDP1);
		WDTCR &= ~(1 << WDP2);
	}
		
	else if (timeOutPeriod == 0.5)
	{
		WDTCR |= (1 << WDP0);
		WDTCR &= ~(1 << WDP1);
		WDTCR &= ~(1 << WDP2);
	}
		
	else if(timeOutPeriod == 65.0)
	{
		WDTCR &= ~(1 << WDP0);
		WDTCR |= (1 << WDP1);
		WDTCR &= ~(1 << WDP2);
	}
		
	else if(timeOutPeriod == 0.13)
	{
		WDTCR |= (1 << WDP0);
		WDTCR |= (1 << WDP1);
		WDTCR &= ~(1 << WDP2);
	}
		
	else if(timeOutPeriod == 0.26)
	{
		WDTCR &= ~(1 << WDP0);
		WDTCR &= ~(1 << WDP1);
		WDTCR |= (1 << WDP2);
	}
		
	else if(timeOutPeriod == 0.52)
	{
		WDTCR |= (1 << WDP0);
		WDTCR &= ~(1 << WDP1);
		WDTCR |= (1 << WDP2);
	}
		
	else if(timeOutPeriod == 1.0)
	{
		WDTCR &= ~(1 << WDP0);
		WDTCR |= (1 << WDP1);
		WDTCR |= (1 << WDP2);
	}
		
	else if(timeOutPeriod == 2.1)
	{
		WDTCR |= (1 << WDP0);
		WDTCR |= (1 << WDP1);
		WDTCR |= (1 << WDP2);
	}
}

void WdtOff(void)
{
	WDTCR = (1<<WDTOE)|(1<<WDE);
	WDTCR = 0x00;
}

#endif /* WATCHDOGTIMER_H_ */