/* MultiFiles.cpp : Implement multi file compilation
*  Date: 26/12/2020
*  Author: Bruno C. Messias
*/
#include <iostream>
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
    
    return 0;
}
