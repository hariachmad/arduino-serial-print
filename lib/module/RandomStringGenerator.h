#ifndef RandomStringGenerator_h
#define RandomStringGenerator_h

#include <Arduino.h>

class RandomStringGenerator{
    public:
        static String execute(int length);
};

#endif