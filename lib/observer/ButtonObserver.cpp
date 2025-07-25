#include "ButtonObserver.h"

void ButtonObserver::update()
{
    Serial.print(name);
    Serial.print(" - ");
    serializeJson(Package::package, Serial);
    PackageSenderTask::sendPackage(client);
    delay(2000);
}