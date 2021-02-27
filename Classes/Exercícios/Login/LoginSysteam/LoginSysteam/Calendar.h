#ifndef CALENDAR
#define CALENDAR

class Calendar {
public:
	inline Calendar(unsigned int year, unsigned int month, unsigned int day);
	inline ~Calendar();
	inline void setCalendar(unsigned int year, unsigned int month, unsigned int day);
	inline void readCalendar(unsigned int& year, unsigned int& month, unsigned int& day);
	inline void advance();
private:
	unsigned int year, month, day;
};

#endif		// CALENDAR