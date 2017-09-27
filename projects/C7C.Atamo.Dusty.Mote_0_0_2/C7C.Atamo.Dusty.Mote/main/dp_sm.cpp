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
#include "dp_conf.h"
 
sys_state SystemState;
 
void dp_state_init(void)
{
    memset(&SystemState, 0, sizeof(SystemState));
    SystemState._conf = sys_conf;
    SystemState._sys_ready_flag = DP_SYS__SYS_READY;
}

void dp_is_sys_ready(void)
{
    return SystemState._sys_ready_flag;
}

void dp_sleep(uint32_t milliseconds)
{

    //TODO: verify this timeout routine

    uint32_t waited = 0;
    uint32_t max_wait = dp_conf_param_get_cur(LUT_IDX__SLEEP_GUARD_TIMEOUT);

    /*Sleep Guard*/
    while(SystemState._sys_sleepguard > 0)
    {
        waited += 10;
        delay(10);
        if (waited > max_wait)
        {
            SystemState._sys_sleepguard = 0;
            break;
        }
    }

    SystemState._sys_ready_flag = DP_SYS__SYS_NOT_READY;
    delay(milliseconds);//TODO: make a proper sleep function
}

int dp_wake(void)
{
    //TODO; this

    SystemState._sys_ready_flag = DP_SYS__SYS_READY;
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