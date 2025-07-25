#include "PackageSenderTask.h"
#include "../package/Package.h"
#include <Arduino.h>
#include "../module/LedModule.h"
#include "../module/MqttModule.h"
#include "../module/RandomStringGenerator.h"

void PackageSenderTask::sendPackage(PubSubClient* client) {
    LedModule ledModule(14);
    ledModule.on();
    Serial.println("Sending Package");
    Package::package["uuid"] = RandomStringGenerator::execute(8);
    serializeJson(Package::package, Serial);
    String packageString;
    serializeJson(Package::package, packageString);
    MqttModule::publish(client, "psilre32", packageString.c_str());
    Serial.println();
    Serial.println("Package Sent");
    Package::package.clear();
    delay(5000);
    ledModule.off();
}