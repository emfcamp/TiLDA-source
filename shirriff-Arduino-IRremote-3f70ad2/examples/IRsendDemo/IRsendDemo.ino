/*
* IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
* An IR LED must be connected to Arduino PWM pin 3.
* Version 0.1 July, 2009
* Copyright 2009 Ken Shirriff
* http://arcfn.com
*/

#include <IRremote.h>

// TODO figure out where the pin is defined (it's correct though)
IRsend irsend;

void setup()
{
	Serial.begin(9600);
}

void loop() {
	digitalWrite(4,HIGH);
	digitalWrite(13, HIGH); 
	while (true) {
		Serial.println("Sending");
		for (int i = 0; i < 3; i++) {
			irsend.sendSony(0xa90, 12); // Sony TV power code
			delay(40);
		}
		Serial.println("Sent");
	}
}
