/* TypedefDays.cpp : Example of uses of typedef
*  Date: 23/12/2020
*  Author: Bruno C. Messias
*/

#include <iostream>

typedef enum days{SUN,MON,TUE,WED,THU,FRI,SAT} days; //! const in enum are capitelized as a convention

inline days operator++ (days &d) { //! creating new meaning to ++ operator
	return static_cast<days>((static_cast<int>(d) + 1) % 7); 
}

std::ostream& operator<< (std::ostream& out, const days& d) //!uses a binary operator << uses this rarely used type to new function
//! ostream& -> call by reference directly use IOSTREAM, more efficintly
{
	switch (d)
	{
		case SUN: out << "SUN"; break;
		case MON: out << "MON"; break;
		case TUE: out << "TUE"; break;
		case WED: out << "WED"; break;
		case THU: out << "THU"; break;
		case FRI: out << "FRI"; break;
		case SAT: out << "SAT"; break;
		default:
			break;
	}

	return out;
}

int main()
{
	days d = MON, e;
	e = ++d; //calling operator++(days)
	std::cout << d << '\t' << e << std::endl; //!using operator<< has a meaning

	return 0;
}
