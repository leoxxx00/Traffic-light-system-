#define LED_PIN 13
#include <Led.h>
Led led(LED_PIN);
void setup()
{
  led.init();
}
void loop()
{
led.on();
delay(1000);  
led.off();
delay(500);  
}

 

