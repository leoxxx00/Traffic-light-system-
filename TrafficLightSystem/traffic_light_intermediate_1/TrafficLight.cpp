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
