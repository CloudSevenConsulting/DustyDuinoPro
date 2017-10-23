/*
 * TestDpSampleTime.cpp
 *
 * Created: 19/10/2017 9:01:11 AM
 *  Author: Aaron Hurst
 */ 

#include <stdint.h>
#include <stddef.h>

#include "TestDpSampleTime.h"
#include "../globals.h"
#include "../sample/sample.h"

TestDpSampleTime::TestDpSampleTime(void)
{
};

void TestDpSampleTime::run(void)
{
	TU_SH_DpSampleTime_op();
}

void TestDpSampleTime::TU_SH_DpSampleTime_op(void)
{
	bool passed = true;
	dp_payload_flush();

	/*Run test case*/
	sample_time();

	/*Examine outputs*/
	if (dp_payload._ready_send != 0 || dp_payload._payload_ptr != 5) {
		t_fail();
	} else if (dp_payload.payload[0] != 0b01011111) {
		t_fail();
	} else if (dp_payload.payload[1] != 0b00101010) {
		t_fail();
	} else if (dp_payload.payload[2] != 0b01010011) {
		t_fail();
	} else if (dp_payload.payload[3] != 0b00000001) {
		t_fail();
	} else if (dp_payload.payload[4] != 0b10110111) {
		t_fail();
	}
	
	/*No failed tests - SUCCESS*/
	t_pass();
}
