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
	Botão acionando, mas sem energia
	Botão acionado antes de timeout

FILA de dados
Deve conter ID do Controlador e Data/hora do log

Funções do LOG:
	Listar todos os eventos ocorridos
	Informar tempo total que o o aqucedor estve ligado em um intervalo de data
	Listar período de maior utilização do sistema
	
Objetivos:
Envio via UART
Mandar a Fila do Atmega e ser esvaziadaa -> estrutura no computador armazenar em lista esses dados(armazenar em .log no pc)
*/

////-- For using USART
//#define FOSC 16000000
//#define BAUD 9600
//#define MYUBBR FOSC/16/BAUD-1
//
//void USART_Init(unsigned int ubrr)
//{
	///*Set Baud Rate*/
	//UBRR0H = (unsigned char)(ubrr>>8);
	//UBRR0L = (unsigned char)ubrr;
	///*Enable receiver and transmitter*/	
	//UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	///*Set Frame format: 8data, 1stop bit*/
	//UCSR0C = (3<<UCSZ00);
//}
//
//unsigned char USART_Recive( void) {
	///*Wait for data to be receiver*/
	//while(!(UCSR0A & (1<<RXC0)));
	//
	///*Get and return received data from buffer*/
	//return UDR0;
//} 
//
//void USART_Transmit(unsigned char data)
//{
	///*Wait for empty transmit buffer*/
	//while(!(UCSR0A & (1<<UDRE0)));
	//
	///*Put data into buffer, sends the data*/
	//UDR0 = data;
//}


int main(void)
{
	//PoolControlerWindowns Controler;
	PoolControlerAtmega Controler;

	while(1)
	{
		Controler.inputSW();
		Controler.FSM();
		Controler.checkLog();
		if(flag)
		{
			Controler.setEstate(1);  //If interrupt occur the next estate is INIT to reset the timer and initiate system
			flag = false;
		}	
	}
	
	return 0;
}

