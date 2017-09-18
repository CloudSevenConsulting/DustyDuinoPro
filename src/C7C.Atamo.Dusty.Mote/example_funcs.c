#include "temp_all_funcs.h"
#include /*TODO: The sensor drive type header*/

int sensor_read(char *buf)
{
    int ret;

    /*Check if the buffer is the correct size*/
    if (sizeof(buf) < int config_param_get_cur(CONFIG__LUT_SENSOR_RESOLUTION))
    {
        return FAILURE;
    }

    /*Check the sensor is set*/
    if (SystemState._sensor_conf_set == 0 )
    {
        /*TODO: Configure the sensor*/
        /*TODO: Check return*/
    }

    case SystemState._sensor_type
        switch SENSOR__TYPE_A:
            ret = sensor_drive_type_a(SystemState._sensor_addr, buf[0]);
            /*TODO: check return*/
            break;
        /*All the other types*/
        /*..etc*/
        default:
            /*Error function: CRITICAL*/

    /*TODO: Check macros for returns*/
    return SUCCESS;
}
