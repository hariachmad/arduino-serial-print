#include "IntervalButtonModule.h"
#include <Arduino.h>

IntervalButtonModule::IntervalButtonModule(int pinNumber)
{
    pin = pinNumber;
}

void IntervalButtonModule::begin()
{
    pinMode(pin, INPUT);
}

void IntervalButtonModule::observer()
{
    int currentState = digitalRead(pin);
    unsigned long now = millis();
    if (lastConfirmedState == HIGH && currentState == LOW)
    {
        if (!waitingForConfirmation)
        {
            lowStartTime = now;
            waitingForConfirmation = true;
        }
        else if (now - lowStartTime >= 1000)
        {
            lastConfirmedState = LOW;
            waitingForConfirmation = false;
            Serial.println("State changed: HIGH -> LOW (after 1s delay)");
            handleChangeState(LOW);
        }
    }
    if (currentState == HIGH)
    {
        if (waitingForConfirmation)
        {
            waitingForConfirmation = false;
            Serial.println("LOW canceled, bounced back to HIGH");
        }
        lastConfirmedState = HIGH;
    }
    if (lastConfirmedState == LOW && currentState == HIGH){
        handleChangeState(LOW);
    }
}