/**
 *  @ Author: Rene Correa
 *  @ Create Time: 20-10-24 16:02:20
 *  @ Description:
 */

#include "joystick.h"

Joystick::Joystick(volatile uint8_t* verticalPort, uint8_t verticalPin,
                volatile uint8_t* horizontalPort, uint8_t horizontalPin,
                volatile uint8_t* selectablePort, uint8_t selectablePin){
    this->horizontalPort = horizontalPort;
    this->horizontalPin = horizontalPin;
    this->verticalPort = verticalPort;
    this->verticalPin = verticalPin;
    this->selectablePort = selectablePort;
    this->selectablePin = selectablePin;

    ADMUX |=  (1<<REFS0);		// Tensao de referencia
	ADMUX &=~ (1<<REFS1);		// Tensao de referência
    //AVcc with etxernal capacitor at AREF pin   
	ADMUX &=~ (1<<ADLAR);		// Ajuste de organizaçao do resultado

	ADCSRA |= (1<<ADPS0);		// Divisor fator = 128
	ADCSRA |= (1<<ADPS1);		// Divisor fator = 128
	ADCSRA |= (1<<ADPS2);		// Divisor fator = 128
    //Leitura a cada 16MHZ / 128 = 126Khz → 8us
    //Leitura a cada 16MHZ / 2 = 8Mhz → 125ns
	ADCSRA |= (1<<ADEN);

    *(selectablePort-1) &=~ (1<<selectablePin); //Define o pino selectable da porta selectable como INPUT
}

Joystick::~Joystick(){

}

uint16_t Joystick::readHorizontal(){
    uint8_t canal = horizontalPin;
    canal &= 0b00001111;				// Limite de canal em 15
	ADMUX = (ADMUX & 0xF0)|canal;   // Limpa os últimos 4 bits de ADMUX 0xF0 → 0b11110000
	ADCSRA |= (1<<ADSC);				// Inicia a conversao
	while((ADCSRA)&(1<<ADSC));		// Enquanto se complete a coversao
	return(ADC);					// Devolve o valor de ADC
}

uint16_t Joystick::readVertical(){
    uint8_t canal = verticalPin;
    canal &= 0b00001111;				// Limite de canal em 15
	ADMUX = (ADMUX & 0xF0)|canal;   // Limpa os últimos 4 bits de ADMUX 0xF0 → 0b11110000
	ADCSRA |= (1<<ADSC);				// Inicia a conversao
	while((ADCSRA)&(1<<ADSC));		// Enquanto se complete a coversao
	return(ADC);
}

uint16_t Joystick::readSelectable(){
  return *(selectablePort-2) & (1<<selectablePin); //retorna valor lido no selectablePin
}