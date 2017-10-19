/*
 * TestDpSampleTime.cpp
 *
 * Created: 19/10/2017 9:01:11 AM
 *  Author: Aaron Hurst
 */ 

#include <stdint.h>
#include <stddef.h>

/*OFFLINE TESTING ONLY*/
#include <stdio.h>
#include <stdint.h>
#include <iostream>
/*END OFFLINE TESTING ONLY*/

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
		printf("sample_time: TEST FAILED - BAU\n");
		passed = false;
	} else if (dp_payload.payload[0] != 0b01011111) {
		printf("sample_time: TEST FAILED - BAU\n");
		passed = false;
	} else if (dp_payload.payload[1] != 0b00101010) {
		printf("sample_time: TEST FAILED - BAU\n");
		passed = false;
	} else if (dp_payload.payload[2] != 0b01010011) {
		printf("sample_time: TEST FAILED - BAU\n");
		passed = false;
	} else if (dp_payload.payload[3] != 0b00000001) {
		printf("sample_time: TEST FAILED - BAU\n");
		passed = false;
	} else if (dp_payload.payload[4] != 0b10110111) {
		printf("sample_time: TEST FAILED - BAU\n");
		passed = false;
	}
	
	// Code available for providing console output in offline testing
	// for (int byte = 0; byte < 5; byte++) {
	// 	for (int i = 7; i >= 0; i--) {
	// 		std::cout << ((dp_payload.payload[byte] >> i) & 1);
	// 	}
	// 	printf(" ");
	// }
	// printf("\n");
	// printf("_ready_send: %i\n", dp_payload._ready_send);
	// printf("_payload_ptr: %i\n", dp_payload._payload_ptr);

	/*No failed tests - SUCCESS*/
	if (passed == true) {
		printf("sample_time:        TEST PASSED - BAU\n");
	}
}
