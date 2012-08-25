// should pulse the IR LED at roughly the correct freqeuncy to trigger the 
// sensor

#include "Arduino.h"

const int irout_pin = 3;
const int led_pin   = 10;
// 1/38k = 2.631578947e-05 s ~= 26.3 micro-seconds
const int carrier_signal = 26;

void setup() {
	pinMode(irout_pin, OUTPUT);
	pinMode(led_pin,   OUTPUT);
}



void loop() {
	while(true) {
		digitalWrite(irout_pin, HIGH);
		digitalWrite(led_pin,   HIGH);
		delayMicroseconds(carrier_signal/2);
		digitalWrite(irout_pin, LOW);
		digitalWrite(led_pin,   LOW);
		delayMicroseconds(carrier_signal/2);
	}
}
