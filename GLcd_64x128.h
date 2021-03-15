/*
 * GLcd_64x128.h
 *
 * Created: 2018/07/28 11:03:57
 *  Author: Milad
 */ 


#ifndef GLCD_64X128_H_
#define GLCD_64X128_H_

class TextGLcd
{
	public:

	#define Data_Port	 PORTA			/* Define data port for GLCD */
	#define Command_Port	 PORTC		/* Define command port for GLCD */
	#define Data_Port_Dir	 DDRA		/* Define data port for GLCD */
	#define Command_Port_Dir DDRC		/* Define command port for GLCD */

	#define RS		 PC0				/* Define control pins */
	#define RW		 PC1
	#define EN		 PC2
	#define CS1		 PC3
	#define CS2		 PC4
	#define RST		 PC5

	#define TotalPage	 8

	void GLCD_Command(char Command);

	void GLCD_Data(char Data);

	void GLCD_Init();

	void GLCD_ClearAll();

	void GLCD_String(char page_no, char *str);
	
	};

class ImageGLcd
{
	public:
	#define Data_Port			PORTA	/* Define data port for GLCD */
	#define Command_Port		PORTC	/* Define command port for GLCD */
	#define Data_Port_Dir		DDRA	/* Define data port for GLCD */
	#define Command_Port_Dir	DDRC	/* Define command port for GLCD */

	#define RS					PC0		/* Define control pins */
	#define RW					PC1
	#define EN					PC2
	#define CS1					PC3
	#define CS2					PC4
	#define RST					PC5

	#define TotalPage			8

	void GLCD_Command(char Command);

	void GLCD_Data(char Data);

	void GLCD_Init();

	void GLCD_ClearAll();

	void GLCD_String(const char* image);
	};

#endif /* GLCD_64X128_H_ */