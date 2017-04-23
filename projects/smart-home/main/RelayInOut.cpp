#include "RelayInOut.h"

RelayInOut::RelayInOut(int inPin, int outPin, int relayInitState, long debounceDelay)
{
  pinMode(inPin, INPUT);
  pinMode(outPin, OUTPUT);
  digitalWrite(outPin, relayInitState);
  _relayState = relayInitState;
  _inPin = inPin;
  _outPin = outPin;
  _debounceDelay = debounceDelay;
  _lastDebounceTime = 0;
  _lastButtonState = LOW;
}

void RelayInOut::check()
{
  // read the state of the switch into a local variable:
  int reading = digitalRead(_inPin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH),  and you've waited
  // long enough since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != _lastButtonState) {
    _lastDebounceTime = millis();
  }

  if ((millis() - _lastDebounceTime) > _debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != _buttonState) {
      _buttonState = reading;

      // only toggle the Relay if the new button state is HIGH
      if (_buttonState == HIGH) {
        _relayState = !_relayState;
      }
    }
  }

  // set the relay:
  digitalWrite(_outPin, _relayState);

  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  _lastButtonState = reading;

}
