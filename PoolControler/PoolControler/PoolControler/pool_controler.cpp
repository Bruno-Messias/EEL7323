
#include "pool_controler.h"

PoolControler::PoolControler()
{
    timeout = false;
    pump = false; 
    heater = false;
    estate = 0;
}
PoolControler::~PoolControler() { }

void PoolControler::FSM()
{
    switch (estate)
    {
    case 0: //RESET
        timeout = true;
        pump = false;
        heater = false;

        if (reset)
        {
            estate = 1;
            break;
        }
        else
        {
            estate = 0;
            break;
        }
    case 1: //INIT
        reset = false;
        timeout = false;
        pump = true;
        heater = true;
        //Next Estate:
        if (sw)
        {
            estate = 3;
            break;
        }
        else
        {
            estate = 2;
            break;
        }
    case 2: //ON1
        
        //Next Estate:
        Timer::resetTimer();
        while (Timer::getTime() <= 3600)
        {
            Timer::coutTimer();
            //TODO: Add sleep function
            //TODO: Add low time signal
            if (reset)
            {
                estate = 1;
                break;
            }
        }
        estate = 4;
        break;
    case 3: //ON2

        //Next Estate:
        Timer::resetTimer();
        while (Timer::getTime() <= 1800)
        {
            Timer::coutTimer();
            //TODO: Add sleep funcion
            //TODO: Add low time signal
            if (reset)
            {
                estate = 1;
                break;
            }
        }
        estate = 4;
        break;
    case 4: //OFF1
        timeout = true;
        heater = false;
        estate = 5;
        break;
    case 5: //OFF2
        
        //Next Estate:
        Timer::resetTimer();
        while (Timer::getTime() <= 60)
        {
            Timer::coutTimer()
            //TODO: Add sleep function
        }
        pump = false;
        estate = 0;
        break;
    default:
        estate = 0;
        break;
    }
      
}