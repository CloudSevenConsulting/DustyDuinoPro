/*
 * sample.cpp
 *
 * Created: 2017-09-28 06:50:27
 *  Author: kjph
 */ 

#include "sample.h"
#include "../globals.h"


uint8_t reserve_field(unit8_t type, unit8_t val_len)
{
    /*Populate field header*/
    uint8_t header_len = pack_field_header(type, val_len);

    /*Increment internal payload pointer*/
    dp_payload._payload_ptr += header_len + val_len;

    return dp_payload._payload_ptr - val_len;
}

uint8_t pack_field_header(unit8_t type, unit8_t len, unit8_t ptr)
{
    if (len < 2 || len > DP_SAM__LEN_FIELD_VAL_MAX) {
        return -1;
    }
    
    /* Construct field header
     * TODO: Need a LUT for all types (see frame.h ...FIELD_TYPE... for possible types received) Timestamp, sensor data, diagnostic?
     * Then combine this information with the length of the field value into a single byte code
     * (e.g. first 5 bits are type, next 3 are length)
     * Field value length: 2, 4, 6, 8, 10, or 12 bytes => 6 options => at least 3 bits to specify field value length
     * => only 5 bits available to specify type in field header (32 options)
     */
    //uint8_t field_header = sample_type_lookup(type)
    uint8_t field_header = 0; //dummy, TODO: implement real version

    /*Store field header in payload*/
    dp_payload.payload[ptr] = field_header;

    return DP_SAM__LEN_FIELD_HEAD;
}

void dp_payload_flush(void)
{
    memset(&dp_payload, 0, sizeof(dp_payload));
}
