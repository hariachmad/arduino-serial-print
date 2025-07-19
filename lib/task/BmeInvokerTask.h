#ifndef BME_INVOKER_TASK_H
#define BME_INVOKER_TASK_H

#include "../module/SensorService.h"

class BmeInvokerTask{
    public:
        static void bmeInvokerTask(SensorService* service);
};

#endif