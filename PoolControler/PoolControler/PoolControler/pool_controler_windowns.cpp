#include "pool_controler_windowns.h"

void PoolControlerWindowns::inputSW()
{
    std::cout << "SW?: " << std::endl;
    std::cin >> insertSW;
    if (insertSW == 1)
    {
        sw = true;
    }
    else sw = false;
}

//TODO: Finish FSM
void PoolControlerWindowns::FSM()
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
            PoolControlerWindowns::displayTimer();
            Sleep(sec);
            //? Need Test!
            if (_kbhit()) //If keyboard pressed check if reset is pressed
            {
                switch (_getch())
                {
                case 49:// press 1 to reset
                    estate = 1;
                    break;
                default:
                    estate = 4;
                    continue;
                }
            }
            
            if (Timer::getTime() <= 60)
            {
                low = true;
                std::cout << "Low time Alert!" << std::endl;
            }
        }
        low = false
        break;
    case 3: //ON2

        //Next Estate:
        Timer::resetTimer();
        while (Timer::getTime() <= 1800)
        {
            Timer::coutTimer();
            PoolControlerWindowns::displayTimer();
            Sleep(sec);

            //? Need Test!
            if (_kbhit()) //If keyboard pressed check if reset is pressed
            {
                switch (_getch())
                {
                case 49:// press 1 to reset
                    estate = 1;
                    break;
                default:
                    estate = 4;
                    continue;
                }
            }
            if (Timer::getTime() <= 60)
            {
                low = true;
                std::cout << "Low time Alert!" << std::endl;
            }

        }
        low = false;
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
            Timer::coutTimer();
            Sleep(sec);
        }
        pump = false;
        estate = 0;
        break;
    default:
        estate = 0;
        break;
    }
}

void PoolControlerWindowns::Inputs()
{
    //TODO: FInish Inputs 
    switch (estate)
    {
    case 0: //RESET
        std::cout << "Initiate?" << std::endl;
        std::cin >> insertReset;
        if (insertReset == 1)
        {
            reset = true;
        }
        else reset = false;
        break;
    case 1: //INIT
        //Next Estate
        break;
    case 2: //ON1
        break;
    case 3: //ON2

        break;
    case 4: //OFF1

        break;
    case 5: //OFF2  

        break;
    default:
        break;
    }
}

void PoolControlerWindowns::Outputs()
{
    switch (estate)
    {
    case 0: //RESET
        std::cout << "------------ Controler Pool ----------" << std::endl;
        std::cout << "For Reset Timer press 1 anytime " << std::endl;
    case 1: //INIT
        //Next Estate
        break;
    case 2: //ON1
        std::cout << "------ Initiating Timer 60s -----" << std::endl;
        Sleep(100);
        system("cls");
        break;
    case 3: //ON2
        std::cout << "------ Initiating Timer 30s -----" << std::endl;
        Sleep(100);
        system("cls");
        break;
    case 4: //OFF1
        std::cout << "------ Powering OFF the System -----" << std::endl;
        Sleep(100);
        system("cls");
        break;
    case 5: //OFF2  
        std::cout << "--------------- System OFF  ----------------" << std::endl;
        std::cout << "------ Thank you for using our system! -----" << std::endl;
        Sleep(100);
        system("cls");
    default:
        break;
    }
}

void PoolControlerWindowns::displayTimer()
{
    system("cls");
    std::cout << "--------- Timer ----------" << std::endl;
    minuteTimer = Timer::getTime();
    minuteTimer = minuteTimer / 60;
    minuteTimer = 60 - minuteTimer;
    std::cout << "    " << minuteTimer << std::endl;
    std::cout << "--------------------------" << std::endl;
}

