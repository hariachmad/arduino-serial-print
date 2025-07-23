#ifndef MQTT_MODULE_H
#define MQTT_MODULE_H

#include <PubSubClient.h>
#include <WifiModule.h>
#include <Arduino.h>

class MqttModule{
    private:
        PubSubClient* client;
        const char* mqttServer = "broker.emqx.io";
        const int mqttPort = 1883;
        WifiModule* wifiModule;
    public:
        MqttModule(WifiModule* _wifiModule);
        void reconnect();
        static void callback(char *topic, uint8_t*payload, unsigned int length);
        void publish(const char *topic,const char * message);
        void loop();
};

#endif