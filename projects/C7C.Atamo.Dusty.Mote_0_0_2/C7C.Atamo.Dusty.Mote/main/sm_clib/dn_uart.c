
#include "dn_uart.h"

#include "../usart/ISerial.h"
#include "../usart/usart_vars.h"

//========== 
/*! Initialise the UART peripheral on the Microcontroller 
 *
 * @param rxByte_cb (dn_uart_rxByte_cbt): TODO: What is this?
 */
void dn_uart_init(dn_uart_rxByte_cbt rxByte_cb)
{

    // Store RX callback function
    dn_uart_vars.ipmt_uart_rxByte_cb = rxByte_cb;
    
    /*This is done in setup*/
    /*TODO: this*/
    dp_usart_init(USART_AC__BAUD_RATE);
}

//========== 
/** @brief 
 *
 * 
 *
 * @param parameter
 *
 * @return 0 on success, 1 on failure
 */
void dn_uart_txByte(uint8_t byte)
{
    dp_usart_write(byte);
}

//========== 
/** @brief 
 *
 * 
 *
 * @param parameter
 *
 * @return 0 on success, 1 on failure
 */
void dn_uart_txFlush()
{
    dp_usart_flush();
}