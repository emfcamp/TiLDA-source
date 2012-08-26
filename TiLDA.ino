#include "lights.h"

Lights lights;

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

void setup() {
  for (float i = 0; i < 2*PI; i += 0.01) {
    analogWrite(13, (int)(abs(sin(i)) * 255));
    delay(5);
  }
  led_cycle(&lights, LED_LEFT, 1000);
  led_cycle(&lights, LED_RIGHT, 1000);
}

void loop() {

  Colour c;
  c.red=0;
  c.green=0;
  c.blue=0;
  //
  //lights.set(LED_LEFT, c);
}
