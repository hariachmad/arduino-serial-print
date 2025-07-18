#include <Arduino.h>
#include "../lib/module/MessageModule.h"
#include "../lib/module/BmeModule.h"
#include "../lib/module/GpsModule.h"
#include "../lib/module/buttonModule.h"

Payload payload;
BmeModule bmeModule;
GpsModule gpsModule;

Button sendButton(51);

const int intervalButton = 48;

void sendPayload()
{
  bmeModule.injectBME(bmeModule.getBME().readTemperature(), bmeModule.getBME().readHumidity());
  double bmeAltitude = bmeModule.getBME().readAltitude(1013.25);

  if (gpsModule.getGPS().location.isValid())
  {
    gpsModule.injectGPS(gpsModule.getGPS().location.lat(), gpsModule.getGPS().location.lng(), bmeAltitude);
    payload.dispatch(0);
  }
  else
  {
    payload.dispatch(0);
  }
}

void setup()
{
  Serial.begin(115200);
  // gpsSerial.begin(9600); // (Pin 19 RX, Pin 18 TX)
  Serial1.begin(9600);
  Serial2.begin(115200); // (Pin 17 RX, Pin 16 TX)
  sendButton.begin();
  bmeModule.setupBME(0x76);
  pinMode(intervalButton, INPUT);
}

void loop()
{
  int flag = false;
  // while (gpsSerial.available() > 0)
  while (Serial1.available() > 0)
  {
    int pinInterval = digitalRead(intervalButton);
    Serial.println(pinInterval);
    sendButton.observer();
    char c = Serial1.read();
    gpsModule.getGPS().encode(c);
    if (pinInterval == HIGH)
    {
      sendPayload();
      delay(5000);
      flag = true;
    }
    else if (sendButton.isPressed() && pinInterval == LOW)
    {
      // if (!flag)
      // {
      //   Serial.println("Data dikirim!");
      //   sendPayload();
      // }
      flag = false;
    }

    if(!flag && pinInterval == LOW && sendButton.isPressed()){
      sendPayload();
    }
  }
  if (millis() > 5000 && gpsModule.getGPS().charsProcessed() < 10)
  {
    Serial.println("GPS tidak terhubung!");
    while (true)
      ;
  }
}
