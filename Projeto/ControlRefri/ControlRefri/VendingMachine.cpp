
#include <string>
#include <iostream>
#include <iomanip>

#include "VendingMachine.h"

using namespace std;

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

