#include <Arduino.h>

#ifndef COMMON_H
#define COMMON_H

struct Payload
{
  int id;
  String name;
  int seuqence = 1;
  float temperature;
  float humidity;
  double latitude = 0.0;
  double longitude = 0.0;
  double altitude = 0.0;

  void dispatch();
};

#endif