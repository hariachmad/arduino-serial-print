#ifndef SENSOR_SERVICE_H
#define SENSOR_SERVICE_H
#include "ISensor.h"

class SensorService{
    private:
        ISensor* sensor;
    public:
        SensorService(ISensor* sensor);
        void inject();
        void setup();
        void invoke(const void* param);
        ISensor* getSensor();
};

#endif