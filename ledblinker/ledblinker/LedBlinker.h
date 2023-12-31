#ifndef LED_BLINKER_H
#define LED_BLINKER_H

#include <Arduino.h>
#include "Led.h"

class LedBlinker 
{
private:
  Led led;
  unsigned long lastTimeBlinked;
  unsigned long blinkDelay;

  void toggleLed();

public:
  LedBlinker() {} // do not use
  LedBlinker(Led &led);
  LedBlinker(Led &led, unsigned long blinkDelay);

  void initLed();

  void update();

  unsigned long getBlinkDelay();
  void setBlinkDelay(unsigned long blinkDelay);
};

#endif
