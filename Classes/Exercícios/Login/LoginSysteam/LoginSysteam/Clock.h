#ifndef CLOCK
#define CLOCK

class Clock {
protected:
	unsigned int hour, min, sec;
	bool isPM;
public:
	inline Clock(unsigned int hour, unsigned int min, unsigned int sec, bool isPM);
	inline ~Clock();
	inline void setClock(unsigned int hour, unsigned int min, unsigned int sec, bool isPM);
	inline void readClock(unsigned int& hour, unsigned int& min, unsigned int& sec, bool& isPM);
	inline void advance();
};

#endif		// CLOCK