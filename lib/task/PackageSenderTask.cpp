#include "PackageSenderTask.h"
#include "../package/Package.h"
#include <Arduino.h>
#include "../module/LedModule.h"
#include "../module/MqttModule.h"


void PackageSenderTask::sendPackage(MqttModule*mqttModule) {
    LedModule ledModule(14);
    ledModule.on();
    Serial.println("Sending Package");
    serializeJson(Package::package, Serial);
    mqttModule->publish("psi_lora_package", Package::package.as<String>().c_str());
    Serial.println();
    Serial.println("Package Sent");
    delay(5000);
    ledModule.off();
}