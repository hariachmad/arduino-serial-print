#ifndef MQTT_MODULE_H
#define MQTT_MODULE_H

#include <PubSubClient.h>
#include <WifiModule.h>
#include <Arduino.h>

class MqttModule{
    private:
        PubSubClient* client;
        WifiModule* wifiModule;
    public:
        MqttModule(WifiModule* _wifiModule);
        static void reconnect(PubSubClient* client);
        static void callback(char *topic, uint8_t*payload, unsigned int length);
        static void setup(PubSubClient* client);
        static void publish(PubSubClient* client,const char *topic, const char *message);
};

#endif