/*============================================================================*/
/*!
 * @file port.cpp
 *
 * @brief Port (pin) setup for duinoPro
 *
 *
 * @date 2017/10/01
 * @author Jamie K. Phan
 *
 */
/*============================================================================*/

#include "port.h"
#include <Arduino.h>

void port_init(void)
{
    pinMode(DP_PORT__UART_NP_RTS, INPUT);
    pinMode(DP_PORT__UART_NP_CTS, OUTPUT);
}

void pin_set_mode(int pin, int mode)
{
    pinMode(pin, mode);
}

void pin_set_digital(int pin, int value)
{
    digitalWrite(pin, value);
}