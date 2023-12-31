#include "Led.h"
#include "LedBlinker.h"
#include "PushButton.h"
#include "TrafficLight.h"

#define RED_LED_PIN 11
#define YELLOW_LED_PIN 10
#define GREEN_LED_PIN 9
#define BUTTON_PIN 2

Led redLed(RED_LED_PIN);
Led yellowLed(YELLOW_LED_PIN);
Led greenLed(GREEN_LED_PIN);
LedBlinker greenLedBlinker(greenLed, 100);
PushButton button(BUTTON_PIN, true, true);
TrafficLight trafficLight(
      redLed, yellowLed, greenLed,
      greenLedBlinker, button);

void setup() {
  trafficLight.init();
}

void loop() {
  trafficLight.update();
}
