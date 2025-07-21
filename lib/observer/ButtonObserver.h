#ifndef BUTTON_OBSERVER_H
#define BUTTON_OBSERVER_H

#include "IObserver.h"
#include <Arduino.h>
#include "../task/PackageSenderTask.h"
#include "../task/PackageAllocTask.h"
#include "../package/Package.h"


class ButtonObserver : public IObserver
{
private:
    const String name;

public:
    ButtonObserver(String name) : name(name) {}

    void update() override;
};

#endif