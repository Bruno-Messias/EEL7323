#ifndef VENDING_MACHINE_H
#define VENDING_MACHINE_H

class vending_machine
{
private:
    unsigned int money_stash, money_out; // entrada e sa�da de dinheiro 
    char soda; // Refrigerante escolhido

public:
    vending_machine();
    ~vending_machine();

    bool input_25, input_50, input_100, input_d, input_a, input_b; // entrada de usu�rio para dinheiro e sele��o de refrigerantes ou devolu��o
    void Stash_add(); //Adiciona dinheiro na m�quina de acordo com a entrada de usu�rio
    void FSM(); // estados da m�quina de venda
    void Display(void);

};
#endif
