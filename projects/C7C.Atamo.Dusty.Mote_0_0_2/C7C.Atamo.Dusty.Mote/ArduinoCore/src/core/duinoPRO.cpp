
#include <duinoPRO.h>
// #include <Pin.h>
#include <pins_arduino.h>
#include <Arduino.h>

duinoPRO::duinoPRO(void)
{
	pinMode(VBAT_SENSE_EN_PIN, OUTPUT);
	digitalWrite(VBAT_SENSE_EN_PIN, LOW);
	
	pinMode(BASEBOARD_LED, OUTPUT);
	digitalWrite(BASEBOARD_LED, LOW);
	
	pinMode(UART_SELECT_PIN, OUTPUT);
	digitalWrite(UART_SELECT_PIN, HIGH);
};

void duinoPRO::enableVbatSense(bool enable)
{
	digitalWrite(VBAT_SENSE_EN_PIN, enable);
}

float duinoPRO::getVbat()
{
    int vbatRaw = analogRead(VBAT);
    return (vbatRaw * (3.3/1023.0) * (10750.0/750.0));
}

void duinoPRO::setLed(bool on)
{
    digitalWrite(BASEBOARD_LED, on);
}

void duinoPRO::uartUsbMode()
{
	digitalWrite(UART_SELECT_PIN, HIGH);
}

void duinoPRO::uartModule7Mode()
{
	digitalWrite(UART_SELECT_PIN, LOW);
}




