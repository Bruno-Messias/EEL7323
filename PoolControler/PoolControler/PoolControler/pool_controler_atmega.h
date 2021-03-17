#ifndef POOL_CONTROLER_ATMEGA_H
#define POOL_CONTROLER_ATMEGA_H

#include "pool_controler.cpp"

class PoolControlerAtmega : public PoolControler
{
	bool timeout, pump, heater, reset, sw, low;
	int estate;
public:
	void FSM();
	void Inputs();
	void Outputs();
};


#endif // !POOL_CONTROLER_ATMEGA_H


