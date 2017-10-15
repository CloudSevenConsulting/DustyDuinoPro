/*============================================================================*/
/*!
 * @file ISerial.h
 *
 * @brief Serial interface between DuinoPro (DP) and Dusty (DN)
 *
 * This module provide interface functions to the DN that exposes the DP's UART
 * interface.
 *
 * This module only exists due to the lack of forward comptability between
 * .c and .cpp. Otherwise, it is best to have this file in sm_clib/dn_uart
 *
 * @date 2017/10/01
 * @author Jamie K. Phan
 *
 */
/*============================================================================*/

#ifndef ISERIAL_H_
#define ISERIAL_H_

//=====================================
/*! @brief Initialise the USART
*
*/
void dp_usart_init(int);

//=====================================
/*! @brief Terminates the USART operation
*
*/
void dp_usart_end(void);

//=====================================
/*! @brief Flush the USARt
*
*/
void dp_usart_flush(void);

//=====================================
/*! @brief Write the USART bus
*
* @param c byte to write to USART
*
* @return size of byte
*/
size_t dp_usart_write(uint8_t);

//=====================================
/*! @brief Reads from USART module
*
*/
int dp_usart_read(void);

//=====================================
/*! @brief Handles Mode 4 flow control
*
*/
void dp_usart_mode4_flow(int direction, int flow);


#endif /* ISERIAL_H_ */