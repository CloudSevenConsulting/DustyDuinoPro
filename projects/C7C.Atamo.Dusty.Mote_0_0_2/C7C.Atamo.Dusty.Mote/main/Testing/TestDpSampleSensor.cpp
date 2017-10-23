/*
 * TestDpSampleSensor.cpp
 *
 * Created: 19/10/2017 10:36:40 AM
 *  Author: Aaron Hurst
 */ 

#include <stdint.h>
#include <stddef.h>

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
        t_fail();
    }
    for (uint8_t i = 0; i < 13; i++) {
        if (dp_payload.payload[i] != expected[i]) {
            t_fail();
        }
    }
    
    /*No failed tests - SUCCESS*/
    t_pass();

    /*Reinstate settings*/
    SystemState._sensor_n_outputs = tmp_sensor_n_outputs;
    SystemState._sensor_type = tmp_sensor_type;
    SystemState._sensor_status = tmp_sensor_status;
}
