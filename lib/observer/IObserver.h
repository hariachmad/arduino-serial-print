#ifndef I_OBSERVER_H
#define I_OBSERVER_H

#include <Arduino.h>

class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void update() = 0;
};

#endif