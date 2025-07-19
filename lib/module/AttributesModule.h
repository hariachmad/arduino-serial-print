#ifndef ATTRIBUTES_MODULE_H
#define ATTRIBUTES_MODULE_H

#include <Arduino.h>
#include <ISensor.h>
class AttributesModule : public ISensor
{
private:
    int id;
    String name;

public:
    void inject() override;
    void setup() override;
    void invoke(const void *param) override;
};
#endif