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
                dn_uart_vars.np_cts = 0;
            }
            else
            {
                delay(2);
                dn_uart_vars.np_cts = 1;
            }
        case USART__DIRECTION_PN:
            //TODO: This
            break;
    }

    update_port_usart();
}

void update_port_usart(void)
{
    pin_set_digital(DP_PORT__UART_NP_CTS, dn_uart_vars.np_cts);
}

ISR (PCINT2_vect)
{

    //TODO: Check if bus is already used with usart.vars

    dn_uart_vars.np_rts = pin_read(DP_PORT__UART_NP_RTS);
    if (dn_uart_vars.np_rts)
    {

        // If the pin change on RTS was a deassertion, then follow with a 
        // deassert
        usart_mode4_flow(USART__DIRECTION_NP, USART__FLOWCTRL_DEASSERT);
    }
    else
    {
        usart_mode4_flow(USART__DIRECTION_NP, USART__FLOWCTRL_ASSERT);

        dn_uart_vars.ipmt_uart_rxByte_cb(Serial.read());
    }

    update_port_usart();
}