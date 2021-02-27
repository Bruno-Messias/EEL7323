#include "Calendar.h"

inline Calendar::Calendar(unsigned int year, unsigned int month, unsigned int day) {
	this->year = year;
	this->month = month;
	this->day = day;
}

inline Calendar::~Calendar() { }

inline void Calendar::setCalendar(unsigned int year, unsigned int month, unsigned int day) {
	this->year = year;
	this->month = month;
	this->day = day;
}

inline void Calendar::readCalendar(unsigned int& year, unsigned int& month, unsigned int& day) {
	year = this->year;
	month = this->month;
	day = this->day;
}

inline void Calendar::advance() {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) { //leap year
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if (day < 30)
				day++;
			else {
				if (month < 11) {
					month++;
					day = 1;
				}
				else {
					year++;
					month = 1;
					day = 1;
				}
			}
		}
		if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (day < 29)
				day++;
			else {
				if (month < 11) {
					month++;
					day = 1;
				}
				else {
					year++;
					month = 1;
					day = 1;
				}
			}
		}
		if (month == 2) {
			if (day < 28)
				day++;
			else {
				if (month < 11) {
					month++;
					day = 1;
				}
				else {
					year++;
					month = 1;
					day = 1;
				}
			}
		}
	}
	else {
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if (day < 30)
				day++;
			else {
				if (month < 11) {
					month++;
					day = 1;
				}
				else {
					year++;
					month = 1;
					day = 1;
				}
			}
		}
		if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (day < 29)
				day++;
			else {
				if (month < 11) {
					month++;
					day = 1;
				}
				else {
					year++;
					month = 1;
					day = 1;
				}
			}

		}
		if (month == 2)
			if (day < 27)
				day++;
			else {
				if (month < 11) {
					month++;
					day = 1;
				}
				else {
					year++;
					month = 1;
					day = 1;
				}
			}
	}
}

