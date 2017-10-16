/*============================================================================*/
/*!
 * @file port.cpp
 *
 * @brief Port (pin) setup for duinoPro
 *
 *
 * @date 2017/10/01
 * @author Jamie K. Phan
 *
 */
/*============================================================================*/

#include "port.h"
#include <duinoPro.h>
#include <Module.h>
#include <Pin.h>

//Global externally
Module Board_Mod_Usart(DP_PORT__MODULE_USART);

//Global locally
Pin rts(DP_PORT__MODULE_USART, DP_PORT__USART_RTS_BMASK);

void port_init(void)
{
    rts.mode(OUTPUT);
}

void port_rts_set(int value)
{

    if (value)
    {
        rts.write(HIGH);
    }
    else
    {
        rts.write(LOW);
    }
}