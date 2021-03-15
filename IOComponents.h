/*
 * IOComponents.h
 *
 * Created: 2018/07/08 9:09:12
 *  Author: Milad
 */ 


#ifndef IOCOMPONENTS_H_
#define IOCOMPONENTS_H_

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "IORegisters.h"

class Button
{
	public:	
	
	bool start = true;
	bool flag = false;
	unsigned int keyCounter = 0;
	unsigned int key;
  
	void InstanseEffectButton (unsigned char operatorPin , unsigned operatorPinNum , unsigned char operandProt ,unsigned int operandPortNum , bool capUse);

	void ContinueousEffectButton (unsigned char operatorPin , unsigned operatorPinNum , unsigned char operandProt ,unsigned int operandPortNum , bool capUse);

	unsigned int Keypad (unsigned char rowPort , unsigned char columnPin , unsigned int row , unsigned int column , unsigned char operandPort);
	
	
	//void Keypad(unsigned char rowPort , unsigned char columnPin , unsigned int row , unsigned int column , unsigned char operandPort);

};

#endif /* IOCOMPONENTS_H_ */