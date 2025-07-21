#include "PackageSenderTask.h"
#include "../package/Package.h"
#include <Arduino.h>

void PackageSenderTask::sendPackage() {
    Serial.println("Sending Package");
    serializeJson(Package::package, Serial);
    Serial.println();
    Serial.println("Package Sent");
    delay(5000);
}