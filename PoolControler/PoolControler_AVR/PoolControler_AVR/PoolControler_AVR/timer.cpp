#include "timer.h"

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