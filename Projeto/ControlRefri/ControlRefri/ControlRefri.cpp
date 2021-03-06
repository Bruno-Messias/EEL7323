#include "ControlRefri.h"

using namespace std;

int main() {

    interface_leon Maquina; // Cria objeto da máquina de vendas
    char teclado = '0'; // inicializa variável de entrada de usuário

    while (true)
    {

        Maquina.Display(); //Mostra as informações de entrada e saída da máquina de vendas

        cin >> teclado; //recebe a entrada de teclado do terminal do usuário e armazena em 'teclado'

        //seta as variáveis dependendo da entrada em 'teclado'
        if (teclado == '1') {
            Maquina.input_25 = true;
        }
        if (teclado == '2') {
            Maquina.input_50 = true;
        }
        if (teclado == '3') {
            Maquina.input_100 = true;
        }
        if (teclado == 'a') {
            Maquina.input_a = true;
        }
        if (teclado == 'b') {
            Maquina.input_b = true;
        }
        if (teclado == 'd') {
            Maquina.input_d = true;
        }

        Maquina.Stash_add(); // caso a entrada seja 1, 2 ou 4 é adicionado à maquina os valores de 25, 50 e 100  respectivamente 
        Maquina.FSM(); // FSM da maquina de vendas
    }


}