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
    //TODO: Implementar Saidas da LEON
}

void interface_leon::Inputs()
{
    //TODO: Implementar Saida da Leon
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