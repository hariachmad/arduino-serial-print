#ifndef INTERVAL_BUTTON_MODULE_H
#define INTERVAL_BUTTON_MODULE_H
#include <Arduino.h>

class IntervalButtonModule
{
private:
    int sendMessageIntervalMode = false; 
    unsigned long lastDebounceTime = 0;
    bool lastConfirmedState = HIGH;
    unsigned long lowStartTime = 0;
    unsigned long debounceDelay = 50;
    bool waitingForConfirmation = false;
    int pin;

public:
    IntervalButtonModule(int pinNumber);
    void observer();
    void begin();
    void handleChangeState(int state);
};

#endif