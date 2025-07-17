#ifndef BUTTON_H
#define BUTTOH_H

class Button
{
    private:
        int pin;
        bool previousState;
    
    public:
        Button(int pinNumber); 
        void begin();
        bool isPressed();
};

#endif