/*
 * TestDpSampleDiagnostic.cpp
 *
 * Created: 19/10/2017 10:02:49 AM
 *  Author: Aaron Hurst
 */ 

#include <stdint.h>
#include <stddef.h>

/*OFFLINE TESTING ONLY*/
#include <stdio.h>
#include <stdint.h>
#include <iostream>
/*END OFFLINE TESTING ONLY*/

#include "TestDpSampleDiagnostic.h"
#include "../globals.h"
#include "../sample/sample.h"

#define RETURN_SUCCESS 0

TestDpSampleDiagnostic::TestDpSampleDiagnostic(void)
{
};

void TestDpSampleDiagnostic::run(void)
{
	TU_SH_DpSampleDiagnostic_op();
}

void TestDpSampleDiagnostic::TU_SH_DpSampleDiagnostic_op(void)
{
	bool passed = true;
    dp_payload_flush();
    uint8_t ret = -1;

	/*Run test case*/
	ret = sample_diagnostic();

    /*Examine outputs*/
    if (ret != RETURN_SUCCESS || dp_payload._ready_send != 0 || dp_payload._payload_ptr != 5) {
        printf("sample_diagnostic: TEST FAILED - BAU 1\n");
        passed = false;
    } else if (dp_payload.payload[0] != 0b01011110) {
        printf("sample_diagnostic: TEST FAILED - BAU 2\n");
        passed = false;
    } else if (dp_payload.payload[1] != 0b01000011) {
        printf("sample_diagnostic: TEST FAILED - BAU 3\n");
        passed = false;
    } else if (dp_payload.payload[2] != 0b10111101) {
        printf("sample_diagnostic: TEST FAILED - BAU 4\n");
        passed = false;
    } else if (dp_payload.payload[3] != 0b01000010) {
        printf("sample_diagnostic: TEST FAILED - BAU 5\n");
        passed = false;
    } else if (dp_payload.payload[4] != 0b10011100) {
        printf("sample_diagnostic: TEST FAILED - BAU 6\n");
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
        printf("sample_diagnostic:  TEST PASSED - BAU\n");
    }
}
