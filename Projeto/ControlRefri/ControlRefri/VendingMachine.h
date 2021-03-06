#ifndef VENDING_MACHINE_H
#define VENDING_MACHINE_H

class vending_machine //Classe abstrata para o controle de interface em tempo de compila��o
{
public:
    int money_stash, money_out;
    bool input_25, input_50, input_100, input_d, input_a, input_b; // entrada de usu�rio para dinheiro e sele��o de refrigerantes ou devolu��o
    std::string soda;

    void Stash_add(); //Adiciona dinheiro na m�quina de acordo com a entrada de usu�rio
    void FSM(); // estados da m�quina de venda

    virtual void Display(void) = 0; //Display do Menu para cada interface
    virtual void Inputs() = 0;
};

#endif //VENDING_MACHINE_H
