
#include "../../libraries/Wire/Wire.h"
#include <Arduino.h>
#include <pins_arduino.h>

void initVariant()
{
	Serial.println("Welcome to initVariant");
	Wire.begin();
	pinMode(EXPANDER_RSTN, OUTPUT);
	digitalWrite(EXPANDER_RSTN, LOW);
	delay(10);
	digitalWrite(EXPANDER_RSTN, HIGH);
	delay(10);
}
