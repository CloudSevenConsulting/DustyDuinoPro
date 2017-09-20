
// #include <Wire.h>
// #include <../../libraries/Wire/Wire.h>
// #include <../../Wire.h>
#include <Pin.h>
#include <Arduino.h>
#include <pins_arduino.h>


Pin::Pin()
{
	_id = NOT_A_PIN;
};

Pin::Pin(uint8_t id)
{
	_id = id;
};

Pin::Pin(uint8_t mod, uint8_t pin)
{
	_id = moduleSignalToPin(mod, pin);
};

void Pin::mode(uint8_t value)
{
	::pinMode(_id, value);
 };

void Pin::write(bool value)
{
	::digitalWrite(_id, value);
};

bool Pin::read(void)
{
	return ::digitalRead(_id);
};

