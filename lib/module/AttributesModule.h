#include <Arduino.h>

#ifndef ATTRIBUTES_MODULE_H
#define ATTRIBUTES_MODULE_H
class AttributesModule{
    public:
        static void injectAttributes(int id, String name);
};
#endif