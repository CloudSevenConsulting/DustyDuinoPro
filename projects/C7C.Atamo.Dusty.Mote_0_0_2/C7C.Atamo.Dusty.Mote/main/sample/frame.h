/*
 * frame.h
 *
 * Functions for framing according to our payload standard
 *
 */

#ifndef FRAME_H_
#define FRAME_H_

#define DP_SAM__N_FIELD_MAX 3           // timestamp, sensor data, diagnostic data
#define DP_SAM__LEN_FIELD_VAL_MAX 12    // sensor with six 16-bit values
#define DP_SAM__LEN_FIELD_HEAD 1
#define DP_SAM__LEN_DATL_HEAD 1
#define DP_SAM__LEN_PAYL_HEAD 1

#define DP_SAM__LEN_PAYL_MAX 26
    /* 2 bytes of headers, 2 bytes timestamp field
     * 1 byte sensor header, 12 bytes sensor data
     * 1 byte diagnostic header, 8 bytes diagnostic data
     */

#define DP_SAM__PAYL_TYPE_DATA 0
#define DP_SAM__PAYL_TYPE_CONF 1

//TODO: move to globals
typedef struct {
    uint8_t _n_bytes;
    uint8_t _ready_send;
    uint8_t _payload_ptr;
    uint8_t payload[DP_SAM__LEN_PAYL_MAX];
} dp_payload_t;

//=====================================
/*! @brief Reserve space in payload for field of desired length
 *
 * Increments internal payload pointer to end of required space for field
 * (i.e. reserve field). Calls pack_payload_header to build and write field
 * header to payload. Returns pointer to beginning of field value in
 * payload.
 *
 * @param type  code representing the type of data/field to be reserved
 * @param len   length of field value in bytes
 *
 * @return pointer to start of field value in payload, -1 on failure
 */
uint8_t reserve_field(type, len);

//=====================================
/*! @brief Build and write field header to payload
 *
 * Given the desired field type and length of the field value in bytes,
 * this function constructs the appropriate field header and writes it
 * to the payload at the position indicated by the pointer provided.
 *
 * @param type  code representing the type of data/field to be reserved
 * @param len   length of field value in bytes
 * @param ptr   pointer to position in payload to write field header
 *
 * @return length of field header, -1 on failure
 */
uint8_t pack_field_header(type, n, ptr);

//========== 
/*! @brief Clears the payload buffers
 *
 */
void dp_payload_flush(void);


#endif /* SAMPLE_H_ */