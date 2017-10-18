/*
 * port.h
 *
 * Created: 2017-10-16 17:32:54
 *  Author: kjph
 */ 


#ifndef PORT_H_
#define PORT_H_

#include <Arduino.h>

/*******************************************************************************
 * Pin Mappins
 ******************************************************************************/
// Direct-Pins
#define DP_PORT__M1P1 9     /// PB1 (PCTIN1/OC1A)
#define DP_PORT__M2P1 5     /// PD5 (PCINT21/OC0B/T1)
#define DP_PORT__M3P1 4     /// PD4 (PCINT20/XCK/T0)
#define DP_PORT__M4P1 3     /// PD3 (PCINT19/OC2B/INT1)
#define DP_PORT__M5P1 A2    /// PC2 (ADC2/PCINT10)
#define DP_PORT__M6P1 A1    /// PC1 (ADC1/PCINT9)
#define DP_PORT__M7P1 7     /// PD7 (PCINT23/AIN1)

/*******************************************************************************
 * USART
 ******************************************************************************/
/**
 *
 * Dusty-to-DuinoPro (NP)
 * ____           ______________________
 *     |         |
 * RTS | ------> | DP_PORT__UART_NP_RTS = M7P1
 * TX  | ------> | RX                   = M7P4
 * CTS | <------ | DP_PORT__UART_NP_CTS = M6P1
 * ____|         |_______________________
 * 
 */
#define DP_PORT__UART_NP_RTS DP_PORT__M7P1
#define DP_PORT__UART_NP_CTS DP_PORT__M6P1

/**
 *
 * DuinoPro-to-Dusty (PN)
 *        _______________________           ______
 *                               |         |
 * M4P1   = DP_PORT__UART_PN_RTS | ------> | RTS
 * M7P5   =                   TX | ------> | RX
 * M5P1   = DP_PORT__UART_PN_CTS | <------ | CTS 
 *        _______________________|         |______
 * 
 */
#define DP_PORT__UART_PN_RTS DP_PORT__M5P1
#define DP_PORT__UART_PN_CTS DP_PORT__M1P1

/*******************************************************************************
 * Interrupts
 ******************************************************************************/

//=====================================
/*! @brief Pin Change Interrupt 1
*
* PCINT 8 - 13
*
* This interrupt is defined in usart_flow
*
*/
//ISR(PCINT1_vect);

//=====================================
/*! @brief Pin Change Interrupt 1
*
* PCINT 8 - 13
*
* This interrupt is defined in usart_flow
*
*/
//ISR(PCINT1_vect);

//=====================================
/*! @brief Pin Change Interrupt 2
*
* PCINT 16- 23
*
* This interrupt is defined in usart_flow
*
*/
ISR(PCTIN2_vect);

//=====================================
/*! @brief Sets up PCINT (Pin Change 
*          Interrupts)
*
* @param pin the Arduino pin reference
*
*/
void interrupt_pci_init(int pin);

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

//=====================================
/*! @brief Wrapper for arduino DigitalRead
*
* @param pin the Arduion pin reference
*
* @return digital value of pin
*/
int pin_read(int pin);


#endif /* PORT_H_ */