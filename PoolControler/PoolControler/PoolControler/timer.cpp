#include "timer.h"

Timer::Timer()
{
	timer = 0;
}

Timer::~Timer() { }

void Timer::coutTimer()
{
	timer++;
}
void Timer::resetTimer()
{
	timer = 0;
}
int Timer::getTime()
{
	return timer;
}