#include "ButtonObserver.h"

void ButtonObserver::update()
{
    Serial.print(name);
    Serial.print(" - ");
    serializeJson(Package::package, Serial);
    PackageSenderTask::sendPackage();
    delay(2000);
}