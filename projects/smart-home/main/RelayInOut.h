#ifndef RELAY_IN_OUT_H
#define RELAY_IN_OUT_H

#include "Arduino.h"

class RelayInOut {

  public:
    RelayInOut(int inPin, int outPin, int relayInitState, long debounceDelay);
    void check();

  private:
    int _inPin;
    int _outPin;
    int _relayState;
    int _lastButtonState;
    long _debounceDelay;
    long _lastDebounceTime;
    int _buttonState;

};

#endif
