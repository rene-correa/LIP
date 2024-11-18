/**
 *  @ Author: Rene Correa
 *  @ Create Time: 20-10-24 15:53:33
 *  @ Description:
 */

#ifdef F_CPU
#undef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include "joystick.h"

#define Led1 (1<<PORTB1)
#define Led2 (1<<PORTB2)
#define Led3 (1<<PORTB3)

Joystick joy1 = Joystick(&PORTC, PORTC0, &PORTC, PORTC1, &PORTC, PORTC2);

int main(){
    DDRB |= Led1 | Led2 | Led3;
    PORTB &=~ Led1 &~ Led2 &~ Led3;

    while(1){
        if(joy1.readHorizontal() >512) PORTB |= Led1;
        else PORTB &=~ Led1;

        if(joy1.readVertical() >512) PORTB |= Led2;
        else PORTB &=~ Led2;

        if(joy1.readSelectable()) PORTB |= Led3;
        else PORTB &=~ Led3;
    }
    return 0;
}
