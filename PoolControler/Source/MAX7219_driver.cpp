#include "MAX7219_driver.h"


MaxDriver::MaxDriver()
{
	 // set CS, MOSI and SCK to output
	 SPI_DDR |= (1 << CS) | (1 << MOSI) | (1 << SCK);

	 // enable SPI, set as master, and clock to fosc/128
	 SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR1) | (1 << SPR0);
}


void MaxDriver::SPI_Write_Byte(uint8_t data)
{
	// load data into register
	SPDR = data;

	// Wait for transmission complete
	while(!(SPSR & (1 << SPIF)));
}


void MaxDriver::MAX7219_INIT()
{
	// Disable Shutdown mode
	rst_bit(PORTB, CS);		 // CS pin is pulled LOW
	SPI_Write_Byte(0x0C);    // Select Shutdown register
	SPI_Write_Byte(0x01);    // Set D0 bit to return to normal operation
	set_bit(PORTB, CS) ;     // CS pin is pulled HIGH
	
	// Set BCD decode mode for digits DIG0-DIG3
	rst_bit(PORTB, CS);		 // CS pin is pulled LOW
	SPI_Write_Byte(0x09);    // Select Decode Mode register
	SPI_Write_Byte(0x0F);    // Select BCD mode for digits DIG0-DIG3
	set_bit(PORTB, CS);       // CS pin is pulled HIGH
	
	// Set display brightness
	rst_bit(PORTB, CS);		 // CS pin is pulled LOW
	SPI_Write_Byte(0x0A);    // Select Intensity register
	SPI_Write_Byte(0x0a);    // Set maximum brightness
	set_bit(PORTB, CS);       // CS pin is pulled HIGH
	
	// Set display refresh
	rst_bit(PORTB, CS);		 // CS pin is pulled LOW
	SPI_Write_Byte(0x0B);    // Select Scan-Limit register
	SPI_Write_Byte(0x03);    // Select digits DIG0-DIG3
	set_bit(PORTB, CS);      // CS pin is pulled HIGH
	
	// Enable Display-Test
	rst_bit(PORTB, CS);		 // CS pin is pulled LOW
	SPI_Write_Byte(0x0F);    // Select Display-Test register
	SPI_Write_Byte(0x01);    // Enable Display-Test
	set_bit(PORTB, CS);      // CS pin is pulled HIGH
	
	_delay_ms(1000);
	// Disable Display-Test
	rst_bit(PORTB, CS);		 // CS pin is pulled LOW
	SPI_Write_Byte(0x0F);    // Select Display-Test register
	SPI_Write_Byte(0x00);    // Disable Display-Test
	set_bit(PORTB, CS);      // CS pin is pulled HIGH
}

void MaxDriver::displaySignal(unsigned int digit, unsigned int number)
{
	rst_bit(PORTB, CS);				// CS pin is pulled LOW
	SPI_Write_Byte(digit);			// Select the digit
	SPI_Write_Byte(number);			//Send Number
	set_bit(PORTB, CS);				// CS pin is pulled HIGH
	
}

void MaxDriver::resetDisplay()
{
	rst_bit(PORTB, CS);			   // CS pin is pulled LOW
	SPI_Write_Byte(1);			   // Select the digit
	SPI_Write_Byte(0);			   //Send Number
	set_bit(PORTB, CS);			   // CS pin is pulled HIGH
	
	rst_bit(PORTB, CS);			   // CS pin is pulled LOW
	SPI_Write_Byte(0);			   // Select the digit
	SPI_Write_Byte(0);			   //Send Number
	set_bit(PORTB, CS);			   // CS pin is pulled HIGH
}