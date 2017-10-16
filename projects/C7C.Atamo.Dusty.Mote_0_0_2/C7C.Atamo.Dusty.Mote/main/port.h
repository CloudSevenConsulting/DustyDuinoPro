/*
 * port.h
 *
 * Created: 2017-10-16 17:32:54
 *  Author: kjph
 */ 


#ifndef PORT_H_
#define PORT_H_

#include <Arduino.h>

// DuinoPro to Arduino
#define DP_PORT__M1P1 9
#define DP_PORT__M2P1 5
#define DP_PORT__M3P1 4
#define DP_PORT__M4P1 3
#define DP_PORT__M5P1 A2
#define DP_PORT__M6P1 A1
#define DP_PORT__M7P1 7

//Used pins
#define DP_PORT__UART_NP_RTS DP_PORT__M7P1
#define DP_PORT__UART_NP_CTS DP_PORT__M6P1

//=====================================
/*! @brief Initialises all pins
*
*/
void port_init(void);

//=====================================
/*! @brief Wrapper for arduino pinMode
*
* @param pin the Arduino pin reference
* @param mode Output or Input
*/
void pin_set_mode(int, int);

//=====================================
/*! @brief Wrapper for arduino DigialWrite
*
* @param pin the Arduion pin reference
* @param value High or Low
*/
void pin_set_digital(int, int);


#endif /* PORT_H_ */