#ifndef POOL_CONTROLER_WINDOWNS_H
#define POOL_CONTROLER_WINDOWNS_H

#include "pool_controler.cpp"
#include "timer.cpp"

#include <windows.h>
#include <iostream>

#define sec 1000

class PoolControlerWindowns: public PoolControler
{
	Timer time
	bool timeout, pump, heater, reset, sw, low;
	int estate, insertSW, insertReset;
public:
	void inputSW();
	void FSM();
	void Inputs();
	void Outputs();
};

#endif // !POOL_CONTROLER_WINDOWNS_H
