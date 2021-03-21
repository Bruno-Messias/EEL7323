/*
 * PoolControler_AVR.cpp
 *
 * Created: 21/03/2021 16:20:44
 * Author : Bruno C. Messias 
 */ 

//#include "pool_controler_windowns.cpp"
#include "pool_controler_atmega.cpp"

int main(void)
{
	//PoolControlerWindowns Controler;
	PoolControlerAtmega Controler;
	Controler.inputSW();
	
	while (1)
	{
		    Controler.Inputs();
		    Controler.Outputs();
		    Controler.FSM();
	}
	
	return 0;
}

