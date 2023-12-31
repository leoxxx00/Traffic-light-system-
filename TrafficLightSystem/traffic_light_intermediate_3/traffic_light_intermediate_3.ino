#include "Led.h"
#include "LedBlinker.h"
#include "PushButton.h"
#include "Potentiometer.h"
#include "TrafficLight.h"

#define RED_LED_PIN 11
#define YELLOW_LED_PIN 10
#define GREEN_LED_PIN 9
#define BUTTON_PIN 2
#define POTENTIOMETER_PIN A0

Potentiometer potentiometer(POTENTIOMETER_PIN);
Led redLed(RED_LED_PIN);
Led yellowLed(YELLOW_LED_PIN);
Led greenLed(GREEN_LED_PIN);
LedBlinker greenLedBlinker(greenLed, 100);
PushButton button(BUTTON_PIN, true, true);
TrafficLight trafficLight(
      redLed, yellowLed, greenLed,
      greenLedBlinker, button);

void setup() {
  Serial.begin(115200);
  // trafficLight.init();
}

void loop() {
  // trafficLight.update();
  Serial.println(potentiometer.getValue());
  delay(100);
}
