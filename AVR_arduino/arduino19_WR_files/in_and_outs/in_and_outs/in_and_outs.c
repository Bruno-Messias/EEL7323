/*
 * in_and_outs.c
 *
 * Created: 17/06/2015 18:15:46
 *  Author: Wagner Rambo
 */ 


// -- Frequência --
#define F_CPU 16000000				//Frequência do cristal oscilador externo


// -- Bibliotecas Auxiliares --
#include <avr/io.h>
#include <util/delay.h>

// registrador = registrador OR flag(1) [ligando um determinado bit]
// registrador = registrador AND (not flag(1)) [desligando um determinado bit]

// reg |= (1<<bit)


#define set_bit(reg,bit)   (reg |= (1<<bit))
#define reset_bit(reg,bit) (reg &= ~(1<<bit))


int main(void)
{
	set_bit(DDRB, PORTB5);						//Defino o PB5 como saída
	
	
    while(1)
    {
       set_bit(PORTB, PORTB5);
	   _delay_ms(500);
	   reset_bit(PORTB,PORTB5);
	   _delay_ms(500);
	   
    }
}