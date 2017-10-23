/*
 * TestDpSample.cpp
 *
 * Created: 19/10/2017 10:36:40 AM
 *  Author: Aaron Hurst
 */ 

#include <stdint.h>
#include <stddef.h>

#include "TestDpSample.h"
#include "../globals.h"
#include "../sample/sample.h"
#include "../sample/sensor.h"

#define RETURN_SUCCESS 0
#define RETURN_FAILURE 1

TestDpSample::TestDpSample(void)
{
};

void TestDpSample::run(void)
{
	TU_SH_DpSample_op();
}

void TestDpSample::TU_SH_DpSample_op(void)
{
    /*Variables*/
    uint8_t ret = -1;
    uint8_t tmp_sensor_n_outputs, tmp_sensor_type, tmp_sensor_status;

    /*Expected payload output*/
    uint8_t expected_sens[20] = {0x00, 0x02, 0x5F, 0x2A, 0x53, 0x01, 0xB7, 0xC0, 0x01, 0x02, 0x50, 0x10, 0xFF, 0x00, 0x11, 0xDD, 0x00, 0x11, 0x05, 0x04};
    uint8_t expected_diag[12] = {0x00, 0x02, 0x5F, 0x2A, 0x53, 0x01, 0xB7, 0x5E, 0x43, 0xBD, 0x42, 0x9C};
    uint8_t expected_both[25] = {0x00, 0x03, 0x5F, 0x2A, 0x53, 0x01, 0xB7, 0xC0, 0x01, 0x02, 0x50, 0x10, 0xFF, 0x00, 0x11, 0xDD, 0x00, 0x11, 0x05, 0x04, 0x5E, 0x43, 0xBD, 0x42, 0x9C};

    /*Save current settings*/
    tmp_sensor_n_outputs = SystemState._sensor_n_outputs;
    tmp_sensor_type = SystemState._sensor_type;
    tmp_sensor_status = SystemState._sensor_status;

    /*Apply test settings*/
	SystemState._sensor_n_outputs = 6;
	SystemState._sensor_type = DP_SENS__ACCEL_MAGNO;
	SystemState._sensor_status = 1;

    /*******************************************************************************
    * TEST CASE 1: sensor only
    *******************************************************************************/
    ret = sample(1);
    if (ret != RETURN_SUCCESS || dp_payload._ready_send != 1 || dp_payload._payload_ptr != 20) {
        t_fail();
    }
    for (uint8_t i = 0; i < 20; i++) {
        if (dp_payload.payload[i] != expected_sens[i]) {
            t_fail();
            break;
        }
    }

    /*******************************************************************************
    * TEST CASE 2: diagnostic only
    *******************************************************************************/
    ret = -1;
    ret = sample(2);
    if (ret != RETURN_SUCCESS || dp_payload._ready_send != 1 || dp_payload._payload_ptr != 12) {
        t_fail();
    }
    for (uint8_t i = 0; i < 12; i++) {
        if (dp_payload.payload[i] != expected_diag[i]) {
            t_fail();
        }
    }

   /*******************************************************************************
    * TEST CASE 3: sensor & diagnostic
    *******************************************************************************/
    ret = -1;
    ret = sample(3);
    if (ret != RETURN_SUCCESS || dp_payload._ready_send != 1 || dp_payload._payload_ptr != 25) {
        t_fail();
    }
    for (uint8_t i = 0; i < 25; i++) {
        if (dp_payload.payload[i] != expected_both[i]) {
            t_fail();
        }
    }

    /*******************************************************************************
    * PASSED BAU TESTS
    *******************************************************************************/
    t_pass();    
    
    /*******************************************************************************
    * TEST CASES 4 & 5: input validation
    *******************************************************************************/
    ret = -1;
    ret = sample(0);
    if (ret != RETURN_FAILURE || dp_payload._ready_send != 0 || dp_payload._payload_ptr != 0) {
        t_fail();
    }

    ret = -1;
    ret = sample(4);
    if (ret != RETURN_FAILURE || dp_payload._ready_send != 0 || dp_payload._payload_ptr != 0) {
        t_fail();
    }
    
    /*******************************************************************************
    * PASSED INPUT VALIDATION TESTS
    *******************************************************************************/
    t_pass();    
    
    /*Reinstate settings*/
    SystemState._sensor_n_outputs = tmp_sensor_n_outputs;
    SystemState._sensor_type = tmp_sensor_type;
    SystemState._sensor_status = tmp_sensor_status;
}
