#include "ButtonModule.h"
#include <Arduino.h>
#include "../observer/ButtonObserver.h"

// SoftwareSerial gpsSerial(GPS_RX_PIN, GPS_TX_PIN);
Button::Button(int pinNumber, MqttModule* _mqttModule)
{
    pin = pinNumber;    
    attach(new ButtonObserver("Button",_mqttModule));
    begin();
}

void Button::begin()
{
    pinMode(pin, INPUT_PULLUP);
}

void Button::observer()
{
    currentState = digitalRead(pin);
    if (currentState == LOW)
    {   
        delay(200);
        this->notify();
    } 
}

Button::~Button() {
    // 
}