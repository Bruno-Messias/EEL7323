#ifndef INTERFACE_H
#define INTERFACE_H

#include "VendingMachine.h"

class interface_leon: public vending_machine 
{
public : 
	bool input_25, input_50, input_100, input_d, input_a, input_b; // entrada de usuário para dinheiro e seleção de refrigerantes ou devolução

	interface_leon();
	~interface_leon();

	void Stash_add() override;
	void FSM() override;
	void Display(void) override;
};

class interface_windowns: public vending_machine 
{
	int input;
public :
	interface_windowns();
	~interface_windowns();

	void Stash_add() override;
	void FSM() override;
	void Display(void) override;
};

#endif // !INTERFACE_H

