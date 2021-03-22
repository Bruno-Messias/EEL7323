#ifndef MAX7219_H
#define MAX7219_H

#define F_CPU 16000000 // frequency oscillator

#include <util/delay.h>
#include "pins_atmega328p.h"

class MaxDriver
{
	
public:
	MaxDriver();
	void SPI_Write_Byte(uint8_t);
	void MAX7219_INIT();
	void displaySignal(unsigned int, unsigned int);
	void resetDisplay();
};


#endif //MAX7219_H 