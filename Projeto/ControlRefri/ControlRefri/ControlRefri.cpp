#include "ControlRefri.h"

using namespace std;

#define leon_mode false

int main() {

    interface_windowns Maquina;
    //interface_leon Maquina; //Interface da Leon

    while (true)
    {
        Maquina.Display(); //Mostra as informa��es de entrada e sa�da da m�quina de vendas
        Maquina.Inputs(); //Recebe os valores dados pelo usu�rio
        Maquina.Stash_add(); // caso a entrada seja 1, 2 ou 4 � adicionado � maquina os valores de 25, 50 e 100  respectivamente 
        Maquina.FSM(); // FSM da maquina de vendas
    }
}