#ifndef VENDING_MACHINE_H
#define VENDING_MACHINE_H

class vending_machine
{
private:
    unsigned int money_stash, money_out; // entrada e saída de dinheiro 
    char soda; // Refrigerante escolhido

public:
    vending_machine();
    ~vending_machine();

    bool input_25, input_50, input_100, input_d, input_a, input_b; // entrada de usuário para dinheiro e seleção de refrigerantes ou devolução
    void Stash_add(); //Adiciona dinheiro na máquina de acordo com a entrada de usuário
    void FSM(); // estados da máquina de venda
    void Display(void);

};
#endif
