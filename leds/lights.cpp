#include "lights.h"

int pins[] = {LED_RIGHT, LED_LEFT, LED_BLUE, LED_GREEN, LED_RED};

Lights::Lights() {
  for (int i = 0; i < 6; i++) {
      pinMode(pins[i], OUTPUT);
      digitalWrite(pins[i], HIGH);
  }
}

void Lights::set(int light, Colour colour) {
  analogWrite(LED_RED, 255-colour.red);
  analogWrite(LED_GREEN, 255-colour.green);
  analogWrite(LED_BLUE, 255-colour.blue);
  if (light == LED_RIGHT) {
    digitalWrite(LED_RIGHT, HIGH);
    digitalWrite(LED_LEFT, LOW);
  } else if (light == LED_LEFT) {
    digitalWrite(LED_LEFT, HIGH);
    digitalWrite(LED_RIGHT, LOW);
  }
}
