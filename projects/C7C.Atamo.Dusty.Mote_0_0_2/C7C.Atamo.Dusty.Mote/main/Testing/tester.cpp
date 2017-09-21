/*
 * tester.cpp
 *
 * Created: 2017-09-20 18:49:43
 *  Author: kjph
 */ 

#include "tester.h"
#include "Arduino.h"
#include "../globals.h"

tester::tester(void)
{
};

void tester::blink()
{
	delay(500);
	board.setLed(false);
	delay(500);
	board.setLed(true);
}

void tester::fail()
{
	while(1)
	{
		blink();
	}
}