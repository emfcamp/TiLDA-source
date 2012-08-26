#include "lights.h"

int pins[] = {LED_RIGHT, LED_LEFT, LED_BLUE, LED_GREEN, LED_RED};

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
  analogWrite(LED_RED, logScale(colour.red));
  analogWrite(LED_GREEN, logScale(colour.green));
  analogWrite(LED_BLUE, logScale(colour.blue));
  if (light == LED_RIGHT) {
    digitalWrite(LED_RIGHT, HIGH);
    digitalWrite(LED_LEFT, LOW);
  } else if (light == LED_LEFT) {
    digitalWrite(LED_LEFT, HIGH);
    digitalWrite(LED_RIGHT, LOW);
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
