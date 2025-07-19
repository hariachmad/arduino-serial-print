#include "InjectSensorTask.h"
#include "SensorService.h"

void InjectSensorTask::injectSensorTask(SensorService* services, size_t size){
    for(int i = 0; i<size; i++){
        services[i].inject();
    }
}