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

// String AttributesModule::generateRandomString(int length){
//   const char charset[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM123456789!@#$%^&*()";
//   const int charsetLength= sizeof(charset)-1;
//   String randomString= "";

//   for(int i=0;i<length;i++){
//     int index=random(0,charsetLength);
//     randomString+= charset[index];
//   }

//   return randomString;
// }