#ifndef CLOCKCALENDAR
#define CLOCKCALENDAR

#include <iostream>
#include <iomanip>

#include "Clock.cpp"
#include "Calendar.cpp"

using namespace std;

class ClockCalendar : public Clock, public Calendar {
public:
	ClockCalendar(unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int min, unsigned int sec, bool isPM);
	~ClockCalendar();
	void advance();
	void writeClock();
};

#endif		// CLOCKCALENDAR