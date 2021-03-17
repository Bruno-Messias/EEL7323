//timer_windowns.h
#ifndef TIMER_WINDOWNS_H
#define TIMER_WINDOWNS_H

#include <windows.h>
#include <iostream>

#define sec 1000

class timer {
	int time;
public:
	timer();
	~timer();
	void CoutTimer();
	void ResetTimer();
	int GetTime();
};

#endif // !TIMER_WINDOWNS_H