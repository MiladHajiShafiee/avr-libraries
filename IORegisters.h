/*
 * IORegisters.h
 *
 * Created: 2018/07/08 8:28:46
 *  Author: Milad
 */ 


#ifndef IOREGISTERS_H_
#define IOREGISTERS_H_

class Registers
{
	public:
	
	
	void DdrRegisters(unsigned char rName , unsigned int rBeginnerNum , unsigned int rEnderNum , unsigned int rSituation);

	void DdrRegisters(unsigned char rName , unsigned int rNum , unsigned int rSituation);

	void DdrRegisters(unsigned char rName , unsigned int rSituation);


	void PortRegisters(unsigned char rName , unsigned int rBeginnerNum , unsigned int rEnderNum , unsigned int rSituation);

	void PortRegisters(unsigned char rName , unsigned int rNum , unsigned int rSituation);

	void PortRegisters(unsigned char rName , unsigned int rSituation);
	
};

#endif /* IOREGISTERS_H_ */
