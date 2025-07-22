#ifndef BUTTON_H
#define BUTTON_H

#include "../observer/Subject.h"
class Button : public Subject
{
    private:
        int pin;
        bool currentState;
        bool previousState;
    public:
        Button(int pinNumber);
        void observer(); 
        void begin();
        ~Button();      
};

#endif