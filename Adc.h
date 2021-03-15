/*
 * Adc.h
 *
 * Created: 2018/07/29 7:33:27
 *  Author: Milad
 */ 


#ifndef ADC_H_
#define ADC_H_

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>


class Adc
{
	public:
	
	void AdcInit(unsigned char adcPort , unsigned int AdcChannel , unsigned int ADCSRAFrequency , const char *Vref);
	unsigned int AdcRead(void);
	};


#endif /* ADC_H_ */