#include "PackageSenderTask.h"
#include "../lib/package/Package.h"
#include <Arduino.h>

void PackageSenderTask::sendPackage(StaticJsonDocument<200> package) {
    Serial.println("Sending Package");
    serializeJson(package, Serial);
    Serial.println();
    Serial.println("Package Sent");
}