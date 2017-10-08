/*
 * sample.cpp
 *
 * Created: 2017-09-28 06:50:27
 *  Author: kjph
 */ 

#include "sample.h"

dp_payload_t dp_payload; //TODO: move to globals.h

void dp_payload_flush(void)
{
    memset(&dp_payload, 0, sizeof(dp_payload));
}

uint8_t add_field(uint8_t field_type, uint8_t *field_value)
{
    //Input validation
    if (sizeof(field_value) > DP_FRAME__N_FIELD_MAX)
    {
        return 1;
    }
}

void dp_sam_datl_incr(void)
{
    dp_payload.payload[DP_FRAME__LEN_PAYL_HEAD]++;
}