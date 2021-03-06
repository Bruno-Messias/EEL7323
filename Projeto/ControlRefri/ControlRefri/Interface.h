#ifndef INTERFACE_H
#define INTERFACE_H

#include "VendingMachine.cpp"

class interface_leon: public vending_machine 
{
public : 

	interface_leon();
	~interface_leon();
	
	void Inputs() override;
	void Display(void) override;
};

class interface_windowns: public vending_machine 
{
	char teclado; //entrada do usários na escolha das opções
public :
	interface_windowns();
	~interface_windowns();

	void Inputs() override;
	void Display(void) override;
};

#endif // !INTERFACE_H

