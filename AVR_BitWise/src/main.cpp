/**
 *  @ Author: Renê Corrêa
 *  @ Create Time: 30-08-24 16:27:47
 *  @ Description: BitWise operations example in AVR328P
 */
#ifdef F_CPU
#undef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

#define Led1 (1<<PORTD0)
#define Led2 (1<<PORTD1)
#define Led3 (1<<PORTD2)
#define Led4 (1<<PORTD3)

int main(){
  DDRD |= Led1 | Led2 | Led3 | Led4; //Define PortD 0 a 3 como saída
  PORTD &=~ Led1 &~ Led2 &~ Led3 &~ Led4;

  while(1){
    PORTD |= Led1;
    PORTD &=~ Led2 &~ Led3 &~ Led4;
    _delay_ms(500);
    PORTD |= Led2;
    PORTD &=~ Led1 &~ Led3 &~ Led4;
    _delay_ms(500);
    PORTD |= Led3;
    PORTD &=~ Led1 &~ Led2 &~ Led4;
    _delay_ms(500);
    PORTD |= Led4;
    PORTD &=~ Led1 &~ Led2 &~ Led3;
    _delay_ms(500);
  }
}
