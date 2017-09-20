#include <Module.h>
#include <pins_arduino.h>

Module::Module(int id) : _id(id)
{
	for (int i=0; i<PINS_PER_MODULE; i++)
	{
		pinMap[i] = Pin(_id, i+1);
	}
	_spiSelect = Pin(moduleSpiSelectToPin(_id));
};

int Module::id()
{
    return _id;
}

    /**
     * Provides access to the Pins.
     */

Pin& Module::pin(uint8_t pin)
{
    return (pinMap[pin-1]);
};

uint8_t Module::digitalPin(uint8_t modulePin)
{
    /*
    Serial.print("module::pin() module: ");
    Serial.print(_id);
    Serial.print(", module pin: ");
    Serial.print(modulePin);
    Serial.print(" => ");
    Serial.println(moduleSignalToPin(_id, modulePin));
    */
    return moduleSignalToPin(_id, modulePin);
}


Pin& Module::spiSelect()
{
    return _spiSelect;
};



    /* TODO: SPI; USART; Interrupts */


