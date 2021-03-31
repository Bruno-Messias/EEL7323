#ifndef POOL_CONTROLER_ATMEGA_H
#define POOL_CONTROLER_ATMEGA_H


#include "MAX7219_driver.cpp"

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "pins_atmega328p.h"
#include "pool_controler.cpp"
#include "ClockCalendar.cpp"
#include "timer.cpp"

#define sec 1000
#define minute 60000

class PoolControlerAtmega : public PoolControler
{
	ClockCalendar cc; //TODO define time
	Timer time;
	MaxDriver led;
	int estate, value;
	bool timeout, pump, heater, reset, sw, low, init;
	unsigned char event;
public:
	PoolControlerAtmega();
	~PoolControlerAtmega() { }
	virtual void inputSW();
	virtual void FSM();
	virtual void Inputs();
	virtual void Outputs();
	void setEstate(int);
	void displayTimer();
	unsigned char checkLog();
};

#endif // !POOL_CONTROLER_ATMEGA_H


