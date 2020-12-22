/* SwapFunction.cpp : Implement swap pointers function
*  Date: 21/12/2020
*  Author: Bruno C. Messias
*/

#include <iostream>
#include <complex>

using namespace std;

inline void swap(int& i, int& j) //inline is more efficint
//! call by reference
// int& -> signature of the arguments
{
    int temp = i; 
    i = j;
    j = temp;
}

inline void swap(double& i, double& j)//! only use inline for small function
{
    double temp = i;
    i = j;
    j = temp;
}

//! C++ has overloading(can have two function with the same name without problems) and call by reference

//! Adding template(generic function)

template <class T> //! capitalized T is a convencion (meta variable)

inline void swap(T& d, T& s)
{
    T temp = d;
    d = s;
    s = temp;
}

int main()
{
    int m = 5, n = 10;
    double x = 5.3, y = 10.6;

    complex<double> r(2.4, 3.5), s(3.4, 6.7);

    cout << "inputs: " << m << "," << n << endl;
    swap(m, n);
    cout << "outputs: " << m << "," << n << endl;

    cout << "double inputs: " << x << "," << y << endl;
    swap(x, y);
    cout << "double outputs: " << x << "," << y << endl;

    cout << "complex inputs: " << r << "," << s << endl;
    swap(r, s);
    cout << "complex outputs: " << r << "," << s << endl;

    return 0;
}