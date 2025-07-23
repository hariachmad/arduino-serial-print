#include "PackageSenderTask.h"
#include "../package/Package.h"
#include <Arduino.h>
#include "../module/LedModule.h"


void PackageSenderTask::sendPackage() {
    LedModule ledModule(14);
    ledModule.on();
    Serial.println("Sending Package");
    serializeJson(Package::package, Serial);
    Serial.println();
    Serial.println("Package Sent");
    delay(5000);
    ledModule.off();
}