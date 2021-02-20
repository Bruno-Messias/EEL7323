// Calendar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Classes.h"

int main()
{
    Calendar contagem;

    contagem.setCalendar();

    while (true) {
        Sleep(sec);
        contagem.coutCalendar();
        contagem.showCalendar();
    }

    return 0;
}
