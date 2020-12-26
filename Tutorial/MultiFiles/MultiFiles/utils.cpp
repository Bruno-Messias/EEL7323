//Definition of utils.cpp

#include "utils.h"

namespace utilz
{
    double area(double length, double width)
    {
        return length * width;
    }

    double area(Retangle ret)
    {
        return ret.length * ret.width;
    }

    double pow(double base, int pow)
    {
        double total = 1;
        for (int i = 0; i < pow; i++)
        {
            total *= base;
        }
        return total;
    }

    void swap(int& a, int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
}

