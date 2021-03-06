#include "ControlRefri.h"

using namespace std;

#define leon_mode false

int main() {

    interface_windowns Maquina;
    //interface_leon Maquina; //Interface da Leon

    while (true)
    {
        Maquina.Display(); //Mostra as informações de entrada e saída da máquina de vendas
        Maquina.Inputs(); //Recebe os valores dados pelo usuário
        Maquina.Stash_add(); // caso a entrada seja 1, 2 ou 4 é adicionado à maquina os valores de 25, 50 e 100  respectivamente 
        Maquina.FSM(); // FSM da maquina de vendas
    }
}