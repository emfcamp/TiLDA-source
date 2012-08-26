#ifndef LIGHTS_H
#define LIGHTS_H

#include "Arduino.h"
#include "pins.h"

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
