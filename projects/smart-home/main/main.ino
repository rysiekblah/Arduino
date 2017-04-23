#include "LightSensor.h"
int buttonPin = 2;                          // button pin -- Digital 2
int relayPin = 3;                           // relay pin -- Digital 3
int lightsPin = 13;
int analogPin = 0;
int relayState = HIGH;
int buttonState;
int lastButtonState = LOW;
long lastDebounceTime = 0;
long debounceDelay = 50;
int lightSensorVal = 0;

LightSensor lightSensor(lightsPin, analogPin, 1000, 9600);

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(relayPin, OUTPUT);
//  pinMode(lightsPin, OUTPUT);

  digitalWrite(relayPin, relayState);
//  digitalWrite(lightsPin, HIGH);

//  Serial.begin(9600);
}
void loop() {
   // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH),  and you've waited
  // long enough since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the Relay if the new button state is HIGH
      if (buttonState == HIGH) {
        relayState = !relayState;
      }
    }
  }

   // set the relay:
  digitalWrite(relayPin, relayState);

  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = reading;

  lightSensor.read();

  // Light sensor
//  lightSensorVal = analogRead(0);         // read voltage value
//  Serial.println(lightSensorVal);
//  if(lightSensorVal<1000){                // if the value is less than 1000，LED turns off
//    digitalWrite(lightsPin,LOW);
//  }else{                        // if the value is more than 1000，LED turns on
//    digitalWrite(lightsPin,HIGH);
//  }
//  delay(10);
}
