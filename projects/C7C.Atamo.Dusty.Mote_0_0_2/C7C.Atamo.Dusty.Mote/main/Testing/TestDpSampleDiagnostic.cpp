/*
 * TestDpSampleDiagnostic.cpp
 *
 * Created: 19/10/2017 10:02:49 AM
 *  Author: Aaron Hurst
 */ 

#include <stdint.h>
#include <stddef.h>

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
    dp_payload_flush();
    uint8_t ret = -1;

	/*Run test case*/
	ret = sample_diagnostic();

    /*Examine outputs*/
    if (ret != RETURN_SUCCESS || dp_payload._ready_send != 0 || dp_payload._payload_ptr != 5) {
        t_fail();        
    } else if (dp_payload.payload[0] != 0b01011110) {
        t_fail();
    } else if (dp_payload.payload[1] != 0b01000011) {
        t_fail();
    } else if (dp_payload.payload[2] != 0b10111101) {
        t_fail();
    } else if (dp_payload.payload[3] != 0b01000010) {
        t_fail();
    } else if (dp_payload.payload[4] != 0b10011100) {
        t_fail();
    }
    
    //*No failed tests - SUCCESS*/
    t_pass();
}
