#ifndef LIGHTS_H
#define LIGHTS_H

#include "Arduino.h"

enum LED_Pins { LED_RIGHT = 7, LED_LEFT = 4, LED_BLUE = 5, LED_GREEN = 6, LED_RED = 10 };

struct Colour {
  char red, green, blue;
};

class Lights {
  public:
  Lights();
  void set(int light, Colour colour);
};


void led_cycle(Lights *lights, int light, int time);

#endif // LIGHTS_H
