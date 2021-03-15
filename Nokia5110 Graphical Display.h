/*
 * Nokia5110_Graphical_Display.h
 *
 * Created: 2018/08/24 8:53:06
 *  Author: Milad
 */ 

#ifndef NOKIA5110 GRAPHICAL DISPLAY_H_
#define NOKIA5110 GRAPHICAL DISPLAY_H_

#define F_CPU 8000000UL

#include <util/delay.h>
#include <string.h>
#include "AnimKid.h"
#include "SPI.h"
#include "Font.h"


class NokiaDisplay
{
	public:
	
	Spi spi;
	
	void Command(char DATA);
	
	void Print(char *DATA);

	void Reset();

	void Init();

	void SetXy(char x, char y);

	void Clear();

	void Image(const unsigned char *image_data);
	
	};

#endif /* NOKIA5110 GRAPHICAL DISPLAY_H_ */
