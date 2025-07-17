#include "../../src/main.h"
#include "AttributesModule.h"

void AttributesModule::injectAttributes(int id, char* name){
  payload.id = id;
  payload.name = name;
}