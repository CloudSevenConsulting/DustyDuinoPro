/*============================================================================*/
/*!
 * @file usart_flow.cpp
 *
 * @brief Handles flow control for USART
 *
 * @date 2017/10/15
 * @author Jamie K. Phan
 *
 */
/*============================================================================*/

#include "usart_flow.h"
#include "../port.h"

extern "C" {
    #include "../usart/usart_vars.h"
}

void usart_mode4_flow(int direction, int value)
{
    switch (direction)
    {
        // Dusty (N) to DuinoPro (P)
        case USART__DIRECTION_NP:
            if (value == USART__FLOWCTRL_ASSERT)
            {
                pin_set_digital(DP_PORT__UART_NP_CTS, 0);
            }
            else
            {
                delay(2);
                pin_set_digital(DP_PORT__UART_NP_CTS, 1);
            }
        case USART__DIRECTION_PN:
            //TODO: This
            break;
    }
}

ISR (PCINT2_vect) // handle pin change interrupt for D0 to D7 here
{
    if(pin_read(DP_PORT__UART_NP_RTS))
    {
        usart_mode4_flow(USART__DIRECTION_NP, USART__FLOWCTRL_DEASSERT);
    }
    else
    {
        usart_mode4_flow(USART__DIRECTION_NP, USART__FLOWCTRL_ASSERT);

        dn_uart_vars.ipmt_uart_rxByte_cb(Serial.read());
    }
}