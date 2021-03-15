/*
 * TimerCounter.h
 *
 * Created: 2018/07/30 8:55:04
 *  Author: Milad
 */ 


/*
-------------------------------------------------- Introduction to TimerCounter ------------------------------------------- :
	Generally, we use timer/counter to generate time delays, waveforms or to count events. Also, the timer is used for PWM generation, capturing events etc.

	In AVR ATmega16 / ATmega32, there are three timers :
	
	Timer0: 8-bit timer
	Timer1: 16-bit timer
	Timer2: 8-bit timer
	
	
	Basic registers and flags of the Timers :
	
	1 - TCNTn : Timer / Counter Register :
		Every timer has timer/counter register. It is zero upon reset. We can access value or write a value to this register. It counts up with each clock pulse.
		TOVn : Timer Overflow Flag :
		Each timer has Timer Overflow flag. When timer overflows, this flag will get set.
	2 - TCCRn : Timer Counter Control Register :
		This register is used for setting the modes of timer/counter.
	3 - OCRn : Output Compare Register :
		The value in this register is compared with the content of the TCNTn register. When they are equal, OCFn flag will get set.
	4 -	TIFR: Timer Counter Interrupt Flag register
	
*/

#ifndef TIMERCOUNTER_H_
#define TIMERCOUNTER_H_

#include <avr/io.h>
#include <avr/interrupt.h>


enum PhraseVariable { Normal , CTC , PhaseCorrectPWM_ChannelA , PhaseCorrectPWM_ChannelB , Clear , FastPWM , PhaseAndFrequensyCorrectPWM ,
					  Timer , Counter , FallingEdge , RisingEdge , Toggle , Set , PhaseAndFrequensyCorrectPWM_ChannelA , PhaseCorrectPWM ,
					  Timer0 , Timer1 , Timer2 , Disconnenct , Inverted , NonInverted , CTC_ChannelA , PhaseAndFrequensyCorrectPWM_ChannelB ,
					  Normal_ChannelA , Normal_ChannelB , CTC_ChannelB , FastPWM_ChannelA , FastPWM_ChannelB };

class TC
{
	public:
	
	void delayGenerator(uint16_t delayValue , uint8_t FoscValue , PhraseVariable WMode , bool timerOverFlowinterrupt);
	
	void CounterMode(PhraseVariable clockOnWhat , PhraseVariable timerx);
	
	void TimerMode(PhraseVariable timerx , PhraseVariable waveFormGeneration , PhraseVariable workMode , uint16_t preScaler , uint16_t initialValue , uint16_t specificValue , bool timerOverFlowinterrupt , bool timerCompareInterrupt);
	
	};



#endif /* TIMERCOUNTER_H_ */