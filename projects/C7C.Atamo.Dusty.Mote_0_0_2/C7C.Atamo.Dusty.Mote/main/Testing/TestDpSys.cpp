/*
 * TestDpSys.cpp
 *
 * Created: 2017-09-26 22:42:50
 *  Author: kjph
 */ 

#include "TestDpSys.h"
#include "Arduino.h"
#include "../globals.h"

TestDpSys::TestDpSys(void)
{
    Board.setLed(false);
};

void TestDpSys::run()
{
    TU_SH_DPSys_FlashBlink_Op();
}

void TestDpSys::TU_SH_DPSys_FlashBlink_Op()
{
    while(1)
    {
        blink();
    }
}