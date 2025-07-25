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
    public:
        Button(int pinNumber, PubSubClient* _client);
        void observer(); 
        void begin();
        ~Button();      
};

#endif