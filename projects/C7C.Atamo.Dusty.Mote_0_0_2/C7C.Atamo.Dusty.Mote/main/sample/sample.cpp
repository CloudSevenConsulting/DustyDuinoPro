/* sample.cpp */

#include <duinoPRO.h>   /* required for Vbat querying*/

#include "../sm_qsl/dn_time.h"
#include "../globals.h"

#include "sample.h"
#include "frame.h"
#include "sensor.h"

#define DP_SAM__TYPE_SENS 1
#define DP_SAM__TYPE_DIAG 2
#define DP_SAM__TYPE_BOTH 3

uint8_t sample(uint8_t sample_type)
{
    uint8_t ret;
    
    /*Input validation*/
    if (sample_type != DP_SAM__TYPE_SENS && sample_type != DP_SAM__TYPE_SENS && sample_type != DP_SAM__TYPE_SENS) {
        return FAILURE;
    }

    /*Flush payload*/
    dp_payload_flush();

    //TODO: payload header and dataload header
    
    /*Prepare timestamp*/
    sample_time();
    
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

    return SUCCESS;
}


void sample_time(void)
{
    uint8_t tmp_ptr;
    uint32_t time_val;
    
    /*Reserve field in payload from current payload pointer*/
    tmp_ptr = reserve_field(DP_SAM__FIELD_TYPE_TIME,
        DP_SAM__LEN_FIELD_VAL_TIME,
        &dp_payload._payload_ptr,
        &dp_payload.payload[dp_payload._payload_ptr]);
    
    /*Get timestamp*/
    time_val = dn_time_ms();
    
    //TODO: check for successful function returns before storing timestamp
    
    /*Write timestamp to payload, MSB first*/
    dp_payload.payload[tmp_ptr]   = (uint8_t)(time_val);
    dp_payload.payload[tmp_ptr+1] = (uint8_t)(time_val<<8);
    dp_payload.payload[tmp_ptr+2] = (uint8_t)(time_val<<8);
    dp_payload.payload[tmp_ptr+3] = (uint8_t)(time_val<<8);
}


uint8_t sample_sensor()
{
    uint8_t tmp_ptr, ret;
    uint16_t sens_data_buf[DP_SENS__OUTPUTS_MAX];
    
    /*Reserve field in payload from current payload pointer*/
    tmp_ptr = reserve_field(DP_SAM__FIELD_TYPE_SENS,
        SystemState._sensor_n_outputs*DP_SENS__RESOLUTION_MAX,
        &dp_payload._payload_ptr,
        &dp_payload.payload[dp_payload._payload_ptr]);
    
    /*Get sensor data*/
    ret = sensor_read(sens_data_buf);
    if (ret == FAILURE) {
        return FAILURE;
    }

    /*Write sensor data to payload, MSB first*/
    for (int i = 0; i < SystemState._sensor_n_outputs; i++) {
        dp_payload.payload[tmp_ptr+i]   = (uint8_t)(sens_data_buf[i]);
        dp_payload.payload[tmp_ptr+i+1] = (uint8_t)(sens_data_buf[i]<<8);
    }
    
    return SUCCESS;
}


uint8_t sample_diagnostic()
{
    uint8_t tmp_ptr;
    float Vbat;

    /*Reserve field in payload from current payload pointer*/
    tmp_ptr = reserve_field(DP_SAM__FIELD_TYPE_DIAG,
        DP_SAM__LEN_FIELD_VAL_DIAG,
        &dp_payload._payload_ptr,
        &dp_payload.payload[dp_payload._payload_ptr]);
    
    /*Get Vbat*/
    Board.enableVbatSense(true);
    Vbat = Board.getVbat();
    Board.enableVbatSense(false);

    /*Write Vbat to payload, MSB first*/
    memcpy(&dp_payload.payload[tmp_ptr], &Vbat, DP_SAM__LEN_FIELD_VAL_DIAG);
    //TODO: check we can assume float is 32 bits
    //TODO: check MSB is stored first (testing)

    return SUCCESS;
}