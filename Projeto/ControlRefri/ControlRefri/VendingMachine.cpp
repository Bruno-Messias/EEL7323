
#include <string>
#include <iostream>
#include <iomanip>

#include "VendingMachine.h"

using namespace std;

vending_machine::vending_machine() // construtor: inicializa o objeto com as variáveis definidas abaixo
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

vending_machine::~vending_machine() {}

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

