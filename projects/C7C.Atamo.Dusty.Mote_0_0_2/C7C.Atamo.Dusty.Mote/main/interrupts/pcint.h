/*
 * int_pcint.h
 *
 * Created: 2017-10-16 01:55:45
 *  Author: kjph
 */ 


 #ifndef PCINT_H_
 #define PCINT_H_
 
 
 void pciSetup(int pin);
  
 // Use one Routine to handle each group
 ISR (PCINT0_vect);
 ISR (PCINT1_vect);
 ISR (PCINT2_vect);
 
 
 #endif /* INT_PCINT_H_ */