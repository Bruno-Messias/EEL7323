//Declarations of utils
#ifndef UTILS
#define UTILS

struct Retangle
{
    double length;
    double width;
};

namespace utilz 
{

    double area(double length, double width);

    double area(Retangle ret);

    double pow(double base, int pow = 2);

    void swap(int& a, int& b);
}

#endif // !UTILS


