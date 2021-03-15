/*
 * SPI.cpp
 *
 * Created: 2018/08/02 9:21:43
 *  Author: Milad
 */ 
 #include "SPI.h"
 #include <avr/io.h>
 
 
 void Spi::MasterInit(void)
 {
	 DDRB = (1 << SCK)|(1 << MOSI)|(1 << SS);
	 DDRB &= ~(1 << MISO);
	 PORTB |= (1 << 4);
	 SPCR = (1 << SPE)|(1 << MSTR)|(1 << SPR0);
	 SS_Enable;
 }
 
 void Spi::Write(char data)
 {
	 char flushBuffer;
	 SPDR = data;
	 while(!(SPSR & (1 << SPIF)));
	 flushBuffer = SPDR;
 }
 
 char Spi::Read(void)
 {
	 SPDR = 0xFF;
	 while (!(SPSR & (1<<SPIF)));	/* Wait till reception complete */
	 return (SPDR);					/* Return received data */
 }
 
 void Spi::SlaveInit(void)
 {
	
	DDRB &= ~((1 << SCK)|(1 << MOSI)|(1<< SS));		 /* Make MOSI, SCK, SS as input pins */				
	DDRB |= (1 << MISO);							 /* Make MISO pin as output pin */
	SPCR = (1 << SPE);							 /* Enable SPI in slave mode */
 }
 