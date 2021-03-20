#ifndef POOL_CONTROLER_WINDOWNS_H
#define POOL_CONTROLER_WINDOWNS_H

#include "pool_controler.cpp"
#include "timer.cpp"

#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>

#define sec 1000

class PoolControlerWindowns: public PoolControler
{
	Timer time
	bool timeout, pump, heater, reset, sw, low;
	int estate, insertSW, insertReset, minuteTimer;
public:
	void inputSW();
	void FSM();
	void Inputs();
	void Outputs();
	void displayTimer();
};

#endif // !POOL_CONTROLER_WINDOWNS_H
