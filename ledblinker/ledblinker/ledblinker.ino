#include "Led.h"
#include "LedBlinker.h"

#define RED_LED_PIN 11
#define YELLOW_LED_PIN 10
#define GREEN_LED_PIN 9

Led redLed(RED_LED_PIN);
Led yellowLed(YELLOW_LED_PIN);
Led greenLed(GREEN_LED_PIN);

LedBlinker redLedBlinker(redLed, 200);
LedBlinker yellowLedBlinker(yellowLed, 450);
LedBlinker greenLedBlinker(greenLed, 899);

void setup() {
  redLedBlinker.initLed();
  yellowLedBlinker.initLed();
  greenLedBlinker.initLed();
}

void loop() {
  redLedBlinker.update();
  yellowLedBlinker.update();
  greenLedBlinker.update();
}
