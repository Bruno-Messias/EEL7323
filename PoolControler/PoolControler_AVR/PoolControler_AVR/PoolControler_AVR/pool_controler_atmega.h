#ifndef POOL_CONTROLER_ATMEGA_H
#define POOL_CONTROLER_ATMEGA_H

// -- Frequency --
#define F_CPU 16000000 // frequency oscillator

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "pool_controler.cpp"
#include "timer.cpp"

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

class PoolControlerAtmega : public PoolControler
{
	Timer time;
	int estate, value1, value2, value;
	bool timeout, pump, heater, reset, sw, low;
public:
	PoolControlerAtmega();
	~PoolControlerAtmega() { }
	virtual void inputSW();
	virtual void FSM();
	virtual void Inputs();
	virtual void Outputs();
	void setEstate(int);
	void displayTimer();
};

#endif // !POOL_CONTROLER_ATMEGA_H


