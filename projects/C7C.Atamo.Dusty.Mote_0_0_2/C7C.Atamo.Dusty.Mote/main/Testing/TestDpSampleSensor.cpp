/*
 * TestDpSampleSensor.cpp
 *
 * Created: 19/10/2017 10:36:40 AM
 *  Author: Aaron Hurst
 */ 

#include <stdint.h>
#include <stddef.h>

/*OFFLINE TESTING ONLY*/
#include <stdio.h>
#include <stdint.h>
#include <iostream>
/*END OFFLINE TESTING ONLY*/

#include "TestDpSampleSensor.h"
#include "../globals.h"
#include "../sample/sample.h"
#include "../sample/sensor.h"

#define RETURN_SUCCESS 0

TestDpSampleSensor::TestDpSampleSensor(void)
{
};

void TestDpSampleSensor::run(void)
{
	TU_SH_DpSampleSensor_op();
}

void TestDpSampleSensor::TU_SH_DpSampleSensor_op(void)
{
    /*Variables*/
    bool passed = true;
    dp_payload_flush();
    uint8_t ret = -1;
    uint8_t tmp_sensor_n_outputs, tmp_sensor_type, tmp_sensor_status;

    /*Expected payload output*/
    uint8_t expected[13] = {0xC0, 0x01, 0x02, 0x50, 0x10, 0xFF, 0x00, 0x11, 0xDD, 0x00, 0x11, 0x05, 0x04};
    
    /*Save current settings*/
    tmp_sensor_n_outputs = SystemState._sensor_n_outputs;
    tmp_sensor_type = SystemState._sensor_type;
    tmp_sensor_status = SystemState._sensor_status;

    /*Apply test settings*/
	SystemState._sensor_n_outputs = 6;
	SystemState._sensor_type = DP_SENS__ACCEL_MAGNO;
	SystemState._sensor_status = 1;

	/*Run test case*/
    ret = sample_sensor();
    
    /*Examine outputs*/
    if (ret != RETURN_SUCCESS || dp_payload._ready_send != 0 || dp_payload._payload_ptr != 13) {
        printf("sample_sensor:      TEST FAILED - BAU 1\n");
        passed = false;
    }
    for (uint8_t i = 0; i < 13; i++) {
        if (dp_payload.payload[i] != expected[i]) {
            printf("sample_sensor:      TEST FAILED - BAU %d\n", i);
            printf("payload: %i, expected: %i\n", dp_payload.payload[i], expected[i]);
            passed = false;
            break;
        }
    }
    
    /*No failed tests - SUCCESS*/
    if (passed == true) {
        printf("sample_sensor:      TEST PASSED - BAU\n");
    }

    /*Code available for providing console output in offline testing*/
    // for (int byte = 0; byte < 13; byte++) {
    // 	for (int i = 7; i >= 0; i--) {
    // 		std::cout << ((dp_payload.payload[byte] >> i) & 1);
    // 	}
    // 	printf(" ");
    // }
    // printf("\n");
    // printf("return:       %i\n", ret);
    // printf("_ready_send:  %i\n", dp_payload._ready_send);
    // printf("_payload_ptr: %i\n", dp_payload._payload_ptr);


    /*Reinstate settings*/
    SystemState._sensor_n_outputs = tmp_sensor_n_outputs;
    SystemState._sensor_type = tmp_sensor_type;
    SystemState._sensor_status = tmp_sensor_status;
}
