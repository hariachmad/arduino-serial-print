#include "BmeModule.h"
#include "AttributesModule.h"
#include <string.h>
#include "../package/Package.h"

void BmeModule::inject()
{
    Package::package["humidity"] = humidity;
    Package::package["temperature"] = temperature;
    Package::package["altitude"] = altitude;
}

void BmeModule::invoke(const void* param){
    const BmeParam* params = static_cast<const BmeParam*>(param);
    humidity = params->humidity;
    temperature = params->temperature;
    altitude = params->altitude;
}

void BmeModule::setup()
{
    bool status = BmeModule::bme.begin(BmeModule::address);
    Serial.println("Setuping BME");
    while (!status)
    {
        Serial.println("BME280 tidak ditemukan, cek koneksi!");
        delay(1000);
    }
};

BmeModule::BmeModule(int _address){
    address = _address;
};

Adafruit_BME280& BmeModule::getBME(){
    return BmeModule::bme;
}