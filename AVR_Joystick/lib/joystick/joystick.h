/**
 *  @ Author: Rene Correa
 *  @ Create Time: 20-10-24 16:02:25
 *  @ Description:
 */

#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <stdio.h>
#include <avr/io.h>

class Joystick{
    private:
        volatile uint8_t* horizontalPort;
        uint8_t horizontalPin;

        volatile uint8_t* verticalPort;
        uint8_t verticalPin;

        volatile uint8_t* selectablePort;
        uint8_t selectablePin;


    public:
        Joystick(volatile uint8_t* verticalPort, uint8_t verticalPin,
                volatile uint8_t* horizontalPort, uint8_t horizontalPin,
                volatile uint8_t* selectablePort, uint8_t selectablePin);
        ~Joystick();
        uint16_t readHorizontal();
        uint16_t readVertical();
        uint16_t readSelectable();
};

#endif