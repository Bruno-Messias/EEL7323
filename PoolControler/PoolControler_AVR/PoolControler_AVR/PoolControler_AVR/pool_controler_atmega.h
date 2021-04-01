#ifndef POOL_CONTROLER_ATMEGA_H
#define POOL_CONTROLER_ATMEGA_H


#include "MAX7219_driver.cpp"

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>

#include "pins_atmega328p.h"
#include "pool_controler.cpp"
#include "ClockCalendar.h"
#include "timer.cpp"
//#include "List.cpp"
#include "USART.cpp"

#define secs 1000
#define minute 60000

class PoolControlerAtmega : public PoolControler
{
	//List data;
	ClockCalendar cc; 
	Timer time;
	MaxDriver led;
	int estate, value;
	bool init,sw;
	unsigned char event;
public:
	PoolControlerAtmega();
	~PoolControlerAtmega() { }
	virtual void inputSW();
	virtual void FSM();
	virtual void Inputs(){};
	virtual void Outputs(){};
	void setEstate(int);
	void displayTimer();
	void checkLog();
};

#endif // !POOL_CONTROLER_ATMEGA_H


