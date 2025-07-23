#ifndef PACKAGE_SENDER_TASK_H
#define PACKAGE_SENDER_TASK_H

#include "Package.h"
#include "../module/MqttModule.h"

class PackageSenderTask{
    public:
        static void sendPackage(MqttModule*mqttModule);

};

#endif