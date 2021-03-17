#include "pool_controler_atmega.h"

#include "pool_controler.cpp"

void PoolControlerAtmega::FSM()
{
    switch (estate)
    {
    case 0: //RESET
        timeout = true;
        pump = false;
        heater = false;
        low = false;

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
            low = true;
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
            low = true;
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
        low = false;
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

void PoolControlerAtmega::Inputs()
{

}

void PoolControler::Outputs()
{

}