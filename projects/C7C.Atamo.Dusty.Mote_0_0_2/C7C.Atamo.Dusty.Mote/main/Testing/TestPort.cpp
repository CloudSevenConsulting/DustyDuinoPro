/*
 * DpUart.cpp
 *
 * Created: 2017-10-02 00:28:09
 *  Author: kjph
 */ 

#include "TestPort.h"
#include "../port.h"

TestPort::TestPort(void)
{
    pin_set_mode(DP_PORT__M7P1, OUTPUT);
    pin_set_mode(DP_PORT__M6P1, OUTPUT);
};

void TestPort::run(void)
{
    pin_set_digital(DP_PORT__M7P1, HIGH);
    pin_set_digital(DP_PORT__M6P1, HIGH);
    delay(500);

    pin_set_digital(DP_PORT__M7P1, LOW);
    pin_set_digital(DP_PORT__M6P1, LOW);
    delay(500);
}

