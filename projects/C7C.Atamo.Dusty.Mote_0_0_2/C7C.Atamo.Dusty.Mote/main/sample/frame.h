/*! Sample.h
 *
 * Functions for framing according to our payload standard
 *
 */

#ifndef SAMPLE_H_
#define SAMPLE_H_

#define DP_SAM__N_FIELD_MAX 3           // timestamp, sensor data, diagnostic data
#define DP_SAM__LEN_FIELD_VAL_MAX 6     // sensor with 6 values
#define DP_SAM__LEN_FIELD_HEAD 1
#define DP_SAM__LEN_DATL_HEAD 1
#define DP_SAM__LEN_PAYL_HEAD 1

#define DP_SAM__LEN_PAYL_MAX 23

#define DP_SAM__PAYL_TYPE_SENS 0    //TODO: suggest change to DP_SAM__PAYL_TYPE_DATA
#define DP_SAM__PAYL_TYPE_CONF 1

typedef struct {
    uint8_t _n_bytes;
    uint8_t _ready_send;
    uint8_t payload[DP_SAM__LEN_PAYL_MAX];
} dp_payload_t;

//========== 
/*! Clears the payload buffers
 *
 */
void dp_payload_flush(void);

//========== 
/*! Add a field frame to the payload
 *
 * @param field_type
 * @param field_value
 *
 * @return 0 on success, 1 on failure
 */
 uint8_t add_field(uint8_t, uint8_t*);

//========== 
/*! Increment the dataload header to indicate an extra field
 *
 */
void dp_sam_datl_head_incr(void);

//========== 
/*! Set the payload header type
 *
 */
void dp_sam_payl_head_set(uint8_t);


#endif /* SAMPLE_H_ */