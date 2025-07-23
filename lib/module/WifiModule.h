#ifndef Wifi_Module_h
#define Wifi_Module_h

#include <WiFi.h>
class WifiModule
{
private:
    const char *ssid = "hidupjokowi";
    const char *password = "tabassam";
    IPAddress localIp;
    wl_status_t status;
    WiFiClient client;
public:
    WifiModule();
    void setup();
    wl_status_t getStatus();
    IPAddress getLocalIp();
    WiFiClient*getClient();
};

#endif