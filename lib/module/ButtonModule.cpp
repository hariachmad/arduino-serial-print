#include "buttonmodule.h"
#include <Arduino.h>

Button::Button(int pinNumber)
{
    pin = pinNumber;
    previousState = HIGH;
}

void Button::begin()
{
    pinMode(pin, INPUT);
}

bool Button::isPressed()
{
    bool curentState = digitalRead(pin);
    if (previousState == HIGH && curentState == LOW)
    {
        delay(50); //Deboumce
        previousState = curentState;
        return true;
    }
    previousState = curentState;
    return false;
}
