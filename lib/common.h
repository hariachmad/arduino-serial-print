#ifndef COMMON_H
#define COMMON_H

#include <TinyGPS++.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

struct Payload
{
  String id;
  String name;
  int seuqence = 1;
  float temperature;
  float humidity;
  double latitude=0.0;
  double longitude=0.0;
  double altitude=0.0;
};

void tampilkanPayload();
void injectGPS(double latitude, double longitude, double altitude);
void injectBME(float temperature, float humidity);

#endif