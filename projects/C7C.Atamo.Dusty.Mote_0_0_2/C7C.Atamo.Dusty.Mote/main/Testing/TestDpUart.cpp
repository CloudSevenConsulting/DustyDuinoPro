/*
 * DpUart.cpp
 *
 * Created: 2017-10-02 00:28:09
 *  Author: kjph
 */ 

 extern "C" {
	#include "../sm_clib/dn_uart.h"
};
#include "TestDpUart.h"
#include "Arduino.h"
#include "../globals.h"

TestDpUart::TestDpUart(void)
{
    dn_uart_init(0);
    Board.setLed(false);
};

void TestDpUart::run(void)
{
    TU_SH_DpUart_external_op();
}

void TestDpUart::TU_SH_DpUart_external_op(void)
{
    while(1){

        //Blink just before sending data
        Board.setLed(true);
        delay(500);
        dn_uart_txByte(1);
        Board.setLed(false);
        delay(500);
    }
}