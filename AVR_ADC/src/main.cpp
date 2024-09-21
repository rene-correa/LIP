/**
 *  @ Author: Renê Corrêa
 *  @ Create Time: 31-08-24 09:43:52
 *  @ Description:
 */

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "DEF_ATMEGA328P.h"
#include "LCD.h"

void ADC_init(void);
uint16_t ADC_read(uint8_t canal);

char str[10];
uint16_t dado_adc;
float valor_tensao;

int main(void)
{
  char str[10];
  uint16_t dado_adc;
  float valor_tensao;
  
	LCD_init();
	ADC_init();
	
    while (1) 
    {
		LCD_clear();
		dado_adc = ADC_read(0);
		valor_tensao = (float)(5.0/1023) * dado_adc;
		dtostrf(valor_tensao, 5, 2, str);
		LCD_printf(str);
		_delay_ms(100);
    }
}

void ADC_init(void)
{
	ADMUX |=  (1<<REFS0);		// Tensão de referência
	ADMUX &=~ (1<<REFS1);		// Tensão de referência
  //AVcc with etxernal capacitor at AREF pin
	ADMUX &=~ (1<<ADLAR);		// Ajuste de organização do resultado

	ADCSRA |= (1<<ADPS0);		// Divisor fator = 128
	ADCSRA |= (1<<ADPS1);		// Divisor fator = 128
	ADCSRA |= (1<<ADPS2);		// Divisor fator = 128
  //Leitura a cada 16MHZ / 128 = 126Khz → 8us
  //Leitura a cada 16MHZ / 2 = 8Mhz → 125ns
	ADCSRA |= (1<<ADEN);		// Ativação do ADC
  //Writing this bit to 1 enables the ADC
}


uint16_t ADC_read(uint8_t canal)
{
	canal &= 0b00001111;				// Limite de canal em 15
	ADMUX = (ADMUX & 0xF0)|canal;   // Limpa os últimos 4 bits de ADMUX 0xF0 → 0b11110000
	ADCSRA |= (1<<ADSC);				// Inicia a conversão
	while((ADCSRA)&(1<<ADSC));		// Enquanto se complete a coversão
	return(ADC);					// Devolve o valor de ADC
}
