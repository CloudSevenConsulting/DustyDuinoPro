/*
 * sensor.cpp
 *
 * Created: 2017-09-27 19:34:22
 *  Author: kjph
 */

#include "sensor.h"
#include "../dp_conf.h"
#include "../globals.h"

uint8_t sensor_read(uint8_t *buf)
{
    int ret;
 
    /*Check if the buffer is the correct size*/
    if (sizeof(buf) < dp_conf_param_get_cur(DP_LUT__SENSOR_RESOLUTION))
    {
        return FAILURE;
    }

    /*Check the sensor is set*/
    if (SystemState._sensor_conf_set == 0 )
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
            break;
        /*All the other types*/
        /*..etc*/
        default:
            /*Error function: CRITICAL*/
            break;
    }

    return SUCCESS;
}
