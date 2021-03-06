
#include <string>
#include <iostream>
#include <iomanip>
#include "vending_machine.h"

using namespace std;

vending_machine::vending_machine() // construtor: inicializa o objeto com as variáveis definidas abaixo
{
    money_stash = 0;
    money_out = 0;
    soda = 'N';
    input_a = false;
    input_b = false;
    input_d = false;
    input_25 = false;
    input_50 = false;
    input_100 = false;
}

vending_machine::~vending_machine()
{
}

void vending_machine::Stash_add() // adiciona dinheiro à maquina conforme entrada de usuário
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

void vending_machine::Display(void) // imprime no console as informações do estado da máquina
{
    cout << "Maquina de vendas" << endl;
    cout << "tecla 1 -> 25 cents    tecla 2-> 50 cents    tecla 4 -> 100 cents" << endl;
    cout << "tecla a -> Refrig. A    tecla b-> Refrig. B   tecla d -> Devolução" << endl;
    cout << " " << endl;
    cout << "Bt: 25=" << input_25 << "  50=" << input_50 << "  100=" << input_100 << "  A=" << input_a << "  B=" << input_b << "  D=" << input_d << endl;
    cout << "Dinheiro inserido: " << money_stash << endl;
    cout << "Dinheiro devolvido: " << money_out << endl;
    cout << "Refigerante escolhido: " << soda << endl;
    cout << " " << endl;
}

void vending_machine::FSM()
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
        soda = 'N';
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
        soda = 'N';
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
        soda = 'N';
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
        soda = 'N';
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
        soda = 'N';
        break;

    case 150:
        money_out = 0;

        soda = 'N';
        if (input_d == true) {
            money_out = money_stash;
            money_stash = 0;
            input_d = false;

        }
        if (input_a == true) {
            money_stash = 0;
            soda = 'A';
            input_a = false;

        }
        if (input_b == true) {
            money_stash = 0;
            soda = 'B';
            input_b = false;

        }
        break;

    default: // redundância criada para englobar possíveis casos quenao se encaixam na tabela de estados da FSM
        soda = 'N';
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
            soda = 'A';
            input_a = false;

        }
        if (money_stash == 150 && input_b == true) {
            money_stash = 0;
            soda = 'B';
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

        soda = 'N';
        money_out = 0;

        break;
    }
}

