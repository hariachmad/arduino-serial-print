#include "MessageModule.h"
#include <ArduinoJson.h>
#include "../../src/main.h"

void Payload::dispatch(){
  StaticJsonDocument<256> doc;

  doc["sequence"] = payload.seuqence;
  doc["temperature"] = payload.temperature;
  doc["humidity"] = payload.humidity;
  doc["latitude"] = payload.latitude;
  doc["longitude"] = payload.longitude;
  doc["altitude"] = payload.altitude;
  doc["id_vehicle"] = payload.id;
  doc["name"]=payload.name;
  doc["version"] = "1";

  serializeJson(doc, Serial2);
  Serial.println("Data sent: " + doc.as<String>()); 
  Serial.println();
  payload.seuqence++;
  //delay(5000);
}