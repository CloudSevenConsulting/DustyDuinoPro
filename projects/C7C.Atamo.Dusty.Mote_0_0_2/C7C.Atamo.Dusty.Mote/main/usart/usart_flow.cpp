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

dn_uart_vars_t dn_uart_vars;

int usart_cts_status(void)
{
    return dn_uart_vars.pn_cts;
}

void usart_mode4_flow(int direction, int value)
{

    /**
     * Note that this function is for the DUINOPRO (P)
     * It only exposes control over that in which P has control over
     * That is:
     *   - For NP: CTS
     *   - For PN: RTS
     */

    switch (direction)
    {
        // Dusty (N) to DuinoPro (P) (We only have control of NP_CTS here)
        case USART__DIRECTION_NP:
            if (value == USART__FLOWCTRL_ASSERT)
            {
                //dn_uart_vars.pn_rts = 1;//Prevent sending while recieving
                dn_uart_vars.np_cts = 0;
            }
            else
            {
                delay(USART_AC__NP_N_BIT_END_TX_RTS_CTS);
                dn_uart_vars.np_cts = 1;
            }
            break;
         // DuinoPro (P) to Dusty (N) (We only have control of PN_RTS here)
        case USART__DIRECTION_PN:
            if (value == USART__FLOWCTRL_ASSERT)
            {
                //dn_uart_vars.np_cts = 1;//Prevent reading whilst sending
                dn_uart_vars.pn_rts = 0;
            }
            else
            {
                dn_uart_vars.pn_rts = 1;
            }
            break;
    }

    update_port_usart();
}

void update_port_usart(void)
{
    pin_set_digital(DP_PORT__UART_NP_CTS, dn_uart_vars.np_cts);
    pin_set_digital(DP_PORT__UART_PN_RTS, dn_uart_vars.pn_rts);

    dn_uart_vars.pn_cts = pin_read(DP_PORT__UART_PN_CTS);
    dn_uart_vars.np_rts = pin_read(DP_PORT__UART_NP_RTS);
}

ISR (PCINT2_vect)
{

    update_port_usart();

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