#include "InjectSensorTask.h"
#include "SensorService.h"

void InjectSensorTask::injectSensorTask(SensorService* services, size_t size){
    Serial.println("Injecting Sensors");
    for(int i = 0; i<size; i++){
        services[i].inject();
    }
    Serial.println("Sensors Injected");
}