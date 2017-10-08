/*
 * sensor.cpp
 *
 * Created: 2017-09-27 19:34:22
 *  Author: kjph
 */

// External libraries
#include <0x00_AccelMagno/AccelMagno.h>

// Project includes
#include "sensor.h"
#include "../dp_conf.h"
#include "../globals.h"

uint8_t sensor_read(uint8_t *buf)
{
    int ret;
    uint8_t swp[DP_SAM__N_FIELD_MAX*DP_SAM__LEN_FIELD_VAL_MAX];
 
    /*Check if the buffer is the correct size*/
    if (sizeof(buf) < dp_conf_param_get_cur(LUT_IDX__SENSOR_RESOLUTION))
    {
        return FAILURE;
    }

    /*Check the sensor is set*/
    if (SystemState._sensor_status == DP_SENS__STATUS_NOT_SET)
    {
        /*TODO: Configure the sensor*/
        /*TODO: Check return*/
        return FAILURE;
    }

    switch (SystemState._sensor_type)
    {
        case DP_SENS__TYPE_A:
            //ret = sensor_drive_type_a(SystemState._sensor_addr, buf[0]);
            /*TODO: check return*/
            /*TODO: set buffer to all zeros (up to DP_LUT__SENSOR_RESOLUTION) if invalid*/
            break;
        /*All the other types*/
        /*..etc*/
        default:
            /*Error function: CRITICAL*/
            break;
    }

    return SUCCESS;
}


// TODO: may need to move this to a separate file - one each for each sensor driver
uint8_t sensor_drive_type_a(uint8_t sensor_addr, uint8_t *buf)
{
    // Define instance of Accel/Magno sensor at appropriate board position
    AccelMagno sensor_AccMag(sensor_addr);

    // Begin using the instance of the Accel/Magno module
    sensor_AccMag.begin();

    // Set the accelerometer and magnetometer full scales
    myAccMag.setAccelFullScale(ACCEL_2G);
    myAccMag.setMagnoFullScale(MAGNO_2GAUSS);

    //TODO: is it desirable to operate in different modes? e.g. get accel but not not mag?
    // Enable the accelerometer and magnetometer
    myAccMag.enableAccel();
    myAccMag.enableMagno();

    //TODO: store these in the buffer
    accX = myAccMag.accelX();
    accY = myAccMag.accelY();
    accZ = myAccMag.accelZ();
    magX = myAccMag.magnoX();
    magY = myAccMag.magnoY();
    magZ = myAccMag.magnoZ();

    //TODO: see AccelMagno-Example.ino for exampel code
    //TODO: investigate sensor low power mode
}