
#ifndef USART_VARS_H
#define USART_VARS_H

// Timing

#define USART_AC__BAUD_RATE 9600
#define USART_AC__NP_N_BIT_END_TX_RTS_CTS 2

typedef void (*dn_uart_rxByte_cbt)(uint8_t byte);

/*!
 * @struct dn_uart_vars_t
 * 
 * @var dn_uart_varts_t:: impt_uart_rxByte_cb
 *      The callback function in ipmt that handles recieved bytes.
 *      I.e. all rx'd bytes need to be sent to this callback
 */
typedef struct {
	dn_uart_rxByte_cbt	ipmt_uart_rxByte_cb;
} dn_uart_vars_t;

extern dn_uart_vars_t dn_uart_vars;

#endif