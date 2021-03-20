// PoolControler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "pool_controler_windowns.cpp"
//#include "pool_controler_atmega.cpp"

int main()
{
    PoolControlerWindowns Controler;
    Controler.inputSW();

    while (1)
    {
        Controler.Inputs();
        Controler.Outputs();
        Controler.FSM();
    }
    
    return 0;
}


