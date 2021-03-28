
#include "ClockCalendar.h"

Clock::Clock (int h, int m, int s, int pm){
	hr = h;
	min = m;
	sec = s;
	isPm = pm;
}
void Clock::setClock (int h, int m, int s, int pm){
	hr = h;
	min = m;
	sec = s;
	isPm = pm;
}
void Clock::readClock (int& h, int& m, int& s, int& pm){
	h = hr;
	m = min;
	s = sec;
	pm = isPm;
}
void Clock::advance (){
	if (sec < 59)
	sec++;
	else {
		sec = 0;
		if (min < 59)
		min++;
		else {
			min = 0;
			if (hr < 12)
			hr++;
			else {
				hr = 0;
			}
		}
	}
}



Calendar::Calendar (int m, int d, int y){};

void Calendar::setCalendar (int m, int d, int y){};

void Calendar::readCalendar (int& m, int& d, int& y){};

void Calendar::advance (){};

ClockCalendar::ClockCalendar (int mt, int d, int y, int h, int m, int s, int pm) : Clock (h, m, s, pm), Calendar (mt, d, y){
}

void ClockCalendar::advance (){ // avancar o calendario, caso o clock
	int wasPm = isPm;       // mude de AM para PM.
	Clock::advance();
	if (wasPm && !isPm)
	Calendar::advance();
}
