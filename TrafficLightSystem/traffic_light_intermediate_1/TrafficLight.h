#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

#include "Led.h"
#include "LedBlinker.h"
#include "PushButton.h"

class TrafficLight
{
private:
  Led redLed;
  Led yellowLed;
  Led greenLed;
  LedBlinker greenLedBlinker;
  PushButton button;

public:
  TrafficLight() {} // do not use
  TrafficLight(
    Led &redLed, Led &yellowLed, Led &greenLed,
    LedBlinker &greenLedBlinker, PushButton &button);

  void init();

  void red();
  void yellow();
  void green();
  void allLedsOff();
};

#endif
