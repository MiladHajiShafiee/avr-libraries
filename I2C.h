/*
 * I2C.h
 *
 * Created: 2018/08/05 8:20:45
 *  Author: Milad
 */ 
#ifndef I2C_H_
#define I2C_H_

#define F_CPU 8000000UL
#define SCL_CLK 100000UL

#include <avr/io.h>
#include <math.h>

enum PrescalerValues {
	DevidedBy1, DevidedBy4,
	DevidedBy16, DevidedBy64
	};

class I2c
{
	public:
	
	void MasterInit(PrescalerValues prescalerValue);
	
	uint8_t Start(unsigned char writeAddress);
	
	void StartWait(unsigned char writeAddress);
	
	uint8_t ReapetedStart(unsigned char readAddress);
	
	uint8_t Write(unsigned char data);
	
	unsigned char ReadAck(void);
	
	unsigned char ReadNack(void);
	
	void Stop(void);
	
	void SlaveInit(uint8_t slaveAddress);
	
	uint8_t Listen(void);
	
	uint8_t Transmit(unsigned char data);
	
	unsigned char Receive(void);
	
	};


#endif /* I2C_H_ */
