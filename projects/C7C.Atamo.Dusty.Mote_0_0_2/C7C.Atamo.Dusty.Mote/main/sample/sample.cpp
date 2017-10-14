/* sample.cpp */

#include <duinoPRO.h>   /* required for Vbat querying*/

#include "../sm_qsl/dn_time/h"
#include "../globals.h"

#include "sample.h"
#include "frame.h"

#define DP_SAM__TYPE_SENS 1
#define DP_SAM__TYPE_DIAG 2
#define DP_SAM__TYPE_BOTH 3

uint8_t sample(uint8_t sample_type)
{
    uint8_t ret;
    
    /*Input validation*/
    /*TODO: add macros for the three different types, check for equality to any of these*/
    if (sample_type > 3 || sample_type < 1) {
        return FAILURE;
    }

    /*Flush payload*/
    dp_payload_flush();

    //TODO: payload header and dataload header
    
    /*Prepare timestamp*/
    ret = sample_time();
    if (ret > 0) {
        return FAILURE;
    }

    /*Sample required data*/
    if (sample_type == DP_SAM__TYPE_SENS) {
        /*Sensor only*/
        ret = sample_sensor();
    }
    else if (sample_type == DP_SAM__TYPE_DIAG) {
        /*Diagnostic only*/
        ret = sample_diagnostic();
    }
    else if (sample_type == DP_SAM__TYPE_BOTH) {
        /*Sensor & diagnostic*/
        ret = sample_sensor();
        ret += sample_diagnostic();
    }

    /*Check sample function return values*/
    if (ret > 0) {
        return FAILURE;
    }

    /*Payload ready to send*/
    dp_payload._ready_send = 1;

    return SUCCESS
}


void sample_time(void)
{
    uint8_t tmp_ptr;
    uint32_t time_val;
    
    /*Reserve field in payload from current payload pointer*/
    tmp_ptr = reserve_field(DP_SAM__FIELD_TYPE_TIME, DP_SAM__LEN_FIELD_TIME, &dp_payload._payload_ptr);
    
    /*Get timestamp*/
    time_val = dn_time_ms();
    
    //TODO: check for successful function returns before storing timestamp
    
    /*Store timestamp in payload, MSB first*/
    dp_payload.payload[tmp_ptr]   = (uint8_t)(time_val);
    dp_payload.payload[tmp_ptr+1] = (uint8_t)(time_val<<8);
    dp_payload.payload[tmp_ptr+2] = (uint8_t)(time_val<<8);
    dp_payload.payload[tmp_ptr+3] = (uint8_t)(time_val<<8);
}


uint8_t sample_sensor()
{
    
    
    return SUCCESS;
}


uint8_t sample_diagnostic()
{
    float Vbat;

    /*Reserve field in payload from current payload pointer*/
    tmp_ptr = reserve_field(DP_SAM__FIELD_TYPE_DIAG, DP_SAM__LEN_FIELD_DIAG, &dp_payload._payload_ptr);
    
    /*Get Vbat*/
    Board.enableVbatSense();
    Vbat = Board.getVbat();
    Board.disableVbatSense();

    /*Store Vbat in payload, MSB first*/
    memcpy(&dp_payload.payload[tmp_ptr], &Vbat, DP_SAM__LEN_FIELD_DIAG)
    //TODO: check we can assume float is 32 bits
    //TODO: check MSB is stored first

    return SUCCESS;
}