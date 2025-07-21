#include <Arduino.h>
#include "../lib/module/MessageModule.h"
#include "../lib/module/BmeModule.h"
#include "../lib/module/GpsModule.h"
#include "../lib/module/ButtonModule.h"
#include "../lib/module/ISensor.h"
#include "../lib/module/AttributesModule.h"
#include "../lib/module/SensorService.h"
#include <TaskScheduler.h>
#include "../lib/task/InjectSensorTask.h"
#include "../lib/task/GpsInvokerTask.h"
#include "../lib/task/BmeInvokerTask.h"

BmeModule bmeModule(0x76);
GpsModule gpsModule;
AttributesModule attributesModule;

SensorService bmeSensorService(&bmeModule);
SensorService gpsSensorService(&gpsModule);
SensorService attributesSensorService(&attributesModule);

SensorService services[3] = {bmeSensorService, gpsSensorService, attributesSensorService};

Scheduler runner;

Task injectorTask(5000, TASK_FOREVER, []()
                  { InjectSensorTask::injectSensorTask(services, 3); }, &runner);

Task gpsInvokerTask(1000, TASK_FOREVER, []()
                    { GpsInvokerTask::gpsInvokerTask(&gpsSensorService); }, &runner);

Task bmeInvokerTask(2000, TASK_FOREVER, []()
                    { BmeInvokerTask::bmeInvokerTask(&bmeSensorService); }, &runner);

// AttributesModule sudah melakukan invoke saat setup

void setup()
{
  Serial.begin(115200);
  Serial1.begin(9600);
  Serial2.begin(115200);

  Serial.print("setup begin");

  bmeSensorService.setup();
  gpsSensorService.setup();
  attributesSensorService.setup(); 

  Serial.println("adding Tasks...");

  runner.addTask(injectorTask);
  runner.addTask(gpsInvokerTask);
  runner.addTask(bmeInvokerTask);

  injectorTask.enable();
  gpsInvokerTask.enable();
  bmeInvokerTask.enable();

  Serial.println("Setup completed successfully");
  delay(1000);
}

void loop()
{
  runner.execute();
}
