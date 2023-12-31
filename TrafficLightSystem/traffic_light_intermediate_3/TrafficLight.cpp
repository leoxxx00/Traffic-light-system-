#include "TrafficLight.h"

TrafficLight::TrafficLight(
                Led &redLed, Led &yellowLed, Led &greenLed,
                LedBlinker &greenLedBlinker, PushButton &button)
{
  this->redLed = redLed;
  this->yellowLed = yellowLed;
  this->greenLed = greenLed;
  this->greenLedBlinker = greenLedBlinker;
  this->button = button;
}

void TrafficLight::init()
{
  redLed.init();
  yellowLed.init();
  greenLed.init();
  button.init();
  delay(100);

  state = STATE_RED;
  red();
}

void TrafficLight::red()
{
  redLed.on();
  yellowLed.off();
  greenLed.off();
}

void TrafficLight::yellow()
{
  redLed.off();
  yellowLed.on();
  greenLed.off();  
}

void TrafficLight::green()
{
  redLed.off();
  yellowLed.off();
  greenLed.on();  
}

void TrafficLight::allLedsOff()
{
  redLed.off();
  yellowLed.off();
  greenLed.off();  
}

void TrafficLight::update()
{
  unsigned long timeNow = millis();
  
  switch (state) {
    case STATE_RED: {
      red();
      if (button.isPressed()) {
        state = STATE_YELLOW;
        yellowStateStartTime = timeNow;
      }
      break;
    }
    case STATE_YELLOW: {
      yellow();
      if (timeNow - yellowStateStartTime > yellowStateDuration) {
        state = STATE_GREEN;
        greenStateStartTime = timeNow;
      }
      break;
    }
    case STATE_GREEN: {
      green();
      if (timeNow - greenStateStartTime > greenStateDuration) {
        state = STATE_BLINK_GREEN;
        allLedsOff();
        blinkGreenStateStartTime = timeNow;
      }
      break;
    }
    case STATE_BLINK_GREEN: {
      greenLedBlinker.update();
      if (timeNow - blinkGreenStateStartTime > 
                      blinkGreenStateDuration) {
        state = STATE_RED;
      }
      break;
    }
    default: {
      state = STATE_RED;
    }
  }
}
