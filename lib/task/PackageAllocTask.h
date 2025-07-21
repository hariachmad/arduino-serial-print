#include "Package.h"
#include <ArduinoJson.h>

class PackageAllocTask{
    public:
        static StaticJsonDocument<200> allocPackage();
};