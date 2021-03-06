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
    cout << "------------------------- Maquina de vendas (Interface - Leon) --------------------------" << endl;
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
void interface_leon::Stash_add() 
{
    if (input_25) {
        money_stash += 25;
        input_25 = false;
    }
    if (input_50) {
        money_stash += 50;
        input_50 = false;
    }
    if (input_100) {
        money_stash += 100;
        input_100 = false;
    }
}
void interface_leon::FSM()
{
    switch (money_stash) {
    case 25:
        money_out = 0;

        if (input_d == true) {
            money_out = money_stash;
            money_stash = 0;
            input_d = false;
        }
        if (input_a == true)
        {
            input_a = false; //"destrava" a entrada do usuário
        }
        if (input_b == true)
        {
            input_b = false;
        }
        soda = "N";
        break;

    case 50:
        money_out = 0;

        if (input_d == true) {
            money_out = money_stash;
            money_stash = 0;
            input_d = false;
        }
        if (input_a == true)
        {
            input_a = false;
        }
        if (input_b == true)
        {
            input_b = false;
        }
        soda = "N";
        break;

    case 75:
        money_out = 0;

        if (input_d == true) {
            money_out = money_stash;
            money_stash = 0;
            input_d = false;
        }
        if (input_a == true)
        {
            input_a = false;
        }
        if (input_b == true)
        {
            input_b = false;
        }
        soda = "N";
        break;

    case 100:
        money_out = 0;

        if (input_d == true) {
            money_out = money_stash;
            money_stash = 0;
            input_d = false;
        }
        if (input_a == true)
        {
            input_a = false;
        }
        if (input_b == true)
        {
            input_b = false;
        }
        soda = "N";
        break;

    case 125:
        money_out = 0;

        if (input_d == true) {
            money_out = money_stash;
            money_stash = 0;
            input_d = false;

        }
        if (input_a == true)
        {
            input_a = false;
        }
        if (input_b == true)
        {
            input_b = false;
        }
        soda = "N";
        break;

    case 150:
        money_out = 0;

        soda = "N";
        if (input_d == true) {
            money_out = money_stash;
            money_stash = 0;
            input_d = false;

        }
        if (input_a == true) {
            money_stash = 0;
            soda = "MEET";
            input_a = false;

        }
        if (input_b == true) {
            money_stash = 0;
            soda = "ETIRPS";
            input_b = false;

        }
        break;

    default:
        soda = "N";
        money_out = 0;

        if (money_stash >= 151)
        {
            money_out = money_stash - 150;
            money_stash -= money_out;
        }

        if (money_stash >= 1 && input_d == true) {
            money_out = money_stash;
            money_stash = 0;
            input_d = false;

        }
        if (money_stash == 150 && input_a == true) {
            money_stash = 0;
            soda = "MEET";
            input_a = false;

        }
        if (money_stash == 150 && input_b == true) {
            money_stash = 0;
            soda = "ETIRPS";
            input_b = false;
        }
        if (input_a == true)
        {
            input_a = false;
        }
        if (input_b == true)
        {
            input_b = false;
        }
        if (input_d == true)
        {
            input_d = false;
        }
        break;

    case 0:
        if (input_a == true)
        {
            input_a = false;
        }
        if (input_b == true)
        {
            input_b = false;
        }
        if (input_d == true)
        {
            input_d = false;
        }

        soda = "N";
        money_out = 0;

        break;
    }
}

//! Windowns Interface
interface_windowns::interface_windowns()
{

}
interface_windowns::~interface_windowns()
{

}
void interface_windowns::Stash_add()
{

}
void interface_windowns::Display(void)
{

}
void interface_windowns::FSM()
{

}