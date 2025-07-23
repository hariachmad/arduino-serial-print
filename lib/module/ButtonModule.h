#ifndef BUTTON_H
#define BUTTON_H

#include "../observer/Subject.h"
#include "../module/MqttModule.h"

class Button : public Subject
{
    private:
        int pin;
        bool currentState;
        bool previousState;
        MqttModule* mqttModule;
    public:
        Button(int pinNumber,MqttModule* _mqttModule);
        void observer(); 
        void begin();
        ~Button();      
};

#endif