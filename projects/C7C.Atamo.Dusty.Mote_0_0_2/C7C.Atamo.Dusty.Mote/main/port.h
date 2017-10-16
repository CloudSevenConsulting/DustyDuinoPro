/*
 * port.h
 *
 * Created: 2017-10-16 17:32:54
 *  Author: kjph
 */ 


#ifndef PORT_H_
#define PORT_H_

#define DP_PORT__MODULE_USART 7

#define DP_PORT__USART_INT_BMASK 1
#define DP_PORT__USART_CTS_BMASK 2
#define DP_PORT__USART_RTS_BMASK 3
#define DP_PORT__USART_RX_BMASK 4
#define DP_PORT__USART_TX_BMASK 5
#define DP_PORT__USART_SCK_BMASK 6

void port_init(void);
void port_rts_set(int value);


#endif /* PORT_H_ */