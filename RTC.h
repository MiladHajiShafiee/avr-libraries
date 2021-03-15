/*
 * RTC.h
 *
 * Created: 2018/08/21 8:21:43
 *  Author: Milad
 */ 


#ifndef RTC_H_
#define RTC_H_

#define DeviceWriteAddress 0xD0
#define DeviceReadAddress 0xD1
#define TimeFormat12 0x40

#include "I2C.h"


I2c i2c;


uint8_t second, minute, hour, day, month;
uint16_t date, year;

bool IsItPM(unsigned char hour)
{
	if(hour & (0x20))
	return 1;
	else
	return 0;
}

void RTCClockWrite(unsigned char hour, unsigned char minute, unsigned char second, unsigned char AmPm)
{
	hour |= 0x20;
	i2c.Start(DeviceWriteAddress);
	i2c.Write(0);
	i2c.Write(hour);
	i2c.Write(minute);
	i2c.Write(second);
	i2c.Stop();
}

void RTCCalendarWrite(unsigned char day, unsigned char date, unsigned char month, unsigned year)
{
	i2c.Start(DeviceWriteAddress);
	i2c.Write(3);
	i2c.Write(day);
	i2c.Write(date);
	i2c.Write(month);
	i2c.Write(year);
	i2c.Stop();
}

void RTCReadClock(unsigned char readClockAddress)
{
	i2c.Start(DeviceWriteAddress);
	i2c.Write(readClockAddress);
	i2c.ReapetedStart(DeviceReadAddress);
	second = i2c.ReadAck();
	minute = i2c.ReadAck();
	hour = i2c.ReadAck();
	i2c.Stop();
}

void RTCReadCalendar(unsigned char readCalendarAddress)
{
	i2c.Start(DeviceWriteAddress);
	i2c.Write(readCalendarAddress);
	i2c.ReapetedStart(DeviceReadAddress);
	day = i2c.ReadAck();
	date = i2c.ReadAck();
	month = i2c.ReadAck();
	year = i2c.ReadAck();
	i2c.Stop();	
}

#endif /* RTC_H_ */