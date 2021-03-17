//timer_windowns.cpp
#include "timer.h"

Timer::Timer()
{
	time = 0;
}

Timer::~Timer() { }

void Timer::coutTimer()
{
	time++;
}
void Timer::resetTimer()
{
	time = 0
}
int Timer::getTime()
{
	return time;
}