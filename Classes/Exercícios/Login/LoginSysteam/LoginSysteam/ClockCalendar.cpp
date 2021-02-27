#include "ClockCalendar.h"

inline ClockCalendar::ClockCalendar(unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int min, unsigned int sec, bool isPM)
	: Clock(hour, min, sec, isPM), Calendar(year, month, day) { }

inline void ClockCalendar::advance() {
	bool wasPm = Clock::isPM; // save current pm.
	Clock::advance();
	if ((wasPm == true) && (Clock::isPM == false))
		Calendar::advance();
}

inline void ClockCalendar::writeClock() {
	std::cout << setw(4) << setfill('0') << year;
	std::cout << "/";
	std::cout << setw(2) << setfill('0') << month;
	std::cout << "/";
	std::cout << setw(2) << setfill('0') << day;
	std::cout << " - ";
	std::cout << setw(2) << setfill('0') << hour;
	std::cout << ":";
	std::cout << setw(2) << setfill('0') << min;
	std::cout << ":";
	std::cout << setw(2) << setfill('0') << sec;
	std::cout << (isPM ? " pm" : " am") << std::endl;
}

inline void ClockCalendar::showClock() {
	Calendar::readCalendar(year, month,day);
	Clock::readClock(hour, min, sec, isPM);
	ClockCalendar::writeClock();
}
