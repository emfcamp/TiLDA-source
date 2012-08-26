#include "lights.h"

int pins[] = {PIN_LED_RIGHT, PIN_LED_LEFT, PIN_LED_BLUE, PIN_LED_GREEN, PIN_LED_RED};

Lights::Lights() {
  for (int i = 0; i < 6; i++) {
      pinMode(pins[i], OUTPUT);
      digitalWrite(pins[i], HIGH);
  }
}

int logScale(int value) {
  return (int)((log(255 - value) / log(255)) * 255);
}

void Lights::set(int light, Colour colour) {
  analogWrite(PIN_LED_RED, logScale(colour.red * 0.8));
  analogWrite(PIN_LED_GREEN, logScale(colour.green));
  analogWrite(PIN_LED_BLUE, logScale(colour.blue));
  if (light == PIN_LED_RIGHT) {
    digitalWrite(PIN_LED_RIGHT, HIGH);
    digitalWrite(PIN_LED_LEFT, LOW);
  } else if (light == PIN_LED_LEFT) {
    digitalWrite(PIN_LED_LEFT, HIGH);
    digitalWrite(PIN_LED_RIGHT, LOW);
  }
}

void led_cycle(Lights *lights, int light, int time) {
  Colour c;
  char brightness = 128;
  float step = (2 * PI) / time;
  for (float i = 0; i < 2 * PI; i += step) {
    c.red = (int)(abs(sin(i)) * brightness);
    c.green = (int)(abs(sin(i + PI / 2)) * brightness);
    c.blue = (int)(abs(sin(i + PI)) * brightness);
    lights->set(light, c);
    delay(1);
  }
  c.red = 0; c.green = 0; c.blue = 0;
  lights->set(light, c);
}
