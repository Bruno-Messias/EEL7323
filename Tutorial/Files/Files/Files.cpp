/* Files.cpp : Working with files
Date : 25 / 12 / 2020
Author : Bruno c.Messias
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main()
{
    //std::string filename; //choose the filename
    //std::cin >> filename;

    ////! Creating File
    ////! 
    //std::ofstream file (filename);
    ////check if the file is open
    //if (file.is_open())
    //{
    //    std::cout << "File is sucessuful opened" << std::endl;
    //}


    //std::vector<std::string> names;
    //names.push_back("Element1");
    //names.push_back("Element2");
    //names.push_back("Element3");

    //for (std::string name : names)
    //{
    //    file << name << std::endl;
    //}

    //file.close();

    //! Reading a file

    std::ifstream file ("hello");

    if (file.is_open())
    {
        std::cout << "It's working\n";
    }

    std::vector<std::string> names;
    
    std::string input;

    while (file >> input) //return file
    {
        names.push_back(input);
    }

    for (std::string name : names)
    {
        std::cout << name << std::endl;
    }

    ////! other way to read a a file(by lines)
    //


    return 0;
}

