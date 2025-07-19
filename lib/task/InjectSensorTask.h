#ifndef INJECT_SENSOR_TASK_H
#define INJECT_SENSOR_TASK_H


#include "../module/SensorService.h"

class InjectSensorTask{
    public:
        static void injectSensorTask(SensorService*services, size_t size);
};

#endif