#include "led.h"
 
void led_init(uint8_t pin) {
    DDRB |= (1 << pin);  // Configura o pino como saída
}
 
void led_on(uint8_t pin) {
    PORTB |= (1 << pin);  // Liga o LED
}
 
void led_off(uint8_t pin) {
    PORTB &= ~(1 << pin);  // Desliga o LED
}
 