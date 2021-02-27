#include "ClockCalendar.h"

using namespace std;

ClockCalendar::ClockCalendar(unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int min, unsigned int sec, bool isPM)
	: Clock(hour, min, sec, isPM), Calendar(year, month, day) {

}

ClockCalendar::~ClockCalendar() { }

void ClockCalendar::advance() {
	bool wasPm = Clock::isPM; // save current pm.
	Clock::advance();
	if ((wasPm == true) && (Clock::isPM == false))
		Calendar::advance();
}

void ClockCalendar::writeClock() {
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
