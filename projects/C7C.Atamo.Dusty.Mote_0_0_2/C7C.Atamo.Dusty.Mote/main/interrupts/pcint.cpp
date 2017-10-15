#include "../globals.h"
#include <duinoPRO.h>
#include <Arduino.h>

void pciSetup(int pin)
{
    *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));  // enable pin
    PCIFR  |= bit (digitalPinToPCICRbit(pin)); // clear any outstanding interrupt
    PCICR  |= bit (digitalPinToPCICRbit(pin)); // enable interrupt for the group
}
 
// Use one Routine to handle each group
 
ISR (PCINT0_vect) // handle pin change interrupt for D8 to D13 here
 {    
 }
 
ISR (PCINT1_vect) // handle pin change interrupt for A0 to A5 here
 {
 }  
 
ISR (PCINT2_vect) // handle pin change interrupt for D0 to D7 here
 {
     Board.setLed(true);
 }  