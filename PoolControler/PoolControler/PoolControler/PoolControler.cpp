// PoolControler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

int minute = 0; int second = 0; int flag = 0;

void printData(int min, int sec)
{
    system("cls");
    std::cout << "1. Start 2. Stop" << std::endl;
    std::cout << "-------------------------" << std::endl ;
    std::cout << "     " <<min << ":" << sec << std::endl;
    std::cout << "-------------------------" << std::endl;
}

void selection()
{
    switch (_getch())
    {
    case 49:
        flag = 0;
        break;
    case 50:
        flag = 1;
        break;
    case 52:
        exit(0);
        break;
    default:
        break;
    }
}

void couter()
{
    while (!_kbhit() && flag ==0) //kbhit -> keyboard hit interrupt to detect if the user press th keyboard
    {
        if (second > 59)
        {
            minute++;
            second = 0;
        }
        
        if (minute > 59)
        {
            minute = 0;
        }
        
        printData(minute, second);
        Sleep(1000);
        ++second;
    }
    selection();
}


int main()
{
    while (1)
    {
       couter();
    }
    
    return 0;
}


