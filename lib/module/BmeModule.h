#ifndef BME_MODULE_H
#define BME_MODULE_H

#include <Wire.h>
#include <ISensor.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

struct BmeParam{
    double humidity;
    double temperature;
    double altitude;
};

class BmeModule : public ISensor
{
private:
    Adafruit_BME280 bme;
    double humidity;
    double temperature;
    double altitude;
    int address;
public:
    Adafruit_BME280 &getBME();
    BmeModule(int address);
    void inject() override;
    void setup() override;
    void invoke(const void* param);
};

#endif