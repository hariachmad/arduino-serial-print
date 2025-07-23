#include "WifiConnectionTask.h"

void WifiConnectionTask::wifiConnectionTask(WifiModule *_wifiModule)
{
    _wifiModule->setup();
    if (_wifiModule->getStatus() != WL_CONNECTED)
        _wifiModule->setup();
    Serial.println("Wifi Connected to: " + _wifiModule->getLocalIp().toString());
}