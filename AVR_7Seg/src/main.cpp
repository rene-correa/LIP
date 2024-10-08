/**
 *  @ Author: Renê Corrêa
 *  @ Create Time: 21-09-24 10:19:51
 *  @ Description: AVR 7 segment display example
 */

#ifdef F_CPU
#undef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

#define A (1<<PORTD0)
#define B (1<<PORTD1)
#define C (1<<PORTD2)
#define D (1<<PORTD3)
#define E (1<<PORTD4)
#define F (1<<PORTD5)
#define G (1<<PORTD6)

int num[10]{
    0b00111111, //0
    0b00000110, //1
    0b01011011, //2
    0b01001111, //3
    0b01100110, //4
    0b01101101, //5
    0b01111101, //6
    0b00000111, //7
    0b01111111, //8
    0b01101111  //9
};


void Seg7(uint8_t x);

int main(){
    DDRD |= A | B | C | D | E | F | G; //Define PortD 0 a 3 como saída
    PORTD &=~ A &~ B &~ C &~ D &~ E &~ F &~ G; //Desliga todos os pinos

    while(1){
        for(int i = 0; i < 10; i++){
            Seg7(i);
            _delay_ms(750);
        }
    }
}

void Seg7(uint8_t x){
    switch(x){
        case 0:
            PORTD |= A | B | C | D | E | F;
            PORTD &=~ G;
            break;
        case 1:
            PORTD |= B | C;
            PORTD &=~ A &~ D &~ E &~ F &~ G;
            break;
        case 2:
            PORTD |= A | B | D | E | G;
            PORTD &=~ C &~ F;
            break;
        case 3:
            PORTD |= A | B | C | D | G;
            PORTD &=~ E &~ F;
            break;
        case 4:
            PORTD |= B | C | F | G;
            PORTD &=~ A &~ D &~ E;
            break;
        case 5:
            PORTD |= A | C | D | F | G;
            PORTD &=~ B &~ E;
            break;
        case 6:
            PORTD |= A | C | D | E | F | G;
            PORTD &=~ B;
            break;
        case 7:
            PORTD |= A | B | C;
            PORTD &=~ D &~ E &~ F &~ G;
            break;
        case 8:
            PORTD |= A | B | C | D | E | F | G;
            break;
        case 9:
            PORTD |= A | B | C | D | F | G;
            PORTD &=~ E;
            break;
        default:
            PORTD &=~ A &~ B &~ C &~ D &~ E &~ F &~ G;
            break;
    }
}