#include <Arduino.h>
#include "../lib/module/MessageModule.h"
#include "../lib/module/BmeModule.h"
#include "../lib/module/GpsModule.h"

Payload payload;
BmeModule bmeModule;
GpsModule gpsModule;

void setup()
{
  Serial.begin(115200);
  Serial1.begin(9600); // (Pin 19 RX, Pin 18 TX)
  Serial2.begin(115200); // (Pin 17 RX, Pin 16 TX)
  bmeModule.setupBME(0x76);
}

void loop()
{
  while (Serial1.available() > 0)
  {
    bmeModule.injectBME(bmeModule.getBME().readTemperature(), bmeModule.getBME().readHumidity());
    double bmeAltitude = bmeModule.getBME().readAltitude(1013.25);
    char c = Serial1.read();
    if (gpsModule.getGPS().encode(c))
    {
      if(gpsModule.getGPS().location.isValid()){
        gpsModule.injectGPS(gpsModule.getGPS().location.lat(), gpsModule.getGPS().location.lng(), bmeAltitude);
        payload.dispatch();
      }else{
        payload.dispatch();
      }      
    }
  }
  Serial.println("Membaca data GPS...");
  if (millis() > 5000 && gpsModule.getGPS().charsProcessed() < 10)
  {
    Serial.println("GPS tidak terhubung!");
    while (true)
      ;
  }
}


