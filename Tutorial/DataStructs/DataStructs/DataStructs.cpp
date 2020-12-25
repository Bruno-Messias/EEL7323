/* DataStructs.cpp : Intro to some structure datas
*  Date: 25/12/2020
*  Author: Bruno C. Messias
*/
#include <iostream>
#include <vector> //for vectors


void print_vector(std::vector<int> data)
{
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << "\t";
    }
    std::cout << "\n";
}

int main()
{
    int guesses[] = {10, 11, 12, 32};

    std::cout << guesses[3] << std::endl;

    //Using vectors
    std::vector<int> data = { 1,2,3 };
    data.push_back(12);
    std::cout << data[data.size() - 1] << std::endl;
    
    std::cout << data.size() << std::endl;
    data.pop_back();                     
    std::cout << data.size() << std::endl;

    print_vector(data);

    return 0;
}

