#include "ClockCalendar.h"

using namespace std;

inline ClockCalendar::ClockCalendar(unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int min, unsigned int sec, bool isPM)
	: Clock(hour, min, sec, isPM), Calendar(year, month, day) { }

inline ClockCalendar::~ClockCalendar() { }

inline void ClockCalendar::advance() {
	bool wasPm = Clock::isPM; // save current pm.
	Clock::advance();
	if ((wasPm == true) && (Clock::isPM == false))
		Calendar::advance();
}

inline void ClockCalendar::writeClock() {
	cout << setw(4) << setfill('0') << year;
	cout << "/";
	cout << setw(2) << setfill('0') << month;
	cout << "/";
	cout << setw(2) << setfill('0') << day;
	cout << " - ";
	cout << setw(2) << setfill('0') << hour;
	cout << ":";
	cout << setw(2) << setfill('0') << min;
	cout << ":";
	cout << setw(2) << setfill('0') << sec;
	cout << (isPM ? " pm" : " am") << endl;
}

inline void ClockCalendar::showClock() {
	Calendar::readCalendar(year, month,day);
	Clock::readClock(hour, min, sec, isPM);
	ClockCalendar::writeClock();
}