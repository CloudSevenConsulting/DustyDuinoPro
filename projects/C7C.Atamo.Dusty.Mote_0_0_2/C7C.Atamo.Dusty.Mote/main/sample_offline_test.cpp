/* sample_offline_test.cpp
 * Code for running sample* unit tests
 * 
 * Compile with:
 * g++ -o test .\sample_offline_test.cpp .\Testing\TestDpSampleTime.cpp .\Testing\TestDpSampleDiagnostic.cpp .\Testing\TestDpSampleSensor.cpp .\Testing\TestDpSample.cpp .\sample\sample.cpp .\sample\frame.cpp .\sample\sensor.cpp .\sm_qsl\dn_time.c .\Testing\TestCase.cpp
 * 
 * Run as:
 * .\test.exe
 * 
 */


#include "globals.h"

#include "Testing/TestDpSampleTime.h"
#include "Testing/TestDpSampleDiagnostic.h"
#include "Testing/TestDpSampleSensor.h"
#include "Testing/TestDpSample.h"

sys_state SystemState;
dp_payload_t dp_payload;

int main (int argv, char *argc[])
{
    TestDpSampleTime test_dp_sample_time;
    test_dp_sample_time.run();  

    TestDpSampleDiagnostic test_dp_sample_diagnostic;
    test_dp_sample_diagnostic.run();

    TestDpSampleSensor test_dp_sample_sensor;
    test_dp_sample_sensor.run();

    TestDpSample test_dp_sample;
    test_dp_sample.run();

    return 0;
}