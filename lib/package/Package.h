#ifndef PACKAGE_H
#define PACKAGE_H
#include <ArduinoJson.h>

class Package{
    public:
        static StaticJsonDocument<200> package; 
};

#endif