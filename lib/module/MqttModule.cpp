#include "MqttModule.h"

MqttModule::MqttModule(WifiModule *_wifiModule)
{
    this->client = new PubSubClient(*this->wifiModule->getClient());
    this->wifiModule = _wifiModule;
}

void MqttModule::reconnect(PubSubClient *client)
{
    while (!client->connected())
    {
        Serial.print("Menghubungkan ke MQTT...");
        if (client->connect("esp32client"))
        {
            Serial.println("terhubung");
            client->subscribe("psilre32");
        }
        else
        {
            Serial.print("gagal, rc=");
            Serial.print(client->state());
            Serial.println(" coba lagi dalam 5 detik");
            delay(5000);
        }
    }
}

void MqttModule::publish(PubSubClient* client,const char *topic, const char *message)
{
    client->publish(topic, message);
}

void MqttModule::callback(char *topic, uint8_t *payload, unsigned int length)
{
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("] ");
    for (int i = 0; i < length; i++)
    {
        Serial.print((char)payload[i]);
    }
    Serial.println();
}

void MqttModule::setup(PubSubClient *client)
{
    const char *mqttServer = "192.168.1.21";
    const int mqttPort = 1883;
    client->setServer(mqttServer, mqttPort);
    client->setCallback(callback);
}

// void MqttModule::loop()
// {
//     if (!client->connected())
//     {
//         // reconnect();
//     }
//     client->loop();
// }