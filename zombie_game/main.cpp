#include "id_receive.h"
#include "RF24/RF24.h"
#include <avr/io.h>
#include <Arduino.h>
#include <inttypes.h>
#include <avr/eeprom.h>
#include "lights.h"
#include <avr/interrupts.h>

void main(){
  rf_setup();

