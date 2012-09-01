/**
 * A Mirf example to test the latency between two Ardunio.
 *
 * Pins:
 * Hardware SPI:
 * MISO -> 12
 * MOSI -> 11
 * SCK -> 13
 *
 * Configurable:
 * CE -> 8
 * CSN -> 7
 *
 * Note: To see best case latency comment out all Serial.println
 * statements not displaying the result and load 
 * 'ping_server_interupt' on the server.
 */

#include "rf.h"

void rf_setup(){
  Serial.begin(9600);
  /*
   * Setup pins / SPI.
   */
   
  /* To change CE / CSN Pins:
   * 
   * Mirf.csnPin = 9;
   * Mirf.cePin = 7;
   */
  Mirf.cePin = A0;
  Mirf.csnPin = A1;

  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  
  /*
   * Configure reciving address.
   */
   
  Mirf.setRADDR((byte *)"clie1");
  
  /*
   * Set the payload length to sizeof(unsigned long) the
   * return type of millis().
   *
   * NB: payload on client and server must be the same.
   */
   
  Mirf.payload = sizeof(uint16_t);
  
  /*
   * Write channel and payload config then power up reciver.
   */
   
  /*
   * To change channel:
   * 
   * Mirf.channel = 10;
   *
   * NB: Make sure channel is legal in your area.
   */
   
  Mirf.config();
}

ISR(SIG_OUTPUT_COMPARE0){
  //ping on OC0
  
  Mirf.setTADDR((byte *)"clie1");
  
  Mirf.send((byte[2])ID);
  Lights::set(0,0x10,0xFF,0x50);
  while(Mirf.isSending()){
  }
  Lights::set(0,0x0,0x00,0x00);
} 
