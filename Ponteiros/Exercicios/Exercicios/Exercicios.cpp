/* Exerc�cios.cpp : resolu��o de alguns exerc�cios sobre ponteiros
    Author: Bruno C. Messias
    Date: 07/02/2021
*/

#include <iostream>

/*
    Exerc�cio 1:
    p++: Vari�vel incrementada em +1
    (*p)++: O valor referenciado pelo ponteiro � incrementado em +1
    *(p++): A vari�vel P � incrementada e ap�s isso � referenciada

*/

int Exercise2()
{
    int y, * p, x; //Declara vari�veis y e x e o ponteiro p
    y = 0;        //Vari�vel y recebe valor 0
    p = &y;       //O ponteiro p recebe o endeder�o de y
    x = *p;       //Vari�vel x recebe o valor apontado por p
    x = 4;        //Vari�vel x recebe valor 4
    (*p)++;       //Vari�vel referenciado por p � incrementado em +1 (y -> 1)
    x--;          //Vari�vel x � decrementado em -1 (3)
    (*p) += x;    //Vari�vel referenciado por P(y) recebe o valor de y(1) + x(3)
    printf("y = %d\n", y); //Valor de Y � escrito na tela

    return 0;
}

int Exercise3()
{
    int x, * p, ** q;
    p = &x;
    q = &p;
    x = 10;
    printf("\n%d \n", **q); //! Corre��o: adicionar **(para que seja refenciado ao valor de x = 10)

    return 0;
}

int Exercise4()
{
    const int size_matrix = 10;
    int matrix[size_matrix][size_matrix];
    int i, j;
    int alocation = 0;

    for (int i = 0; i < size_matrix; i++)
    {
        for (int j = 0; j < size_matrix; j++)
        {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < size_matrix; i++)
    {
        for (int j = 0; j < size_matrix; j++)
        {
            matrix[i][j] = alocation;
            alocation++;
        }
    }

    return 0;
}

int Exercise6a()
{
    int x, * p{}; //! Corre��o: ponteiro p n�o estava inicializado -> Solu��o adicionar {};
    x = 10;
    p = &x;     //! Segunda poss�vel corre��o -> p receber o valor do endere�o de X.

    return 0;
}

int Exercise6b()
{
    int x, * p;
    x = 10;
    p = &x;         //! Corre��o p deve receber o endere�o de x (&x)
    printf("%d", *p);

    return 0;
}

int main()
{
    std::cout << "Everthing OK!" << std::endl;

    return 0;
}


