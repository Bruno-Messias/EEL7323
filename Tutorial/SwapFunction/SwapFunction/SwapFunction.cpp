/* SwapFunction.cpp : Implement swap pointers function
*  Date: 21/12/2020
*  Author: Bruno C. Messias
*/

#include <iostream>

using namespace std;

inline void swap(int& i, int& j) //inline is more efficint
//! call by reference
// int& -> signature of the arguments
{
    int temp = i; 
    i = j;
    j = temp;
}

inline void swap(double& i, double& j)
{
    double temp = i;
    i = j;
    j = temp;
}

//! C++ has overloading(can have two function with the same name without problems) and call by reference

int main()
{
    int m = 5, n = 10;
    double x = 5.3, y = 10.6;

    cout << "inputs: " << m << "," << n << endl;
    swap(m, n);
    cout << "outputs: " << m << "," << n << endl;

    cout << "double inputs: " << x << "," << y << endl;
    swap(x, y); //! C understand the signature name of the type of the variable
    cout << "double outputs: " << x << "," << y << endl;

    return 0;
}
