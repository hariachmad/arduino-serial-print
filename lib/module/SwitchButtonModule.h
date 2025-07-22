#ifndef SWITCH_BUTTON_H
#define SWITCH_BUTTON_H

#include "../observer/Subject.h"
class SwitchButtonModule : public Subject
{
    private:
        int pin;
        bool currentState;
    public:
        SwitchButtonModule(int pinNumber);
        void observer(); 
        void begin();
        ~SwitchButtonModule();        
};

#endif