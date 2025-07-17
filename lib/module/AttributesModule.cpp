#include "../../src/main.h"
#include "AttributesModule.h"
#include <Arduino.h>

void AttributesModule::injectAttributes(int id, String name){
  payload.id = id;
  payload.name = name;
}