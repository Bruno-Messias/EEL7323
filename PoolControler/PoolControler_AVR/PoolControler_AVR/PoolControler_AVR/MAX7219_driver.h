#ifndef MAX7219_H
#define MAX7219_H

#include "pins_atmega328p.h"

#define ON                        1
#define OFF                       0

#define MAX7219_LOAD1             PORTB |= (1<<PIN_SS)
#define MAX7219_LOAD0             PORTB &= ~(1<<PIN_SS)

#define MAX7219_MODE_DECODE       0x09
#define MAX7219_MODE_INTENSITY    0x0A
#define MAX7219_MODE_SCAN_LIMIT   0x0B
#define MAX7219_MODE_POWER        0x0C
#define MAX7219_MODE_TEST         0x0F
#define MAX7219_MODE_NOOP         0x00

#define MAX7219_DIGIT0            0x01
#define MAX7219_DIGIT1            0x02
#define MAX7219_DIGIT2            0x03

#define MAX7219_CHAR_BLANK        0xF
#define MAX7219_CHAR_NEGATIVE     0xA

char digitsInUse = 4;

class MaxDriver
{
public:
	MaxDriver();
	void SPI_Write_Byte(char);
	void spiSendByte (char);
	void MAX7219_writeData(char, char);
	void MAX7219_clearDisplay();
	void MAX7219_INIT();
	void MAX7219_displayNumber(volatile long number); 
};


#endif //MAX7219_H 