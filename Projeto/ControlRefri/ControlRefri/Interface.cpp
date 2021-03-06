#include "Interface.h"

using namespace std;

//! Leon Interface
interface_leon::interface_leon() // construtor: inicializa o objeto com as variáveis definidas abaixo
{
    money_stash = 0;
    money_out = 0;
    soda = "N";
    input_a = false;
    input_b = false;
    input_d = false;
    input_25 = false;
    input_50 = false;
    input_100 = false;
}
interface_leon::~interface_leon() { }
void interface_leon::Display(void)
{
    *direction = 0xffffffff; //Liberando todas as saidas;
    switch (vending_machine::money_out)
    {
    case 25:
        *output = LD0_HIGH(output); //Indica que deve devolver 25 centavos
        break;
    case 50:
        *output = LD1_HIGH(output); //Indica que deve devolver 50 centavos
        break;
    case 100:
        *output = LD2_HIGH(output); //Indica que deve devolver 1 real
        break;
    default:
        *output = LD0_LOW(output);
        *output = LD1_LOW(output);
        *output = LD2_LOW(output);
        break;
    }

    if (vending_machine::soda == "MEET")
        *output = LD3_HIGH(output); //Indica que foi liberado MEET
    else 
        *output = LD3_LOW(output);

    if (vending_machine::soda == "ETIRPS")
        *output = LD4_HIGH(output); //India que foi liberado ETIRPS
    else
        *output = LD4_LOW(output);
}
void interface_leon::Inputs()
{
    //vending_machine::input_a = //button(a);
    //vending_machine::input_b = //button;
    //vending_machine::input_d = //button;
    //vending_machine::input_25 = //button;
    //vending_machine::input_50 = //button;
    //vending_machine::input_100 = //button;
}

//! Windowns Interface
interface_windowns::interface_windowns()
{
    money_stash = 0;
    money_out = 0;
    soda = "N";
    input_a = false;
    input_b = false;
    input_d = false;
    input_25 = false;
    input_50 = false;
    input_100 = false;
}
interface_windowns::~interface_windowns() { }
void interface_windowns::Display(void)
{
    cout << "------------------------- Maquina de vendas (Interface - Windowns) --------------------------" << endl;
    cout << "Comandos Plataforma: " << endl;
    cout << "Tecla 1 -> 25 centavos    Tecla 2-> 50 centavos    Tecla 3 -> 1 real" << endl;
    cout << "Tecla a -> MEET    Tecla b-> ETIRPS   Tecla d -> DEV" << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Bt: 25=" << input_25 << "  50=" << input_50 << "  100=" << input_100 << "  A=" << input_a << "  B=" << input_b << "  D=" << input_d << endl;
    cout << "Dinheiro Acumulado: " << money_stash << endl;
    cout << "Dinheiro Devolvido: " << money_out << endl;
    cout << "Refigerante Escolhido: " << soda << endl;
    cout << endl;
}
void interface_windowns::Inputs()
{
    teclado = '0';
    cin >> teclado; //recebe a entrada de teclado do terminal do usuário e armazena em 'teclado'

    //seta as variáveis dependendo da entrada em 'teclado'
    if (teclado == '1') {
        vending_machine::input_25 = true;
    }
    if (teclado == '2') {
        vending_machine::input_50 = true;
    }
    if (teclado == '3') {
        vending_machine::input_100 = true;
    }
    if (teclado == 'a') {
        vending_machine::input_a = true;
    }
    if (teclado == 'b') {
        vending_machine::input_b = true;
    }
    if (teclado == 'd') {
        vending_machine::input_d = true;
    }
}