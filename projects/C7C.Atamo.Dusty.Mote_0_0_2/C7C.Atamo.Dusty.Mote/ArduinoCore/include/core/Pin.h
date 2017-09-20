#ifndef PIN_H
#define PIN_H

#include <Arduino.h>

/**
 * The Pin class encapsulates everything you can do with a pin.
 */
class Pin {
    private:
        uint8_t _id;

	public:
	    // Set pinMode values from constants in Arduino.h, to ensure consistency.
        enum pinMode {
            PIN_INPUT = INPUT,
			PIN_OUTPUT = OUTPUT,
            PIN_INPUT_PULL_UP = INPUT_PULLUP,
        };
		
		
		/**
		 * Constructor that makes a NOT_A_PIN.
		 */
		Pin();
		/**
		 * Constructor that takes the wiring_digital 'pin' id as an argument.
		 */
		Pin(uint8_t id);
		
		/**
		 * Constructor that takes the module position number and pin on module as arguments.
		 */
		Pin(uint8_t mod, uint8_t pin);

		/**
         * Set whether the pin is going to be used for input
         * or out, as well setting pull ups.
         */
        void mode(uint8_t value);

        /**
         * For a pin that is has the mode OUTPUT, change its
         * value.
         */
        void write(bool value);

        /**
         * Read back the value of a pin. Works for any mode.
         */
        bool read(void);
};


#endif /* PIN_H */
