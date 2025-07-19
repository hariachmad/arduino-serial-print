#ifndef GPS_INVOKER_TASK_H
#define GPS_INVOKER_TASK_H


#include "../module/SensorService.h"

class GpsInvokerTask{
    public:
        static void gpsInvokerTask(SensorService* service);
};

#endif