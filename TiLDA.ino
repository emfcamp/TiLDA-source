#include "lights.h"

Lights lights;

void cycle_lights() {
  // Cycle through the lights on startup
  for (float i = 0; i < 2*PI; i += 0.01) {
    analogWrite(13, (int)(abs(sin(i)) * 255));
    delay(1);
  }
  led_cycle(&lights, PIN_LED_LEFT, 1000);
  led_cycle(&lights, PIN_LED_RIGHT, 1000);
}

void setup() {
  cycle_lights();
}

void loop() {
}
