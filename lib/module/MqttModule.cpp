#include "MqttModule.h"

MqttModule::MqttModule(WifiModule *_wifiModule)
{
    PubSubClient _client(*_wifiModule->getClient());
    this->wifiModule = _wifiModule;
    this->client = &_client;
    this->client->setServer(mqttServer, mqttPort);
    this->client->setCallback(callback);
}

void MqttModule::reconnect()
{
    while (!client->connected())
    {
        Serial.print("Menghubungkan ke MQTT...");
        if (client->connect("esp32client"))
        {
            Serial.println("terhubung");
            client->subscribe("remote");
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

void MqttModule::publish(const char *topic, const char *message)
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

void MqttModule::loop()
{
    if (!client->connected())
    {
        reconnect();
    }
    client->loop();
}