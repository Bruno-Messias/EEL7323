#include "pool_controler_atmega.h"
#include "pool_controler.cpp"

PoolControlerAtmega::PoolControlerAtmega()
{
    estate = 0;
    sw = false;
    pump = false;
    heater = false;
    timeout = false;
    reset = false;
    sw = false;
    low = false;
}

void PoolControlerAtmega::inputSW()
{
    //TODO: Add sw input 
}

//TODO: Finish FSW
void PoolControlerAtmega::FSM()
{
    switch (estate)
    {
    case 0: //RESET

        timeout = true;
        pump = false;
        heater = false;
        low = false;

        //Next Estate
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
    case 2: //ON1 - 60min config

        //Next Estate:
        time.setTimer(60);
        while (time.getTime() > 0 )
        {
            time.coutTimer();
            //TODO: Add sleep function
            //TODO: Add SPI cominucation with 7 digit driver
            //TODO Add low signal
            
            if (reset)
            {
                estate = 1;
                break;
            }
            else estate = 4;
        }
        break;

    case 3: //ON2 - 30min config

        //Next Estate:
        time.setTimer(30);
        while (time.getTime() > 0)
        {
            time.coutTimer();

            //TODO: Add sleep funcion
            //TODO: Add SPI cominucation with 7 digit driver
            //TODO Add low signal

            if (reset)
            {
                estate = 1;
                break;
            }
            else estate = 4;
        }
        break;
    case 4: //OFF1

        timeout = true;
        heater = false;
        low = false;

        //Next Estate
        estate = 5;
        break;
    case 5: //OFF2

        //Next Estate:
        time.setTimer(1);
        while (time.getTime() > 0)
        {
            time.coutTimer();
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
    //TODO: Add Inputs of Atmega 
}

void PoolControlerAtmega::Outputs()
{
    //TODO: add outpus of Atmega
}