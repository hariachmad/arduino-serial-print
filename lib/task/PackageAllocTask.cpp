#include "PackageAllocTask.h"
#include "ArduinoJson.h"

StaticJsonDocument<200> PackageAllocTask::allocPackage() {
    return Package::package;
}