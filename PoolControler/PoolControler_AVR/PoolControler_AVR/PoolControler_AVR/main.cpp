/*
 * PoolControler_AVR.cpp
 *
 * Created: 21/03/2021 16:20:44
 * Author : Bruno C. Messias 
 */ 

bool flag = false; //flag interrupt, global variable

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
			if(flag)
			{
				Controler.setEstate(1);  //If interrupt occur the next estate is INIT to reset the timer
				flag = false;
			}
	}
	
	return 0;
}

