#ifndef COMMON_H
#define COMMON_H

#define GPS_RX_PIN 3
#define GPS_TX_PIN 4

extern SoftwareSerial gpsSerial(GPS_RX_PIN, GPS_TX_PIN);
struct Payload
{
  int id;
  char* name;
  int seuqence = 1;
  float temperature;
  float humidity;
  double latitude = 0.0;
  double longitude = 0.0;
  double altitude = 0.0;

  void tampilkanPayload();
};

#endif