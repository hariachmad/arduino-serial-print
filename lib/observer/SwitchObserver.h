#ifndef SWITCH_OBSERVER_H
#define SWITCH_OBSERVER_H

#include "IObserver.h"

class SwitchObserver : public IObserver{
    private:
    const String name;

public:
    SwitchObserver(String name) : name(name) {}

    void update() override;
};


#endif
