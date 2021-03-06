#ifndef INTERFACE_H
#define INTERFACE_H

#include "VendingMachine.cpp"

//--------------- Máscarasd para os LEDS de saida -----------
#define LD0_HIGH(output)*output || 0x00000001
#define LD0_LOW(output)	*output && 0xfffffffe
#define LD1_HIGH(output)*output || 0x00000002
#define LD1_LOW(output)	*output && 0xfffffffd
#define LD2_HIGH(output)*output || 0x00000003
#define LD2_LOW(output)	*output && 0xfffffffc
#define LD3_HIGH(output)*output || 0x00000004
#define LD3_LOW(output)	*output && 0xfffffffb
#define LD4_HIGH(output)*output || 0x00000005
#define LD4_LOW(output)	*output && 0xfffffffa
//------------------------------------------------------------

class interface_leon: public vending_machine 
{
	volatile unsigned int* data = (volatile unsigned int*)0x80000a00; //inicializando Pontereiros para GPIO LEON3
	volatile unsigned int* output = (volatile unsigned int*)0x80000a04;
	volatile unsigned int* direction = (volatile unsigned int*)0x80000a08;
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

