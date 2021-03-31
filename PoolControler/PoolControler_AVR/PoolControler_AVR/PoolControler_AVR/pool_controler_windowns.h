#ifndef POOL_CONTROLER_WINDOWNS_H
#define POOL_CONTROLER_WINDOWNS_H

#include "pool_controler.cpp"
#include "timer.cpp"

#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>

#define secs 1000
#define minute 60000

class PoolControlerWindowns: public PoolControler
{
	Timer time;
	bool timeout, pump, heater, reset, sw, low;
	int estate, insertSW, insertReset, minuteTimer;
public:
	PoolControlerWindowns();
	void inputSW() override;
	void FSM() override;
	void Inputs() override;
	void Outputs() override;
	void displayTimer();
};

#endif // !POOL_CONTROLER_WINDOWNS_H
