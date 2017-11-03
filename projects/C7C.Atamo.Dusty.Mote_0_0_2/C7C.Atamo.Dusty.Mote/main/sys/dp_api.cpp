/*============================================================================*/
/*!
 * @file dp_api.cpp
 *
 * @brief DuinoPro API for C functionality
 *
 * @date 2017/10/15
 * @author Jamie K. Phan
 *
 */
/*============================================================================*/

#include "dp_api.h"
#include <duinoPRO.h>
#include "../globals.h"

extern "C" void dp_board_set_led(uint8_t status)
{
    if (status)
    {
        Board.setLed(true);
    }
    else
    {
        Board.setLed(false);
    }
}