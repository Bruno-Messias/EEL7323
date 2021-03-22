//Pins ATmega
#include <avr/io.h>

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

#define pump_bit PORTB3
#define heater_bit PORTB4
#define reset_bit PORTB5
#define sw_bit PORTB2
#define low_bit PORTB1