#ifndef BUTTON_H
#define BUTTON_H
class Button
{
    private:
        int pin;
        bool currentState;
        bool previousState;
    public:
        Button(int pinNumber);
        void observer(); 
        void begin();
        bool isPressed();
};

#endif