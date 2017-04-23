
#include "RelayInOut.h"
#include "LightSensor.h"

// Relay
int buttonPin = 2;                          // button pin -- Digital 2
int relayPin = 3;                           // relay pin -- Digital 3
int relayState = HIGH;
long debounceDelay = 50;

// Light sensor
int lightsPin = 13;
int analogPin = 0;

LightSensor lightSensor(lightsPin, analogPin, 1000, 9600);
RelayInOut relayInOn(buttonPin, relayPin, relayState, debounceDelay);

void setup() {
}

void loop() {
  relayInOn.check();
  lightSensor.read();
}
