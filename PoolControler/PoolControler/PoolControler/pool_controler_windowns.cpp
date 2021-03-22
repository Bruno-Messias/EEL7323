#include "pool_controler_windowns.h"

PoolControlerWindowns::PoolControlerWindowns()
{
    estate = 0;
    sw = false;
    pump = false;
    heater = false;
    timeout = false;
    reset = false;
    sw = false;
    low = false;
    minuteTimer = 0;
    insertSW = 0;
    insertReset = 0;
}

void PoolControlerWindowns::inputSW()
{
    std::cout << "SW: 0 for 60min; 1 for 30min " << std::endl;
    std::cin >> insertSW;
    if (insertSW == 1)
    {
        sw = true;
    }
    else sw = false;
}

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
        time.setTimer(60);
        while (time.getTime() > 0)
        {
            if (time.getTime() < 5)
            {
                low = true;
                std::cout << "Low time Alert!" << std::endl;
            }

            time.coutTimer();
            PoolControlerWindowns::displayTimer();
            Sleep(minute);
            if (_kbhit()) //If keyboard pressed check if reset is pressed
            {
                switch (_getch())
                {
                case 49:// press 1 to reset
                    estate = 1;
                    break;
                default:
                    continue;
                }
            }
            if (estate == 1)
                break;

            estate = 4;
        }
        low = false;
        break;
    case 3: //ON2

        //Next Estate:
        time.setTimer(30);
        while (time.getTime() > 0)
        {
            if (time.getTime() < 5)
            {
                low = true;
            }

            time.coutTimer();
            PoolControlerWindowns::displayTimer();
            Sleep(minute);
            if (_kbhit()) //If keyboard pressed check if reset is pressed
            {
                switch (_getch())
                {
                case 49:// press 1 to reset
                    estate = 1;
                    break;
                default:
                    continue;
                }
            }
            if (estate == 1)
                break;

            estate = 4;
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
        time.setTimer(1);
        while (time.getTime() > 0)
        {
            time.coutTimer();
            Sleep(minute);
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
    switch (estate)
    {
    case 0: //RESET
        std::cout << "------------ Controler Pool ----------" << std::endl;
        std::cout << "For Initiate or Reset Timer Press 1" << std::endl;
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
        break;
    case 1: //INIT

        //Next Estate
        break;
    case 2: //ON1

        //Next Estate
        std::cout << std::endl;
        std::cout << "------ Initiating Timer 60min -----" << std::endl;
        Sleep(500);
        system("cls");
        break;
    case 3: //ON2

        //Next Estate
        std::cout << std::endl;
        std::cout << "------ Initiating Timer 30min -----" << std::endl;
        Sleep(500);
        system("cls");
        break;
    case 4: //OFF1

        //Next Estate
        std::cout << std::endl;
        std::cout << "------ Powering OFF the System -----" << std::endl;
        Sleep(500);
        system("cls");
        break;
    case 5: //OFF2 

        //Next Estate
        std::cout << std::endl;
        std::cout << "--------------- System OFF  ----------------" << std::endl;
        std::cout << std::endl;
        std::cout << "------ Thank you for using our system! -----" << std::endl;
        Sleep(1000);
        system("cls");
    default:
        break;
    }
}

void PoolControlerWindowns::displayTimer()
{
    system("cls");
    std::cout << "--------- Timer ----------" << std::endl;
    minuteTimer = time.getTime();
    std::cout << "    " << minuteTimer << std::endl;
    std::cout << "--------------------------" << std::endl;
    if (minuteTimer < 5)
    {
        std::cout << "Alert Low timer remaining!" << std::endl;
    }
}

void PoolControlerWindowns::setEstate(int newEstate)
{
    estate = newEstate;
}