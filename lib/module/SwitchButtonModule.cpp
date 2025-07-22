#include "SwitchButtonModule.h"
#include <Arduino.h>
#include "../observer/SwitchObserver.h"
#include "../context/StateContext.h"

SwitchButtonModule::SwitchButtonModule(int pinNumber)
{
    pin = pinNumber;    
    attach(new SwitchObserver("Button"));
    begin();
}

void SwitchButtonModule::begin()
{
    pinMode(pin, INPUT_PULLUP);
}

void SwitchButtonModule::observer()
{
    currentState = digitalRead(pin);
    if (currentState == LOW)
    {   
        this->notify();
    }else{
       state = HIGH; 
    }    
}

SwitchButtonModule::~SwitchButtonModule(){
    // 
}
