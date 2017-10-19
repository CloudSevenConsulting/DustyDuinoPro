/*
 * tester.cpp
 *
 * Created: 2017-09-20 18:49:43
 *  Author: kjph
 */ 

#include "TestCase.h"
/*COMMENTED OUT FOR TESTING
#include "Arduino.h"
*/
#include "../globals.h"

TestCase::TestCase(void)
{
	tctrl_stop_on_success = true;
};

void TestCase::blink()
{
	/*COMMENTED OUT FOR TESTING
	delay(500);
	Board.setLed(false);
	delay(500);
	Board.setLed(true);
	*/
}

void TestCase::run()
{
}

void TestCase::t_fail()
{
	while(1)
	{
		blink();
	}
}

void TestCase::t_pass()
{
	if (tctrl_stop_on_success)
	{
		while(1)
		{
			blink();
		}
	}
}