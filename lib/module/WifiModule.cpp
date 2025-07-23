#include "WifiModule.h"

WifiModule::WifiModule() {
    setup();
}

void WifiModule::setup() {
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        Serial.println("Connecting WIFI");
        delay(1000);
    }
    localIp = WiFi.localIP();
}

wl_status_t WifiModule::getStatus() {
    return WiFi.status();
}

IPAddress WifiModule::getLocalIp() {
    return localIp;
}

WiFiClient* WifiModule::getClient() {
    return &client;
}   