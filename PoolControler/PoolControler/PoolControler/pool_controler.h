#ifndef POOL_CONTROLER_H
#define POOL_CONTROLER_H

#include "timer.cpp"

class PoolControler
{
	Timer time;
	bool timeout, pump, heater, reset, sw;
	int estate;
public:
	PoolControler();
	~PoolControler();
	void FSM();
	virtual void Inputs() = 0;
	virtual void Outputs() = 0;
};


#endif // !POOL_CONTROLER_H

