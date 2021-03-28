#ifndef POOL_CONTROLER_ATMEGA_H
#define POOL_CONTROLER_ATMEGA_H

// -- Frequency --
#define F_CPU   1000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "pins_atmega328p.h"
#include "pool_controler.cpp"
#include "timer.cpp"
#include "MAX7219_driver.cpp"

#define sec 1000
#define minute 60000

class PoolControlerAtmega : public PoolControler
{
	Timer time;
	MaxDriver led;
	int estate, value;
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


