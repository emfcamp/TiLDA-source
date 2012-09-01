/**
 * Pins:
 * Hardware SPI:
 * MISO -> 12
 * MOSI -> 11
 * SCK -> 13
 *
 * Configurable:
 * CE -> 8
 * CSN -> 7
 */

#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>

void setup() {
  Serial.begin(9600);
}

void begin() {

  Serial.println('initialising');

  // Setup
  Mirf.spi = &MirfHardwareSpi;
  Mirf.cePin = A4;
  Mirf.csnPin = A5;
  Mirf.init();
  Mirf.setRADDR((byte *)"clie1");
  Mirf.payload = sizeof(unsigned long);
  Mirf.config();
  
  // Read and print RF_SETUP
  byte rf_setup = 0;
  byte rf_ch = 0;
  Mirf.readRegister( RF_SETUP, &rf_setup, sizeof(rf_setup) );
  Mirf.readRegister( RF_CH, &rf_ch, sizeof(rf_ch) );
  Serial.print( "rf_setup = " );
  Serial.println( rf_setup, BIN );
  Serial.print( "rf_ch = " );
  Serial.println( rf_ch, BIN );

  Serial.println( "Wireless initialized!" );
}

void loop() {

  if (Serial.available()) {
    char c = tolower(Serial.read());
    if (c == 't') begin();
  }
}
