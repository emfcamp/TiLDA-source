#include "lights.h"
#include "pins.h"

Lights lights;

void setup() {

}

void loop() {
  led_cycle(&lights, PIN_LED_BOTH, 2500);
}


