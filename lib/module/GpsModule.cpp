#include "GpsModule.h"
#include "../../src/main.h"

void GpsModule::injectGPS(double latitude, double longitude, double altitude){
  payload.latitude = latitude;
  payload.longitude = longitude;
  payload.altitude = altitude;
}

void GpsModule::tampilkanDataGPS()
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

GpsModule::GpsModule(){};
TinyGPSPlus& GpsModule::getGPS(){
  return gps;
}