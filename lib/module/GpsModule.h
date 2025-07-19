#ifndef GPS_MODULE_H
#define GPS_MODULE_H
#include <TinyGPS++.h>
#include <ISensor.h>

struct GpsParam{
  double longitude;
  double latitude;
};

class GpsModule : public ISensor{
    private:
        TinyGPSPlus gps;
        double latitude;
        double longitude;
    public:
        void inject() override;
        void setup() override;
        void invoke(const void* param) override;
        TinyGPSPlus& getGPS();
};

#endif

