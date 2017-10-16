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

void interrupt_pci_init(int pin)
{
    *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));  // enable pin
    PCIFR  |= bit (digitalPinToPCICRbit(pin)); // clear any outstanding interrupt
    PCICR  |= bit (digitalPinToPCICRbit(pin)); // enable interrupt for the group
}

void port_init(void)
{
    pinMode(DP_PORT__UART_NP_RTS, INPUT);
    pinMode(DP_PORT__UART_NP_CTS, OUTPUT);

    interrupt_pci_init(DP_PORT__UART_NP_RTS);//Attach PCINT23 (M7 Interrupt)
}

void pin_set_mode(int pin, int mode)
{
    pinMode(pin, mode);
}

void pin_set_digital(int pin, int value)
{
    if (value)
    {
        digitalWrite(pin, HIGH);
    }
    else
    {
        digitalWrite(pin, LOW);
    }
}

int pin_read(int pin)
{
    return digitalRead(pin);
}