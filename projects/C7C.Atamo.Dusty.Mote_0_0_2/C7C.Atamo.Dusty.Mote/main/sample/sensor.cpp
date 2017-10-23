/*
 * sensor.cpp
 *
 * Created: 2017-09-27 19:34:22
 *  Author: kjph
 */

/*External libraries*/
#include "0x00_AccelMagno/AccelMagno.h"

/*Project includes*/
#include "sensor.h"
#include "../globals.h" /*SystemState*/


uint8_t sensor_read(uint16_t *buf, uint8_t buf_size)
{
    int ret;
 
    /*Check if the buffer is large enough*/
    if (buf_size < SystemState._sensor_n_outputs) {
        return FAILURE;
    }

    /*Check the sensor is set*/
    if (SystemState._sensor_status == DP_SENS__STATUS_NOT_SET) {
        /*TODO: run sensor configuration*/
    }

    /*Select and run sensor driver*/
    switch (SystemState._sensor_type) {
        case DP_SENS__ACCEL_MAGNO:
            ret = sensor_drive_accel_magno(SystemState._sensor_addr, buf);
            /*TODO: check return*/
            /*TODO: set buffer to all zeros if invalid*/
            break;
        /*All the other types*/
        /*..etc*/
        default:
            /*Error function: CRITICAL*/
            return FAILURE;
            break;
    }

    return SUCCESS;
}

//TODO: move to separate file - one each for each sensor driver/type
uint8_t sensor_drive_accel_magno(uint8_t sensor_addr, uint16_t *buf)
{
    /*Check if the buffer is large enough*/
    if (sizeof(buf) < 6) {
        return FAILURE;
    }
    
    /*Initiate connection to Accel/Magno sensor and exit low power mode*/
    AccelMagno sensor_AccMag(sensor_addr);
    sensor_AccMag.begin();
    sensor_AccMag.lowPowerMode(false);

    /*Set and enable accelerometer and magnetometer at full scales*/
    sensor_AccMag.setAccelFullScale(ACCEL_2G);
    sensor_AccMag.setMagnoFullScale(MAGNO_2GAUSS);
    sensor_AccMag.enableAccel();
    sensor_AccMag.enableMagno();
    //TODO: ask client if it is desirable to be able operate in different modes? e.g. accel but not not mag

    /*Acquire sensor data*/
    buf[0] = static_cast<uint16_t>(sensor_AccMag.accelX());
    buf[1] = static_cast<uint16_t>(sensor_AccMag.accelY());
    buf[2] = static_cast<uint16_t>(sensor_AccMag.accelZ());
    buf[3] = static_cast<uint16_t>(sensor_AccMag.magnoX());
    buf[4] = static_cast<uint16_t>(sensor_AccMag.magnoY());
    buf[5] = static_cast<uint16_t>(sensor_AccMag.magnoZ());

    /*Put sensor into low power mode*/
    sensor_AccMag.lowPowerMode(true);

    return SUCCESS;
}