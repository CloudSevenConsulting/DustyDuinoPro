
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
 * @var dn_uart_varts_t:: np_rts
 *      Pin value tracker for UART-NP RTS
 * @var dn_uart_varts_t:: np_cts
 *      Pin value tracker for UART-NP cTS
 * @var dn_uart_varts_t:: pn_rts
 *      Pin value tracker for UART-PN RTS
 * @var dn_uart_varts_t:: pn_cts
 *      Pin value tracker for UART-PN CTS
 */
typedef struct {
	dn_uart_rxByte_cbt	ipmt_uart_rxByte_cb;
	int np_rts;
	int np_cts;
	int pn_rts;
	int pn_cts;
	uint8_t bufc;
} dn_uart_vars_t;

extern dn_uart_vars_t dn_uart_vars;

#endif