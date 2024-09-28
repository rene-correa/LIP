/**
 *  @ Author: Renê Corrêa
 *  @ Create Time: 28-09-24 10:16:26
 *  @ Description:
 */

#ifdef F_CPU
#undef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{ 
	uint16_t desloca = 1;
	
	DDRD = 0XFF; // Define todo o PORT D como saída
	DDRB &=~ (1<<PORTB0) | (1<<PORTB1); // Define os bits 0 e 1 do PORT B como entrada
	PORTB |= (1<<PORTB0) | (1<<PORTB1); // Habilita PULL-UP para os bits 0 e 1 do PORT B 
	
    while (1) 
    {
		
		if((PINB & (1 << PINB0)) == 0){ // Verifica o etado lógico do bit 0 no PORT B (se 0)
			_delay_ms(250); // Tempo para debounce (atraso de execução)
			if(desloca >= 0x80){ // Verifica se a variável >= B10000000
				desloca = 1; // Define a retomada
			}
			else{
				desloca *= 2; // Define o delocamento de 1 lógico no BYTE
			}
		}
		
		if((PINB & (1 << PINB1)) == 0){ // Verifica o etado lógico do bit 1 no PORT B (se 0)
			_delay_ms(250); // Tempo para debounce (atraso de execução)
			if(desloca <= 1){ // Verifica se a variável >= B00000001
				desloca = 0x80; // Define a retomada
			}
			else{
				desloca /= 2; // Define o delocamento de 1 lógico no BYTE
			}
		}

		PORTD = desloca; // Estado lógico do BYTE no PORT B 
	}
}