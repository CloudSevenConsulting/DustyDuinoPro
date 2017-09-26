/*
 * test_dnJoin.cpp
 *
 * Created: 2017-09-26 22:42:50
 *  Author: kjph
 */ 

extern "C" {
	#include "../sm_qsl/dn_qsl_api.h"
};
#include "TestDnJoin.h"
#include "Arduino.h"
#include "../globals.h"

TestDnJoin::TestDnJoin(void)
{
    dn_qsl_init();
};

void TestDnJoin::run()
{
    if(dn_qsl_isConnected())
    {
        t_pass();
    }
    else
    {
        Board.setLed(true);
        if (dn_qsl_connect(NETID, JOINKEY, SRC_PORT, BANDWIDTH_MS))
        {
        } else
        {
            Board.setLed(false);
            t_fail();
        }
    }
}