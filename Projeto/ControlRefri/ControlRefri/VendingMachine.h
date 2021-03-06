#ifndef VENDING_MACHINE_H
#define VENDING_MACHINE_H

class vending_machine 
{
public:
    int money_stash, money_out;
    std::string soda;

    virtual void Stash_add() = 0; //Adiciona dinheiro na m�quina de acordo com a entrada de usu�rio
    virtual void FSM() = 0; // estados da m�quina de venda
    virtual void Display(void) = 0; //Display do Menu para cada nterface
};

#endif //VENDING_MACHINE_H
