#include "MAX7219_driver.h"

MaxDriver::MaxDriver()
{
	 	
}


void MaxDriver::spiSendByte (char databyte)
{
	// Copy data into the SPI data register
	SPDR = databyte;
	// Wait until transfer is complete
	while (!(SPSR & (1 << SPIF)));
}

void MaxDriver::MAX7219_writeData(char data_register, char data)
{
	MAX7219_LOAD0;
	// Send the register where the data will be stored
	spiSendByte(data_register);
	// Send the data to be stored
	spiSendByte(data);
	MAX7219_LOAD1;
}

void MaxDriver::MAX7219_clearDisplay()
{
	char i = digitsInUse;
	// Loop until 0, but don't run for zero
	do {
		// Set each display in use to blank
		MaxDriver::MAX7219_writeData(i, MAX7219_CHAR_BLANK);
	} while (--i);
}

void MaxDriver::MAX7219_INIT()
{
	// SCK MOSI CS/LOAD/SS
	DDRB |= (1 << PIN_SCK) | (1 << PIN_MOSI) | (1 << PIN_SS);

	// SPI Enable, Master mode
	SPCR |= (1 << SPE) | (1 << MSTR)| (1<<SPR1);
	
	// Decode mode to "Font Code-B"
	MaxDriver::MAX7219_writeData(MAX7219_MODE_DECODE, 0xFF);

	// Scan limit runs from 0.
	MaxDriver::MAX7219_writeData(MAX7219_MODE_SCAN_LIMIT, digitsInUse - 1);
	MaxDriver::MAX7219_writeData(MAX7219_MODE_INTENSITY, 8);
	MaxDriver::MAX7219_writeData(MAX7219_MODE_POWER, ON);
}


void MaxDriver::MAX7219_displayNumber(volatile long number) 
{
    char negative = 0;

    // Convert negative to positive.
    // Keep a record that it was negative so we can
    // sign it again on the display.
    if (number < 0) {
        negative = 1;
        number *= -1;
    }

    MaxDriver::MAX7219_clearDisplay();

    // If number = 0, only show one zero then exit
    if (number == 0) {
        MaxDriver::MAX7219_writeData(MAX7219_DIGIT0, 0);
        return;
    }
    
    // Initialization to 0 required in this case,
    // does not work without it. Not sure why.
    char i = 0; 
    
    // Loop until number is 0.
    do {
        MaxDriver::MAX7219_writeData(++i, number % 10);
        // Actually divide by 10 now.
        number /= 10;
    } while (number);

    // Bear in mind that if you only have three digits, and
    // try to display something like "-256" all that will display
    // will be "256" because it needs an extra fourth digit to
    // display the sign.
    if (negative) {
        MaxDriver::MAX7219_writeData(i, MAX7219_CHAR_NEGATIVE);
    }
}
