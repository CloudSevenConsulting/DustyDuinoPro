/*
 * dp_sm.c
 *
 * Created: 2017-09-27 18:08:06
 *  Author: kjph
 */

#include <stdio.h>
#include <string.h>
#include <Arduino.h>

#include "dp_sm.h"
#include "globals.h"
 
sys_state SystemState;
 
void dp_state_init(void)
{
    memset(&SystemState, 0, sizeof(SystemState));
    SystemState._conf = sys_conf;
}

void dp_sleep(uint32_t milliseconds)
{

    /*Sleep Guard*/
    while(SystemState._sys_sleepguard > 0)
    {
        //Wait
        //Maximum wait time (to prevent lockup)
        //TODO
    }

    delay(milliseconds);//TODO: make a proper sleep function
}

int dp_wake(void)
{
    //TODO; this

    return 1;
}

void dp_sleepguard_set(void)
{
    SystemState._sys_sleepguard++;
}

void dp_sleepguard_free(void)
{
    if (SystemState._sys_sleepguard > 0)
    {
        SystemState._sys_sleepguard--;
    }
}