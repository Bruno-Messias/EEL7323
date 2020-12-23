/* SumArray.cpp : Implement a generic function that sum arrays
*  Date: 22/12/2020
*  Author: Bruno C. Messias
*/

#include <iostream>

//! Implementing a generic function

template <class T>
T sum(const T data[], int size, T s = 0)//s=0 is a default value
{
	for (int i = 0; i < size; i++)
	{
		s += data[i];
	}

	return s;
}

template <class T1, class T2>
void copy(const T1 source[], T2 destination[], int size)
{
	for (int i = 0; i < size; i++)
	{
		destination[i] = static_cast<T2>(source[i]); //! using safe casting 
	}

}

/*//! are 4 types of casting

static_cast -> safe
reinterpret_cast -> highly unsafe
dynamic_cast -> used with classes
const_cast -> cast away const-ness - const away the type

*/


int main()
{
	std::cout << "template for sum()" << std::endl;

	int a[] = { 1, 2, 3 };
	double b[] = { 2.1, 2.2, 2.3 };
	double c[] = { 0.0, 0.0, 0.0 };

	std::cout << ::sum(a, 3) << std::endl;
	std::cout << ::sum(b, 3) << std::endl;

	::copy(a, c, 3);

	std::cout << "Copy template" << std::endl;
	std::cout << ::sum(c,3,0.6) << std::endl; //transforming a array into double and sum

	return 0;
}
