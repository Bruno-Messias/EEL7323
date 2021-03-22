/*
 * PoolControler_AVR.cpp
 *
 * Created: 21/03/2021 16:20:44
 * Author : Bruno C. Messias 
 */ 

//#include "pool_controler_windowns.cpp"
#include "pool_controler_atmega.cpp"

int flag = 0; //flag interrupt

ISR(PCINT0_vect) //Interrupt Service Routine
{
	flag = 1;
}

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
			if(flag == 1)
			{
				Controler.setEstate(1);  //If interrupt occur the next estate is INIT to reset the timer
				flag = 0;
			}
	}
	
	return 0;
}

