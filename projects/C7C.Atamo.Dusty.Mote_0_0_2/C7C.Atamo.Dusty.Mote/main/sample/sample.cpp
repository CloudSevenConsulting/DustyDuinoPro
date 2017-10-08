/*
 * sample.cpp
 *
 * Created: 8/10/2017 7:28:54 PM
 *  Author: Aaron Hurst
 */ 

#include "../globals.h"
#include "sample.h"
#include "frame.h"


uint8_t sample(uint8_t sample_type)
{
    uint8_t tmp_ptr, ret;
    uint16_t time_val;
    
    /* Input validation*/
    if (sample_type > 3 || sample_type < 1) {
        return FAILURE;
    }
    
    /*Prepare timestamp*/
    tmp_ptr = reserve_field(DP_SAM__FIELD_TYPE_TIME, 2);
    time_val = get_timestamp();
    if (time_val == -1 || tmp_ptr == -1) {
        return FAILURE;
    }
    dp_payload.payload[tmp_ptr] = time_val; //TODO: store MSB/LSB properly, assuming 2-byte timestamp

    /*Sample required data*/
    if (sample_type == 1) {
        /*Sensor only*/
        ret = sample_sensor();
    }
    else if (sample_type == 2) {
        /*Diagnostic only*/
        ret = sample_diagnostic();
    }
    else if (sample_type == 3) {
        /*Sensor & diagnostic*/
        ret = sample_sensor();
        ret += sample_diagnostic();
    }

    if (ret > 0) {
        return FAILURE;
    }

    return SUCCESS
}
