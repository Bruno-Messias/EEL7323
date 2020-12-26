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

    // Adding template function
    template <typename T>
    void swap(T& a, T& b)
    {
        T temp = a;
        a = b;
        b = temp;
    }

    // Adding template overloading function
    template <typename T>
    void swap(T a[], T b[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            T temp = a[i];
            a[i] = b[i];
            b[i] = temp;
        }
    }
}

#endif // !UTILS


