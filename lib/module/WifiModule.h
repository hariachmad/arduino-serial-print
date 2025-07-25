#ifndef Wifi_Module_h
#define Wifi_Module_h

#include <WiFi.h>
class WifiModule
{
private:
    const char *ssid = "Parametrik01";
    const char *password = "tabassam";
    IPAddress localIp;
    WiFiClient client;
public:
    WifiModule();
    void setup();
    wl_status_t getStatus();
    IPAddress getLocalIp();
    WiFiClient*getClient();
};

#endif