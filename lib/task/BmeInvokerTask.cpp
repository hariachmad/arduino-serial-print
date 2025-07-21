#include "BmeInvokerTask.h"
#include "../module/BmeModule.h"

void BmeInvokerTask::bmeInvokerTask(SensorService* service){
    Serial.println("Invoking BME...");
    BmeModule *sensor = static_cast<BmeModule *>(service->getSensor());
    BmeParam* bmeParam = new BmeParam();
    bmeParam->temperature = sensor->getBME().readTemperature();
    bmeParam->humidity = sensor->getBME().readHumidity();
    bmeParam->altitude = sensor->getBME().readAltitude(1013.25);
    service->invoke(bmeParam);
    Serial.println("BME Invoked");    
}