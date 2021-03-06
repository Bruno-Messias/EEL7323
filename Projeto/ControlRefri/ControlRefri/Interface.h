#ifndef INTERFACE_H
#define INTERFACE_H

#include "VendingMachine.cpp"

//--------------- Máscaras para os LEDS de saida -----------
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

//-------------- Máscaras para Inputs -----------------------
#define BTNU 0x00000010
#define is_BTNU(data) BTNU && *data
#define BTNL 0X00000011
#define is_BTNL(data) BTNL && *data
#define BTND 0x00000012
#define is_BTND(data) BTND && *data
#define BTNR 0X00000013
#define is_BTNR(data) BTNR && *data
#define BTNC 0x00000014
#define is_BTNC(data) BTNC && *data
#define SW0 0X00000008
#define is_SW0(data) SW0 && *data

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

