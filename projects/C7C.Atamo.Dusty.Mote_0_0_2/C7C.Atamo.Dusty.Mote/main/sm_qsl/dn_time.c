/*
 * dn_time.c
 *
 * Created: 2017-09-26 02:11:13
 *  Author: kjph
 */

#include <stdint.h>
#include "dn_time.h"

#include "../time/ITime.h"

uint32_t dn_time_ms(void)
{
    //TODO: code this properly to get network time from Dusty
    //see SMIP serial API guide sections 5.6.20 &/or 6.4
    //return dp_time_now();
    return 0x2A5301B7;   // semi-random test output
}

void dn_sleep_ms(uint32_t milliseconds)
{
    dp_delay(milliseconds);//TODO: replace this with a sleep func
}