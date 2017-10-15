/*============================================================================*/
/*!
 * @file usart_flow.h
 *
 * @brief Handles flow control for USART
 *
 * @date 2017/10/15
 * @author Jamie K. Phan
 *
 */
/*============================================================================*/

#ifndef USART_MODE4_FLOW_H`_
#define USART_MODE4_FLOW_H`_

#define USART__FLOWCTRL_DP_TO_DN 1
#define USART__FLOWCTRL_DN_TO_DP 0
#define USART__FLOWCTRL_RTS 1
#define USART__FLOWCTRL_CTS 0

//=====================================
/** @brief Implements the necessary flow control for the USART
 *
 * @param direction The direction of the flow (DP to DN) or (DN to DP). Ensure
 *        Pre-processor macros are used to ensure portability
 * @param flow The flow to be handled; either (RTS) or (CTS)
 *
 * @return 0 on success, 1 on failure
 */
 void usart_mode4_flow(int direction, int flow);

#endif