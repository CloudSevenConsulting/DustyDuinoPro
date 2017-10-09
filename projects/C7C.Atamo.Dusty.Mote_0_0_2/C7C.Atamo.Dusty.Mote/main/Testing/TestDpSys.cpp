/*
 * DpUart.cpp
 *
 * Created: 2017-10-02 00:28:09
 *  Author: kjph
 */ 

#include "TestDpSys.h"
#include "Arduino.h"
#include "../globals.h"

TestDpSys::TestDpSys(void)
{
    Board.setLed(false);
};

void TestDpSys::run(void)
{
    TU_SH_DpSys_FlashBlink_Op();
}

void TestDpSys::TU_SH_DpSys_FlashBlink_Op(void)
{
    while(1)
    {
        blink();
    }

    t_pass();
}