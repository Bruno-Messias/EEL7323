/*
 * LogTester.cpp
 *
 * Created: 05/04/2021 13:53:42
 * Author : Bruno Cayres Messias
 */ 

#include "USART.cpp"

int main(void)
{
    USART0_Init(MYUBBR);
	sei();
	
	char log[] = "1/2021:5:3:12:5:36/a\n";
	char log2[] = "1/2021:5:10:12:5:36/b\n";
	char log3[] = "1/2021:5:20:12:5:36/c\n";
	
    while (1) 
    {
		USART_putstring(log);
		_delay_ms(2000);
		USART_putstring(log2);
		_delay_ms(2000);
		USART_putstring(log3);
		_delay_ms(2000);
    }
	
	return 0;
}

