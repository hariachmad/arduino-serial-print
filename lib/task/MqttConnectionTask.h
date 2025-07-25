#include <PubSubClient.h>

#ifndef MqttConnectionTask_h
#define MqttConnectionTask_h

class MqttConnectionTask
{
    public:
        static void mqttConnectionTask(PubSubClient* client);
};

#endif