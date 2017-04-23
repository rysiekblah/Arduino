#include "Arduino.h"
#include "LightSensor.h"

LightSensor::LightSensor(int pin, int analogPin, int offset, int speed)
{
  _lightPin = pin;
  _analogPin = analogPin;
  _offset = offset;
  pinMode(_lightPin, OUTPUT);
  digitalWrite(_lightPin, LOW);
  Serial.begin(speed);
}

void LightSensor::read()
{
  _lightLevelValue = analogRead(_analogPin);
  Serial.println(_lightLevelValue);
  if(_lightLevelValue<_offset)
  {
    digitalWrite(_lightPin,LOW);
  }else{
    digitalWrite(_lightPin,HIGH);
  }
  delay(10);
}
