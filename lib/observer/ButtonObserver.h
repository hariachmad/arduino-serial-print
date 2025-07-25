#ifndef BUTTON_OBSERVER_H
#define BUTTON_OBSERVER_H

#include "IObserver.h"
#include <Arduino.h>
#include "../task/PackageSenderTask.h"
#include "../task/PackageAllocTask.h"
#include "../package/Package.h"
#include "../module/MqttModule.h"


class ButtonObserver : public IObserver
{
private:
    String name;
    PubSubClient* client;
public:
    ButtonObserver(String _name, PubSubClient* _client) : name(_name), client(_client) {};   
    void update() override;
};

#endif