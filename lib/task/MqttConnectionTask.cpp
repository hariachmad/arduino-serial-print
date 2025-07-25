#include "MqttConnectionTask.h"

void MqttConnectionTask::mqttConnectionTask(PubSubClient* client) {
    
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
    Serial.println("Mqtt Connected ");
    client->subscribe("psilre32");
    Serial.print(client->connected());
}