#ifndef VENDING_MACHINE_H
#define VENDING_MACHINE_H

class vending_machine //Classe abstrata para o controle de interface em tempo de compilação
{
public:
    int money_stash, money_out;
    bool input_25, input_50, input_100, input_d, input_a, input_b; // entrada de usuário para dinheiro e seleção de refrigerantes ou devolução
    std::string soda;

    void Stash_add(); //Adiciona dinheiro na máquina de acordo com a entrada de usuário
    void FSM(); // estados da máquina de venda

    virtual void Display(void) = 0; //Display do Menu para cada interface
    virtual void Inputs() = 0;
};

#endif //VENDING_MACHINE_H
