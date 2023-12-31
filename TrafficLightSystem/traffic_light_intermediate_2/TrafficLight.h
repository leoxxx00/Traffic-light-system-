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

  enum trafficLightState {
    STATE_RED,
    STATE_YELLOW,
    STATE_GREEN,
    STATE_BLINK_GREEN
  };

  int state;

  unsigned long yellowStateStartTime;
  unsigned long greenStateStartTime;
  unsigned long blinkGreenStateStartTime;

  const int yellowStateDuration = 3000;
  const int greenStateDuration = 2000;
  const int blinkGreenStateDuration = 3000;

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

  void update();
};

#endif
