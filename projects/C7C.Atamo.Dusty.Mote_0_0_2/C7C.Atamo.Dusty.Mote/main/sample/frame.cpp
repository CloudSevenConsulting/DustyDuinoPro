/*
 * sample.cpp
 *
 * Created: 2017-09-28 06:50:27
 *  Author: kjph
 */ 

#include <string.h> /*memset*/

#include "../globals.h"
#include "frame.h"


uint8_t reserve_field(uint8_t type, uint8_t val_len, uint8_t *payload_ptr)
{
    /*Populate field header*/
    uint8_t header_len = pack_field_header(type, val_len, payload_ptr);
    if (header_len < 0) {
        return -1;
    }

    /*Increment internal payload pointer*/
    (*payload_ptr) += header_len + val_len;

    return (*payload_ptr) - val_len;
}


uint8_t pack_field_header(uint8_t type, uint8_t len, uint8_t *header_ptr)
{
    uint8_t field_header = 0;
    
    /*Input validation*/
    if (len < DP_SAM__LEN_FIELD_VAL_MIN || len > DP_SAM__LEN_FIELD_VAL_MAX || (len%2) != 0) {
        return -1;
    }
    if (!header_ptr) {
        return -1;
    }
    
    /*Encode field length into field header (3 MSBs, 6 possible values)*/
    field_header = (len<<4);

    /*Encode field type into field header (5 LSBs)*/
    if (type == DP_SAM__FIELD_TYPE_TIME) {
        field_header |= 0b00011111;
    }
    else if (type == DP_SAM__FIELD_TYPE_SENS) {
        field_header |= SystemState._sensor_type; /*_sensor_type has the sensor code as its 5 LSBs*/
    }
    else if (type == DP_SAM__FIELD_TYPE_DIAG) {
        field_header |= 0b00011110;
    }
    else {
        /*Invalid type*/
        return -1;
    }

    /*Store field header at specified pointer*/
    (*header_ptr) = field_header;

    return DP_SAM__LEN_FIELD_HEAD;
}


void dp_payload_flush(void)
{
    memset(&dp_payload, 0, sizeof(dp_payload));
}
