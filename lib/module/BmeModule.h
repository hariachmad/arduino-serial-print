#ifndef BME_MODULE_H
#define BME_MODULE_H

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

class BmeModule
{
private:
    Adafruit_BME280 bme;

public:
    Adafruit_BME280 &getBME();
    BmeModule();
    void injectBME(float temperature, float humidity);
    void setupBME(int address);
};

#endif