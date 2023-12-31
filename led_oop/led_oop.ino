#define LED_PIN 13

class Led 
{
private:
  byte pin;
public:
  Led() {} // do not use

  Led(byte pin)
  {
    this->pin = pin;
  }

  void init()
  {
    pinMode(pin, OUTPUT);
  }

  void init(byte defaultState)
  {
    init();
    if (defaultState == HIGH) {
      on();
    }
    else {
      off();
    }
  }

  void on()
  {
    digitalWrite(pin, HIGH);
  }

  void off()
  {
    digitalWrite(pin, LOW);
  }
};

Led led(LED_PIN);

void setup() {
  led.init();
}

void loop() {
  led.on();
  delay(500);
  led.off();
  delay(500);
}
