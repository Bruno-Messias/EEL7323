/*
 *
 * Autor: Bruno Cayres Mesias
 *        <brunocmessias@hotmail.com>
 *
 * UFSC, CTC, EEL
 * Date: 27/02/2021
 *
 * Description: This program has been proposed in order to exercice
 *              the following concepts:
 *                 - Multiple Inheritance
 *                 - Constructors
 *                 - Output formatting (setw and setfill)
 *                 - Makefile
 *
 * Implemented inheritance:
 * -----------------------
 *
 *       Clock           Calendar
 *           \             /
 *            \           /
 *            ClockCalendar
 *                  |
 *                  |
 *                main
 * Files:
 * -----
 * Clock.h
 * Clock.cpp
 * Calendar.h
 * Calendar.cpp
 * ClockCalendar.h
 * ClockCalendar.cpp
*/

#include "ClockCalendar.cpp"

#include <time.h>

using namespace std;

int main()
{
	ClockCalendar cc(2021, 27, 2, 9, 34, 40, true);

	bool secondAdvanced = false;
	time_t now, elapsed;
	double seconds;

	while (true) {
		secondAdvanced = false;
		time(&now);
		while (!secondAdvanced) {
			time(&elapsed);
			seconds = difftime(elapsed, now);
			if (seconds == 1) {
				secondAdvanced = true;
				cc.advance();
				cc.showClock();
			}
		}
	}
	// buffer flush 
	cout.flush();
	return 0;
}
