#include "LedModule.h"
#include <Arduino.h>

LedModule::LedModule(int pin) {
    this->pin = pin;
    pinMode(pin, OUTPUT);
    off();
}

void LedModule::on() {
    digitalWrite(pin, HIGH);
}

void LedModule::off() {
    digitalWrite(pin, LOW);
}