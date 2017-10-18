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

#ifndef USART_MODE4_FLOW_H_
#define USART_MODE4_FLOW_H_

#define USART__DIRECTION_PN 1
#define USART__DIRECTION_NP 0
#define USART__FLOWCTRL_ASSERT 1
#define USART__FLOWCTRL_DEASSERT 0
//=====================================
/** @brief Implements the necessary flow control for the USART
 *
 * @param direction The direction of the flow (DP to DN) or (DN to DP). Ensure
 *        Pre-processor macros are used to ensure portability
 * @param value The flow to be handled; either (assert) or (deassert)
 *
 * @return 0 on success, 1 on failure
 */
 void usart_mode4_flow(int, int);

 //=====================================
/** @brief Updates the port values based on the uart_vars. This is to ensure 
 *         resources are shared correctly.
 *
 */
 void update_port_usart(void);

#endif