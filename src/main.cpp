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
#include "../lib/task/PackageAllocTask.h"
#include "../lib/package/Package.h"
#include "../lib/task/PackageSenderTask.h"
#include "../lib/module/SwitchButtonModule.h"
#include "../lib/module/SwitchButtonModule.h"
#include "../lib/context/StateContext.h"

SwitchButtonModule switchButtonModule(51);
BmeModule bmeModule(0x76);
GpsModule gpsModule;
AttributesModule attributesModule;
Button buttonModule(50);

SensorService bmeSensorService(&bmeModule);
SensorService gpsSensorService(&gpsModule);
SensorService attributesSensorService(&attributesModule);

SensorService services[3] = {bmeSensorService, gpsSensorService, attributesSensorService};

Scheduler runner;

Task gpsInvokerTask(1000, TASK_FOREVER, []()
                    { GpsInvokerTask::gpsInvokerTask(&gpsSensorService); }, &runner);

Task bmeInvokerTask(2000, TASK_FOREVER, []()
                    { BmeInvokerTask::bmeInvokerTask(&bmeSensorService); }, &runner);

Task injectorTask(5000, TASK_FOREVER, []()
                  { InjectSensorTask::injectSensorTask(services, 3); }, &runner);

Task packageSenderTask(100, TASK_FOREVER, []()
                       { PackageSenderTask::sendPackage(); }, &runner);

Task buttonObserverTask(100, TASK_FOREVER, []()
                        { buttonModule.observer(); }, &runner);

Task switchObserverTask(100, TASK_FOREVER, []()
                        { switchButtonModule.observer(); }, &runner);

Task stateObserverTask(100, TASK_FOREVER, []()
                       {
  if(state == HIGH) {
    packageSenderTask.enableDelayed(100);
    buttonObserverTask.disable();
  }
  if(state == LOW) {
    packageSenderTask.disable();
    buttonObserverTask.enableDelayed(100);
  } }, &runner);

// AttributesModule sudah melakukan invoke saat setup

void setup()
{
  Serial.begin(115200);
  Serial1.begin(9600);
  Serial2.begin(115200);

  Serial.println("setup begin");

  bmeSensorService.setup();
  gpsSensorService.setup();
  attributesSensorService.setup();

  Serial.println("adding Tasks...");

  runner.addTask(injectorTask);
  runner.addTask(gpsInvokerTask);
  runner.addTask(bmeInvokerTask);
  runner.addTask(packageSenderTask);
  runner.addTask(buttonObserverTask);
  runner.addTask(switchObserverTask);
  runner.addTask(stateObserverTask);

  injectorTask.enable();
  gpsInvokerTask.enable();
  bmeInvokerTask.enable();
  packageSenderTask.enable();
  buttonObserverTask.enable();
  switchObserverTask.enable();
  stateObserverTask.enable();

  Serial.println("Setup completed successfully");
  delay(1000);
}

void loop()
{
  runner.execute();
}
