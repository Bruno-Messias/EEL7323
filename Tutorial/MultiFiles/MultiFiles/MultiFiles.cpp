/* MultiFiles.cpp : Implement multi file compilation
*  Date: 26/12/2020
*  Author: Bruno C. Messias
*/
#include <iostream>
#include <string>
#include "utils.h"

int main()
{
    Retangle ret;
    ret.length = 10;
    ret.width = 10;

    std::cout << utilz::area(ret.length, ret.width) << "\n";
    std::cout << utilz::area(ret) << "\n";
    std::cout << utilz::pow(3,3) << "\n";
    std::cout << utilz::pow(3) << "\n";

    int a = 10, b = 20;

    utilz::swap(a, b);
    std::cout << "a = " << a << " b = " << b << "\n";

    std::string first = "Hi";
    std::string last = "Bye";

    utilz::swap(first, last);

    std::cout << first << "\t" << last << "\n";

    int const SIZE = 3;
    int nines[] = { 9,9,9 };
    int ones[] = { 1,1,1 };

    for (int i = 0; i < SIZE; i++)
    {
        std::cout << nines[i] << " " << ones[i] << "\t";
    }
    std::cout << "\n\n";

    utilz::swap(nines, ones, SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        std::cout << nines[i] << " " << ones[i] << "\t";
    }
    

    return 0;
}
