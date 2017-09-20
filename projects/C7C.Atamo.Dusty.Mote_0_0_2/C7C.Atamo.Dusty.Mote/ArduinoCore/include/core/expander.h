#ifndef Expander_h
#define Expander_h

#include "Arduino.h"

#ifdef __cplusplus
extern "C"{
#endif

void expanderPinMode(uint8_t pin, uint8_t mode);
void expanderWrite(uint8_t pin, uint8_t val);
int expanderRead(uint8_t pin);

#ifdef __cplusplus
} // extern "C"
#endif

#endif