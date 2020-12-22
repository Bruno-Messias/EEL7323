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

int main()
{
	std::cout << "template for sum()" << std::endl;

	int a[] = { 1, 2, 3 };
	double b[] = { 2.1, 2.2, 2.3 };

	std::cout << ::sum(a, 3) << std::endl;
	std::cout << ::sum(b, 3) << std::endl;

	return 0;
}