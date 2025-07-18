#ifndef BUTTON_H
#define BUTTON_H
#include <SoftwareSerial.h>

// #define GPS_RX_PIN 3
// #define GPS_TX_PIN 4    

// extern SoftwareSerial gpsSerial;

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