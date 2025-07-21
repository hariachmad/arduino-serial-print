#include "GpsInvokerTask.h"
#include "../module/GpsModule.h"

void GpsInvokerTask::gpsInvokerTask(SensorService *service)
{
    Serial.println("Invoking GPS...");
    while (Serial1.available() > 0)
    {
        char c = Serial1.read();
        GpsModule *sensor = static_cast<GpsModule *>(service->getSensor());
        sensor->getGPS().encode(c);
        if (sensor->getGPS().location.isValid())
        {
            GpsParam *gpsParam;
            gpsParam->latitude = sensor->getGPS().location.lat();
            gpsParam->longitude = sensor->getGPS().location.lng();
            service->invoke(gpsParam);
        }
        if (millis() > 5000 && sensor->getGPS().charsProcessed() < 10)
        {
            Serial.println("GPS tidak terhubung!");
            while (true)
                ;
        }
    }
    Serial.println("GPS Invoked");
}