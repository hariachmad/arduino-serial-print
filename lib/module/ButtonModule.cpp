#include "ButtonModule.h"
#include <Arduino.h>
#include "../observer/ButtonObserver.h"

// SoftwareSerial gpsSerial(GPS_RX_PIN, GPS_TX_PIN);
Button::Button(int pinNumber)
{
    pin = pinNumber;
    currentState= HIGH;
    previousState= LOW;

    attach(new ButtonObserver("Button"));
}

void Button::begin()
{
    pinMode(pin, INPUT_PULLUP);
}

void Button::observer()
{
    previousState = currentState;
    currentState= digitalRead(pin);
    delay(50);
    if(isPressed){
        for(IObserver* observer : observers){
            observer->update();
        }
    }
}

bool Button::isPressed()
{
    if (previousState == HIGH && currentState == LOW)
    {
        Serial.println("Button Pressed");
        return true;
    }
    return false;
}
