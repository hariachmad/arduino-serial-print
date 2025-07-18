#include "BmeModule.h"
#include "../../src/main.h"
#include "AttributesModule.h"
#include <string.h>

void BmeModule::injectBME(float temperature, float humidity)
{
    payload.temperature = temperature;
    payload.humidity = humidity;
}

void BmeModule::setupBME(int address)
{
    bool status = BmeModule::bme.begin(0x76);
    Serial.println("Setup BME");
    while (!status)
    {
        Serial.println("BME280 tidak ditemukan, cek koneksi!");
        delay(1000);
    }
    // BmeModule::injectBME(bme.readTemperature(), bme.readHumidity());
    #if defined(VehicleID) && defined(VehicleName)
    AttributesModule::injectAttributes(int(VehicleID), String(VehicleName));
    #endif
};

BmeModule::BmeModule(){};

Adafruit_BME280& BmeModule::getBME(){
    return BmeModule::bme;
}