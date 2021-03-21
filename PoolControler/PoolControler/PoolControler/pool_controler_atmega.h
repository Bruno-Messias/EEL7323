#ifndef POOL_CONTROLER_ATMEGA_H
#define POOL_CONTROLER_ATMEGA_H

#include "pool_controler.cpp"
#include "timer.cpp"

class PoolControlerAtmega : public PoolControler
{
	Timer time;
	bool timeout, pump, heater, reset, sw, low;
	int estate;
public:
	PoolControlerAtmega();
	void inputSW() override;
	void FSM() override;
	void Inputs() override;
	void Outputs() override;
};


#endif // !POOL_CONTROLER_ATMEGA_H


