#include "timer.h"

Timer::Timer()
{
	timer = 0;
}

Timer::~Timer() { }

void Timer::coutTimer()
{
	timer--;
}
void Timer::setTimer(int newTimer)
{
	timer = newTimer;
}
int Timer::getTime()
{
	return timer;
}