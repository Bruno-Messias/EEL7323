//timer.h
#ifndef TIMER_H
#define TIMER_H

class Timer {
	int timer = 0;
public:
	Timer();
	~Timer();
	void coutTimer();
	void setTimer(int);
	int getTime();
};

#endif // !TIMER_H