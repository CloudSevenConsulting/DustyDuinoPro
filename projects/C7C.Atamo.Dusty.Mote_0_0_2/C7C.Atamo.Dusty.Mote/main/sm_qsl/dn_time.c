/*
 * dn_time.c
 *
 * Created: 2017-09-26 02:11:13
 *  Author: kjph
 */

#include <stdint.h>
#include "dn_time.h"

/* COMMENTED OUT FOR TESTING
#include "../time/ITime.h"
*/

//typedef unsigned long int uint32_t;//TODO: fix this hack lol

uint32_t dn_time_ms(void)
{
    //TODO: code this properly to get network time from Dusty (see SMIP serial API guide 5.6.20 &/or 6.4)
    //return dp_time_now();
    return 0x2A5301B7;   // semi-random test output
}

/* COMMENTED OUT FOR TESTING
void dn_sleep_ms(uint32_t milliseconds)
{
    dp_delay(milliseconds);//TODO: replace this with a sleep func
}
*/