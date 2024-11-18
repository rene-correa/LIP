#define F_CPU 16000000UL
 
#include <avr/io.h>
#include <util/delay.h>
#include "led.h"  // Incluímos o arquivo de cabeçalho da biblioteca
 
int main(void) {
    uint8_t ledPin = PB5;  // Definimos que o LED está conectado ao pino PB0
 
    // Inicializa o LED no pino definido
    led_init(ledPin);
 
    while (1) {
        // Liga o LED
        led_on(ledPin);
        _delay_ms(1000);  // Atraso de 1 segundo
 
        // Desliga o LED
        led_off(ledPin);
        _delay_ms(1000);  // Atraso de 1 segundo
    }
 
    return 0;  
}