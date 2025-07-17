#ifndef GPS_MODULE_H
#define GPS_MODULE_H
#include <TinyGPS++.h>

class GpsModule{
    private:
        TinyGPSPlus gps;
    public:
        GpsModule();
        void injectGPS(double latitude, double longitude, double altitude);
        void tampilkanDataGPS();
        TinyGPSPlus& getGPS();
};

#endif

