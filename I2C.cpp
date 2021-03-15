/*
 * I2C.cpp
 *
 * Created: 2018/08/05 8:20:45
 *  Author: Milad
 */

#include "I2C.h"



void I2c::MasterInit(PrescalerValues prescalerValue)
{
	switch (prescalerValue)
	{
		case DevidedBy1:
		TWSR &= ~(1 << TWPS0);
		TWSR &= ~(1 << TWPS1);
		break;
		case DevidedBy4:
		TWSR |= (1 << TWPS0);
		TWSR &= ~(1 << TWPS1);
		case DevidedBy16:
		TWSR &= ~(1 << TWPS0);
		TWSR |= (1 << TWPS1);
		case DevidedBy64:
		TWSR = (1 << TWPS0)|(1 << TWPS1);
	}
	uint8_t bitRateValue = ((F_CPU/SCL_CLK) - 16) / (2 * pow(4, (TWSR)));
	TWBR = bitRateValue;
}

uint8_t I2c::Start(unsigned char writeAddress)
{
	uint8_t status;														/* Declare variable */
    TWCR = (1 << TWSTA)|(1 << TWEN)|(1 << TWINT);						/* Enable TWI, generate START & clear interrupt flag*/
    while (!(TWCR & (1 << TWINT)));										/* Wait until TWI finish its current job */
    status = TWSR & 0xF8;												/* Read TWI status register */
    if (status != 0x08)													/* Check weather START transmitted or not? */
	{
		return 0;														/* Return 0 to indicate start condition fail */
	}
    TWDR = writeAddress;												/* Write SLA+W in TWI data register */
    TWCR = (1 << TWEN)|(1 << TWINT);									/* Enable TWI & clear interrupt flag */
    while (!(TWCR & (1 << TWINT)));										/* Wait until TWI finish its current job */
    status = TWSR & 0xF8;												/* Read TWI status register */	
    if (status == 0x18)													/* Check for SLA+W transmitted & ack received */
	{
		return 1;														/* Return 1 to indicate ack received */
	}
    if (status == 0x20)													/* Check for SLA+W transmitted & nack received */
	{
		return 2;														/* Return 2 to indicate nack received */
	}
    else
	{
		return 3;														/* Else return 3 to indicate SLA+W failed */
	}
}

void I2c::StartWait(unsigned char writeAddress)
{
	uint8_t status;														/* Declare variable */
	while (1)
	{
		TWCR = (1 << TWSTA)|(1 << TWEN)|(1 << TWINT);					/* Enable TWI, generate start condition and clear interrupt flag */
		while (!(TWCR & (1 << TWINT)));									/* Wait until TWI finish its current job (start condition) */
		status = TWSR & 0xF8;											/* Read TWI status register with masking lower three bits */
		if (status != 0x08)												/* Check weather start condition transmitted successfully or not? */
		continue;														/* If no then continue with start loop again */
		TWDR = writeAddress;											/* If yes then write SLA+W in TWI data register */
		TWCR = (1 << TWEN)|(1 << TWINT);								/* Enable TWI and clear interrupt flag */
		while (!(TWCR & (1 << TWINT)));									/* Wait until TWI finish its current job (Write operation) */
		status = TWSR & 0xF8;											/* Read TWI status register with masking lower three bits */
		if (status != 0x18 )											/* Check weather SLA+W transmitted & ack received or not? */
		{
			Stop();														/* If not then generate stop condition */
			continue;													/* continue with start loop again */
		}
		break;															/* If yes then break loop */
	}
}

uint8_t I2c::ReapetedStart(unsigned char readAddress)
{
	uint8_t status;														/* Declare variable */
    TWCR = (1 << TWSTA)|(1 << TWEN)|(1 << TWINT);						/* Enable TWI, generate start and clear interrupt flag */
    while (!(TWCR & (1 << TWINT)));										/* Wait until TWI finish its current job */
    status = TWSR & 0xF8;												/* Read TWI status register */
    if(status != 0x10)													/* Check for repeated start transmitted */
	{
		return 0;														/* Return 0 for repeated start condition fail */
	}
    TWDR = readAddress;													/* Write SLA+R in TWI data register */
    TWCR = (1 << TWEN)|(1 << TWINT);									/* Enable TWI and clear interrupt flag */
    while (!(TWCR & (1 << TWINT)));										/* Wait until TWI finish its current job */
    status = TWSR & 0xF8;												/* Read TWI status register */
    if (status == 0x40)													/* Check for SLA+R transmitted & ack received */
	{
		return 1;														/* Return 1 to indicate ack received */
	}
    if (status == 0x48)													/* Check for SLA+R transmitted & nack received */
	{
		return 2;														/* Return 2 to indicate nack received */
	}
    else
	{
		return 3;														/* Else return 3 to indicate SLA+W failed */
	}
}

uint8_t I2c::Write(unsigned char data)
{
	uint8_t status;														/* Declare variable */
	TWDR = data;														/* Copy data in TWI data register */
	TWCR = (1 << TWEN)|(1 << TWINT);									/* Enable TWI and clear interrupt flag */
	while (!(TWCR & (1<<TWINT)));										/* Wait until TWI finish its current job */
	status = TWSR & 0xF8;												/* Read TWI status register */
	if (status == 0x28)													/* Check for data transmitted & ack received */
	{
		return 0;														/* Return 0 to indicate ack received */
	}
	if (status == 0x30)													/* Check for data transmitted & nack received */
	{
		return 1;														/* Return 1 to indicate nack received */
	}
	else
	{
		return 2;
	}
}

unsigned char I2c::ReadAck(void)
{
	TWCR = (1 << TWEN)|(1 << TWINT)|(1 << TWEA);						/* Enable TWI, generation of ack and clear interrupt flag */
	while (!(TWCR & (1 << TWINT)));										/* Wait until TWI finish its current job */
	return TWDR;														/* Return received data */
}

unsigned char I2c::ReadNack(void)
{
	TWCR = (1 << TWEN)|(1 << TWINT);									/* Enable TWI and clear interrupt flag */
	while (!(TWCR & (1 << TWINT)));										/* Wait until TWI finish its current job */
	return TWDR;														/* Return received data */
}

void I2c::Stop(void)
{
	TWCR = (1 << TWSTO)|(1 << TWINT)|(1 << TWEN);						/* Enable TWI, generate stop */
	while (TWCR & (1 << TWSTO));										/* Wait until stop condition execution */
}



void I2c::SlaveInit(uint8_t slaveAddress)
{
	TWAR = slaveAddress;												/* Assign Address in TWI address register */
	TWCR = (1 << TWEN)|(1 << TWEA)|(1 << TWINT);						/* Enable TWI, Enable ack generation */
}

uint8_t I2c::Listen(void)
{
	while(1)
	{
		uint8_t status;													/* Declare variable */
		while (!(TWCR & (1 << TWINT)));									/* Wait to be addressed */
		status = TWSR & 0xF8;											/* Read TWI status register */
		if (status == 0x60 || status == 0x68)							/* Own SLA+W received &ack returned */
		{
			return 0;													/* Return 0 to indicate ack returned */
		}
		if (status == 0xA8 || status == 0xB0)							/* Own SLA+R received &ack returned */
		{
			return 1;													/* Return 0 to indicate ack returned */
		}
		if (status == 0x70 || status == 0x78)							/* General call received &ack returned */
		{
			return 2;													/* Return 1 to indicate ack returned */
		}
		else
		{
			continue;													/* Else continue */
		}
	}
}

uint8_t I2c::Transmit(unsigned char data)
{
	uint8_t status;
	TWDR = data;														/* Write data to TWDR to be transmitted */
	TWCR = (1 << TWEN)|(1 << TWINT)|(1 << TWEA);						/* Enable TWI & clear interrupt flag */
	while (!(TWCR & (1 << TWINT)));										/* Wait until TWI finish its current job */
	status = TWSR & 0xF8;												/* Read TWI status register */
	if (status == 0xA0)													/* Check for STOP/REPEATED START received */
	{
		TWCR |= (1 << TWINT);											/* Clear interrupt flag & return -1 */
		return -1;
	}
	if(status == 0xB8)													/* Check for data transmitted & ack received */
	{
		return 0;														/* If yes then return 0 */
	}
	if(status == 0xC0)													/* Check for data transmitted & nack received */
	{
		TWCR |= (1 << TWINT);											/* Clear interrupt flag & return -2 */
		return -2;
	}
	if (status == 0xC8)													/* Last byte transmitted with ack received */
	{
		return -3;														/* If yes then return -3 */
	}
	else																/* else return -4 */
	{
		return -4;
	}
}

unsigned char I2c::Receive(void)
{
	uint8_t status;														/* Declare variable */
	TWCR = (1 << TWEN)|(1 << TWEA)|(1 << TWINT);						/* Enable TWI & generation of ack and clear interrupt flag */
	while (!(TWCR & (1 << TWINT)));										/* Wait until TWI finish its current job */
	status = TWSR & 0xF8;												/* Read TWI status register */
	if (status == 0x80 || status == 0x90)								/* Check for data received & ack returned */
	{
		return TWDR;													/* If yes then return received data */
	}
	if( status == 0x88 || status == 0x98)								/* Check for data received, nack returned & switched to not addressed slave mode */
	{
		return TWDR;													/* If yes then return received data */
	}
	if(status == 0xA0)													/* Check wether STOP/REPEATED START */
	{
		TWCR |= (1 << TWINT);											/* Clear interrupt flag & return -1 */
		return -1;
	}
	else
	{
		return -2;														/* Else return -2 */
	}
}
