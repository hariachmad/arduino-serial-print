#include <Arduino.h>
#include "../lib/shared/common.h"
#include "../lib/module/BmeModule.h"
#include "../lib/module/GpsModule.h"
#include "../lib/module/buttonModule.h"
#include <SoftwareSerial.h>

Payload payload;
BmeModule bmeModule;
GpsModule gpsModule;

Button sendButton(2); // Pin untuk tombol kirim data

void setup()
{
  sendButton.begin();
  Serial.begin(115200);
  gpsSerial.begin(9600); // (Pin 19 RX, Pin 18 TX)
  Serial2.begin(115200);
  bmeModule.setupBME(0x76);
}

void loop()
{
  while (gpsSerial.available() > 0)
  {
    char c = gpsSerial.read();
    gpsModule.getGPS().encode(c);

    if (sendButton.isPressed())
    {
      bmeModule.injectBME(bmeModule.getBME().readTemperature(), bmeModule.getBME().readHumidity());
      double bmeAltitude = bmeModule.getBME().readAltitude(1013.25);
      if (gpsModule.getGPS().location.isValid())
      {
        gpsModule.injectGPS(gpsModule.getGPS().location.lat(), gpsModule.getGPS().location.lng(), bmeAltitude);
        payload.tampilkanPayload();
      }
      else
      {
        payload.tampilkanPayload();
      }
    }
  }

  if (millis() > 5000 && gpsModule.getGPS().charsProcessed() < 10)
  {
    Serial.println("GPS tidak terhubung!");
    while (true)
      ;
  }
}
