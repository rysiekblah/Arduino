#ifndef LIGHT_SENSOR_H
#define LIGHT_SENSOR_H

#include "Arduino.h"

class LightSensor
{
  public:
    LightSensor(int pin, int analogPin, int offset, int serialSpeed);
    void read();

  private:
    int _lightPin;
    int _analogPin;
    int _offset;
    int _serialSpeed;
    int _lightLevelValue;
};

#endif
