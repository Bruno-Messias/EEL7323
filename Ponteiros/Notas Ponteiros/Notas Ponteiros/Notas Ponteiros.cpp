/* Notas Ponteiros.cpp : This file contains the 'main' function. Program execution begins and ends there.
    Author: Bruno C. Messias
    Date: 06/02/2021
*/

#include <iostream>

typedef struct {
    int largura;
    int altura;
    unsigned* bits;
} Image;

int main() {

    Image pic1;
    Image *pImage = &pic1;
    pic1.largura = 100;

    std::cout << "pic1.largura == " << pic1.largura << std::endl;
    std::cout << "pImage->largura == " << pImage->largura << std::endl;
    std::cout << "(*pImage).largura == " << (*pImage).largura << std::endl;
    std::cout << "(&pic1)->largura == " << (&pic1)->largura << std::endl;

    (*pImage).largura = 50;

    std::cout << "pic1.largura == " << pic1.largura << std::endl;
    std::cout << "pImage->largura == " << pImage->largura << std::endl;
    std::cout << "(*pImage).largura == " << (*pImage).largura << std::endl;
    std::cout << "(&pic1)->largura == " << (&pic1)->largura << std::endl;

    return 0;
}
