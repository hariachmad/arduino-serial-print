#ifndef PACKAGE_ALLOC_TASK_H
#define PACKAGE_ALLOC_TASK_H    

#include "Package.h"
#include <ArduinoJson.h>

class PackageAllocTask{
    public:
        static StaticJsonDocument<200> allocPackage();
};

#endif