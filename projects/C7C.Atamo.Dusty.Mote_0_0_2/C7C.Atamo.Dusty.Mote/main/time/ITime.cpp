/*
 * ITime.cpp
 *
 * Created: 2017-09-26 02:14:38
 *  Author: kjph
 */ 

#include <Arduino.h>
#include <stdint.h>

extern "C" void dp_delay(uint32_t milliseconds)
{
    delay(milliseconds);
}

extern "C" uint32_t dp_time_now(void)
{
    //For UART time stamps (internal)
    //This will use internal RTC
    return millis();
}

uint32_t get_dn_time(void)
{
    //TODO: strobe the DN to get time
    return millis();
}

uint32_t time_next_sample(void)
{
    //TODO: determine next timestamp
    return millis();
}

uint32_t time_until_next_sample(uint32_t overhead)
{
    //Determine time to wait
    uint32_t time_now = get_dn_time();
    uint32_t next_sample = time_next_sample();
    return (next_sample - time_now - overhead);
}