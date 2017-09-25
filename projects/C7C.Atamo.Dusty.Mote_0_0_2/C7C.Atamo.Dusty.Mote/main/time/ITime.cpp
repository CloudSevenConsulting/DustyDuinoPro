/*
 * ITime.cpp
 *
 * Created: 2017-09-26 02:14:38
 *  Author: kjph
 */ 

#include <Arduino.h>

extern "C" void dp_delay(uint32_t milliseconds)
{
    delay(milliseconds);
}

extern "C" unsigned long dp_time_now(void)
{
    return millis();
}