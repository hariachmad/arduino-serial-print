#include "AttributesModule.h"
#include <Arduino.h>
#include "../package/Package.h"

void AttributesModule::setup(){
  #if defined(VehicleID) && defined(VehicleName)
    id = int(VehicleID);
    name = String(VehicleName);
  #else
    id = 0;
    name = "Unknown";
  #endif
}

void AttributesModule::inject(){
  Package::package["id"] = id;
  Package::package["name"] = name;
}

void AttributesModule::invoke(const void* param){
  return;
}