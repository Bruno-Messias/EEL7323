/*
 * PoolControler_AVR.cpp
 *
 * Created: 21/03/2021 16:20:44
 * Author : Bruno C. Messias 
 */ 

bool flag = false; //flag interrupt, global variable

//#include "pool_controler_windowns.cpp"
#include "pool_controler_atmega.cpp"


/*
TODO: -- Implementar logs --
	Sistema desligado por timeout
	Bot�o acionando, mas sem energia
	Bot�o acionado antes de timeout

FILA de dados
Deve conter ID do Controlador e Data/hora do log

Fun��es do LOG:
	Listar todos os eventos ocorridos
	Informar tempo total que o o aqucedor estve ligado em um intervalo de data
	Listar per�odo de maior utiliza��o do sistema
	
Objetivos:
Envio via UART
Mandar a Fila do Atmega e ser esvaziadaa -> estrutura no computador armazenar em lista esses dados(armazenar em .log no pc)
*/

	
int main(void)
{
	
	PoolControlerAtmega Controler;

	while (1)
	{
		Controler.inputSW();
		Controler.Inputs();
		Controler.Outputs();
		Controler.FSM();
		if (flag)
		{
			Controler.setEstate(1);  //If interrupt occur the next estate is INIT to reset the timer
			flag = false;
		}
	}
	return 0;
}
