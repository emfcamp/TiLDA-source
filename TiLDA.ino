#include "lights.h"
#include "pins.h"

Lights lights;

unsigned long last_button_down = 0;
bool torch_on = false;

void button_press() {
  // Interrupt handler when button state changes
  int state = digitalRead(PIN_BUTTON);
  if (state == LOW) { // Low means pressed
    last_button_down = millis();
  } else if (state == HIGH) {
    if (last_button_down != 0 && last_button_down < millis() - 1000) {
      // Engage torch mode
      Colour c;
      c.green = c.blue = c.red = 255;
      lights.set(PIN_LED_LEFT, c);
      torch_on = true;
      return;
    }
    if (torch_on) {
      Colour c;
      c.green = c.blue = c.red = 0;
      lights.set(PIN_LED_LEFT, c);
      torch_on = false;
    }
  }
}

void setup() {
  led_cycle(&lights, PIN_LED_LEFT, 500);
  led_cycle(&lights, PIN_LED_RIGHT, 500);
  pinMode(PIN_BUTTON, INPUT_PULLUP);
  attachInterrupt(INT_BUTTON, button_press, CHANGE);
}

void loop() {

}


