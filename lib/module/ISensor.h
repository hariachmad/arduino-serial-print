#ifndef ISENSOR_H
#define ISENSOR_H
#include <Arduino.h>

class ISensor
{
public:
    virtual void setup()=0;
    virtual void inject()=0;
    virtual void invoke(const void* param)=0;
};
#endif