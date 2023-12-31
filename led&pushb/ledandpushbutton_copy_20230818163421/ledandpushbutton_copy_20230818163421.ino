#include "Led.h"
#include "PushButton.h"
#define RED_LED_PIN 11
#define YELLOW_LED_PIN 10
#define GREEN_LED_PIN 9
#define BUTTON_PIN 2

Led redLed(RED_LED_PIN);
Led yellowLed(YELLOW_LED_PIN);
Led greenLed(GREEN_LED_PIN);
PushButton button(BUTTON_PIN,true,true);

void setup() {
redLed.init();
yellowLed.init();
greenLed.init();
button.init();
}

void loop() {
  if (button.isPressed()){
    redLed.on();
    yellowLed.off();
    greenLed.on();
  }
  else{
  redLed.off();
  yellowLed.on();
  greenLed.off();
  }
}
