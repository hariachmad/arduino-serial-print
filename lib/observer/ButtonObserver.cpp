#include "ButtonObserver.h"

void ButtonObserver::update()
{
    Serial.print(name);
    Serial.print(" - ");
    serializeJson(Package::package, Serial);
    PackageSenderTask::sendPackage(mqttModule);
    delay(2000);
}

ButtonObserver::ButtonObserver(String _name,MqttModule*mqttModule){
    this->name = _name;
    this->mqttModule = mqttModule;
}