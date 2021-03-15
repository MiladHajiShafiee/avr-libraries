/*
 * ExternalInterrupt.h
 *
 * Created: 2018/08/01 7:36:19
 *  Author: Milad
 */ 


#ifndef EXTERNALINTERRUPT_H_
#define EXTERNALINTERRUPT_H_

#include <avr/interrupt.h>

enum intReq { Int0, Int1, Int2 };
enum trigSty { level, anyTrigger, fallingEdge, risingEdge };

class ExInterrupt
{
	public:
	
	void interrptInit(intReq R , trigSty T);
	
	};



#endif /* EXTERNALINTERRUPT_H_ */
