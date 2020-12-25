/* ConditionalStatement.cpp : Conditional statement example
*  Date: 24/12/2020
*  Author: Bruno C. Messias
*/
#include <iostream>

int main()
{
    int ans = 11;
    std::cout << "Guess: \n";

    int g;
    std::cin >> g;

    g == ans ? std::cout << "good\n" : std::cout << "bad\n"; //conditional statement

}

// Run program: Ctrl + F5 or Debug > Sta