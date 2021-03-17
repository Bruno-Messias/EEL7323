//timer.h
#ifndef TIMER_H
#define TIMER_H

class Timer {
	int time;
public:
	Timer();
	~Timer();
	void coutTimer();
	void resetTimer();
	int getTime();
};

#endif // !TIMER_H