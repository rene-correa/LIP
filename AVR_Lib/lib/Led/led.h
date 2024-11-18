#ifndef LED_H
#define LED_H
 
#include <avr/io.h>
 
// Função para inicializar o LED
void led_init(uint8_t pin);
 
// Função para ligar o LED
void led_on(uint8_t pin);
 
// Função para desligar o LED
void led_off(uint8_t pin);
 
#endif