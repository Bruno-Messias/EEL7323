//timer_windowns.cpp
#include "timer_windons.h"

timer::timer()
{
	time = 0;
}

timer::~timer() { }

void timer::CoutTimer()
{
	time++;
}
void timer::ResetTimer()
{
	time = 0
}
int timer::GetTime()
{
	return time;
}