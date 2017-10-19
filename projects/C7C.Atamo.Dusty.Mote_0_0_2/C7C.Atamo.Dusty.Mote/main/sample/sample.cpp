/* sample.cpp */

/* COMMENTED OUT FOR TESTING
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
    
    /*Flush payload*/
    dp_payload_flush();
    
    /*Input validation*/
    if (sample_type != DP_SAM__TYPE_SENS && sample_type != DP_SAM__TYPE_DIAG && sample_type != DP_SAM__TYPE_BOTH) {
        return FAILURE;
    }

    /*Payload type and initialise pointer*/
    dp_payload.payload[0] = DP_SAM__PAYL_TYPE_DATA;
    dp_payload._payload_ptr = 2;

    /*Prepare timestamp*/
    sample_time();
    
    /*Sensor only*/
    if (sample_type == DP_SAM__TYPE_SENS) {
        dp_payload.payload[1] = 2;
        ret = sample_sensor();
    }
    /*Diagnostic only*/
    else if (sample_type == DP_SAM__TYPE_DIAG) {
        dp_payload.payload[1] = 2;
        ret = sample_diagnostic();
    }
    /*Sensor & diagnostic*/
    else if (sample_type == DP_SAM__TYPE_BOTH) {
        dp_payload.payload[1] = 3;
        ret = sample_sensor();
        ret += sample_diagnostic();
    }

    /*Check sample function return values*/
    if (ret > 0) {
        return FAILURE;
    }

    /*Check payload length not exceeded*/
    if (dp_payload._payload_ptr > DP_SAM__LEN_PAYL_MAX) {
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
    
    //TODO: check dn_time_ms returns successfully before storing timestamp
    
    /*Write timestamp to payload, MSB first*/
    dp_payload.payload[tmp_ptr]   = (uint8_t)(time_val>>24);
    dp_payload.payload[tmp_ptr+1] = (uint8_t)(time_val>>16);
    dp_payload.payload[tmp_ptr+2] = (uint8_t)(time_val>>8);
    dp_payload.payload[tmp_ptr+3] = (uint8_t)(time_val);
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
    ret = sensor_read(sens_data_buf, 2*DP_SENS__OUTPUTS_MAX);
    if (ret == FAILURE) {
        return FAILURE;
    }

    /*Write sensor data to payload, MSB first*/
    for (int i = 0; i < SystemState._sensor_n_outputs; i++) {
        dp_payload.payload[tmp_ptr+2*i]   = (uint8_t)(sens_data_buf[i]>>8);
        dp_payload.payload[tmp_ptr+2*i+1] = (uint8_t)(sens_data_buf[i]);
    }
    
    return SUCCESS;
}


uint8_t sample_diagnostic()
{
    uint8_t tmp_ptr;
    uint32_t Vbat_bits;
    float Vbat;

    /*Reserve field in payload from current payload pointer*/
    tmp_ptr = reserve_field(DP_SAM__FIELD_TYPE_DIAG,
        DP_SAM__LEN_FIELD_VAL_DIAG,
        &dp_payload._payload_ptr,
        &dp_payload.payload[dp_payload._payload_ptr]);
    
    /*Get Vbat*/
    /* COMMENTED OUT FOR TESTING
    Board.enableVbatSense(true);
    Vbat = Board.getVbat();
    Board.enableVbatSense(false);
    */
    Vbat = 378.5204;  // semi-random value for TESTING
    
    /*Copy bits of Vbat to a 32 bit variable*/
    memcpy(&Vbat_bits, &Vbat, DP_SAM__LEN_FIELD_VAL_DIAG);
    
    /*Write bits of Vbat to payload, MSB first*/
    dp_payload.payload[tmp_ptr]   = (uint8_t)(Vbat_bits>>24);
    dp_payload.payload[tmp_ptr+1] = (uint8_t)(Vbat_bits>>16);
    dp_payload.payload[tmp_ptr+2] = (uint8_t)(Vbat_bits>>8);
    dp_payload.payload[tmp_ptr+3] = (uint8_t)(Vbat_bits);

    return SUCCESS;
}