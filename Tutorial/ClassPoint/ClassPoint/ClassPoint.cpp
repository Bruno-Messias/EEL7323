/* ClassPoint.cpp : Implementing operations with points using classes
*  Date: 24/12/2020
*  Author: Bruno C. Messias
*/

#include <iostream>

class point
{
//public://simple tasks
//    point(double x = 0.0, double y = 0.0): x(x), y(y) {} //default Constructor sytax -> class_name():initializer list - Uses overloading, its better!
//    //point(): x(0.0), y(0.0) {} //Has initialized values
//    double getx() { return x; }//inline
//    void setx(double v) { x = v; }//mutator
//    double gety() { return y; }
//    void sety(double v) { y = v; }
//      
//private://hide -> representation
//    double x, y;

public:
    double x, y;
}; 
//! they are three keywords: public(open box), private(black box) and protected(inherance)

point operator+ (point& p1, point& p2)
{
    point sum = { p1.x + p2.x, p1.y + p2.y };
    return sum;
}

//! is good to every operator overloading its useful make a new << operator overloading of your new type
std::ostream& operator<< (std::ostream& out, const point& p)
{
    out << "(" << p.x << "," << p.y << ")";
    return out;
}
//Usual signatue for overloading ostream& operator<<
//(ostream& out, const my_type& v)
//both arguments are passed by reference
//my_type is passed with a const modifier so as not to be modifier

int main()
{
    point a = { 3.5, 2.5 }, b = { 2.5, 4.5 }, c;//constructor?
    std::cout << "a = " << a << " b = " << b << std::endl;
    std::cout << "sum = " << a + b << std::endl;
    
    return 0;
}