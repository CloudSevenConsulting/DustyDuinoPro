#ifndef MODULE_H
#define MODULE_H

#include <Pin.h>

#define PINS_PER_MODULE 6
 
class Module {
    private:
	    int _id;
		Pin pinMap[PINS_PER_MODULE];
		Pin _spiSelect;

    protected:
	int id();
	
    public:
	// static Pin *pinMap[NUM_MODULES+1][PINS_PER_MODULE+1]; 
	// static Pin *spiSelectMap[NUM_MODULES+1];
	
	Module(int id);
	
	
	// void initialisePinMap();
	/**
	 * Provides access to the Pins.
	*/
	Pin& pin(uint8_t pin);
	
	// Gets the digital pin number, for the relevant module pin
	uint8_t digitalPin(uint8_t modulePin);
	
	Pin& spiSelect();

	/* TODO: SPI, USART, Interrupts */
};

#endif /* MODULE_H */