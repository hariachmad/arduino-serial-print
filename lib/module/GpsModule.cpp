#include "GpsModule.h"
#include "../package/Package.h"

void GpsModule::setup(){
  return;
}

void GpsModule::inject(){
  Package::package["longitude"]= longitude;
  Package::package["latitude"]= latitude;
}

void GpsModule::invoke(const void* param){
  const GpsParam* params = static_cast<const GpsParam*>(param);

  longitude = params->longitude;
  latitude = params->latitude;
  // delete params;
}

TinyGPSPlus& GpsModule::getGPS(){
  return gps;
}