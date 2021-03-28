class Clock {
	protected:
	int hr, min, sec, isPm;
	public:
	Clock (int h, int m, int s, int pm);
	void setClock (int h, int m, int s, int pm);
	void readClock (int& h, int& m, int& s, int& pm);
	void advance ();
};

class Calendar {
	protected:
	int mo, day, yr;
	public:
	Calendar (int m, int d, int y);
	void setCalendar (int m, int d, int y);
	void readCalendar (int& m, int& d, int& y);
	void advance ();
};

class ClockCalendar : public Clock, public Calendar {
	public:
	ClockCalendar (int mt, int d, int y, int h, int m, int s, int pm);
	void advance ();
};
