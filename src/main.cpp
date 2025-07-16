#include <Arduino.h>
#include "../lib/common.h"
#include <ArduinoJson.h>

// #include <TinyGPS++.h>
// #include <Wire.h>
// #include <Adafruit_Sensor.h>
// #include <Adafruit_BME280.h>

// struct Payload
// {
//   float temperature;
//   float humidity;
//   double latitude=0.0;
//   double longitude=0.0;
//   double altitude=0.0;
// };

// TinyGPSPlus gps;
// Adafruit_BME280 bme;
// Payload payload;

TinyGPSPlus gps;
Adafruit_BME280 bme;
Payload payload;

void injectBME(float temperature, float humidity){
  payload.temperature = temperature;
  payload.humidity = humidity;
}

void injectGPS(double latitude, double longitude, double altitude){
  payload.latitude = latitude;
  payload.longitude = longitude;
  payload.altitude = altitude;
}

void tampilkanDataGPS()
{
  if (gps.location.isValid())
  {
    Serial.print("Latitude: ");
    Serial.println(gps.location.lat(), 6);
    Serial.print("Longitude: ");
    Serial.println(gps.location.lng(), 6);
    Serial.print("Altitude: ");
    Serial.println(gps.altitude.meters());
    Serial.print("Waktu: ");
    Serial.print(gps.time.hour());
    Serial.print(":");
    Serial.print(gps.time.minute());
    Serial.print(":");
    Serial.println(gps.time.second());
  }
  else
  {
    Serial.println("Lokasi tidak valid!");
  }
  delay(1000);
}

void tampilkanDataBME()
{
  Serial.print("Suhu: ");
  Serial.println(bme.readTemperature());
  Serial.print("Kelembaban: ");
  Serial.println(bme.readHumidity());
  Serial.print("Tekanan: ");
  Serial.println(bme.readPressure() / 100.0F);
  delay(1000);
}

void injectAttributes(int id, String name){
  payload.id = id;
  payload.name = name;
}

void tampilkanPayload(){
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

  // Serial.print("Temperature: ");
  // Serial.println(payload.temperature);
  // Serial.print("Humidity: ");
  // Serial.println(payload.humidity);
  // Serial.print("Latitude: ");
  // Serial.println(payload.latitude);
  // Serial.print("Longitude: ");
  // Serial.println(payload.longitude);
  // Serial.print("Altitude: ");
  // Serial.println(payload.altitude);
  delay(5000);
}
void setup()
{
  Serial.begin(115200);
  Serial1.begin(9600); // (Pin 19 RX, Pin 18 TX)
  Serial2.begin(115200); // (Pin 17 RX, Pin 16 TX)
  bool status = bme.begin(0x76);
  Serial.println("Membaca data GPS...");
  while (!status)
  {
    Serial.println("BME280 tidak ditemukan, cek koneksi!");
    delay(1000);
  }
  injectBME(bme.readTemperature(), bme.readHumidity());
  injectAttributes(1,"testing_vehicle");
}

void loop()
{
  while (Serial1.available() > 0)
  {
    double bmeAltitude = bme.readAltitude(1013.25);
    char c = Serial1.read();
    if (gps.encode(c))
    {
      if(gps.location.isValid()){
        injectGPS(gps.location.lat(), gps.location.lng(), bmeAltitude);
        tampilkanPayload();
        // tampilkanDataGPS();
      }else{
        tampilkanPayload();
      }

      
      // tampilkanPayload();
    }
    
  }
  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println("GPS tidak terhubung!");
    while (true)
      ;
  }
}


