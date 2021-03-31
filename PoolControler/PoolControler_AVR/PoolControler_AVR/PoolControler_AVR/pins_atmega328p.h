#ifndef PINS_H
#define PINS_H

//Pins Avr
#include <avr/io.h>

//-- Defining Macros for pins

//set a bit in a register
#define set_bit(reg,bit)	(reg |= (1<<bit))
// reset a bit in a register
#define rst_bit(reg,bit)	(reg &= ~(1<<bit))
// test a bit
#define test_bit(reg,bit)	(reg & (1<<bit)) //Press -> low

/*
pump -> PB3 -> d11
heater -> PB4 -> d12
interrupt -> reset - PB5/PCINT5 d13
sw -> PB2 -> d10
low -> PB1 -> d9
display(d7.d6.d5) -> PD's(5,6,7)
*/

//TODO: change some pins to use arduino interface pins with crystal oscillator use D's port

//-- Defining Pins 
#define pump_bit PORTB7
#define heater_bit PORTB6
#define reset_bit PORTB0
#define sw_bit PORTB4
#define low_bit PORTB1

// Define for SPI transmitter pins
#define PIN_SCK PORTB5
#define PIN_MOSI PORTB3
#define PIN_SS PORTB2

#endif //PINS_H