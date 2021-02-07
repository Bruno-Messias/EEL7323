/* Exercícios.cpp : resolução de alguns exercícios sobre ponteiros
    Author: Bruno C. Messias
    Date: 07/02/2021
*/

#include <iostream>

/*
    Exercício 1:
    p++: Variável incrementada em +1
    (*p)++: O valor referenciado pelo ponteiro é incrementado em +1
    *(p++): A variável P é incrementada e após isso é referenciada

*/

int Exercise2()
{
    int y, * p, x; //Declara variáveis y e x e o ponteiro p
    y = 0;        //Variável y recebe valor 0
    p = &y;       //O ponteiro p recebe o endederço de y
    x = *p;       //Variável x recebe o valor apontado por p
    x = 4;        //Variável x recebe valor 4
    (*p)++;       //Variável referenciado por p é incrementado em +1 (y -> 1)
    x--;          //Variável x é decrementado em -1 (3)
    (*p) += x;    //Variável referenciado por P(y) recebe o valor de y(1) + x(3)
    printf("y = %d\n", y); //Valor de Y é escrito na tela

    return 0;
}

int Exercise3()
{
    int x, * p, ** q;
    p = &x;
    q = &p;
    x = 10;
    printf("\n%d \n", **q); //! Correção: adicionar **(para que seja refenciado ao valor de x = 10)

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
    int x, * p{}; //! Correção: ponteiro p não estava inicializado -> Solução adicionar {};
    x = 10;
    p = &x;     //! Segunda possível correção -> p receber o valor do endereço de X.

    return 0;
}

int Exercise6b()
{
    int x, * p;
    x = 10;
    p = &x;         //! Correção p deve receber o endereço de x (&x)
    printf("%d", *p);

    return 0;
}

int main()
{
    std::cout << "Everthing OK!" << std::endl;

    return 0;
}


