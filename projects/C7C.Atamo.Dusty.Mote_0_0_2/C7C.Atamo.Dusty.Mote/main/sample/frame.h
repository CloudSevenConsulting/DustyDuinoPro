/*
 * frame.h
 *
 * Functions for framing according to our payload standard
 *
 */

#ifndef FRAME_H_
#define FRAME_H_

#include <stdint.h>

#define DP_SAM__N_FIELD_MAX 3           // timestamp, sensor data, diagnostic data
#define DP_SAM__LEN_FIELD_VAL_MAX 12    // sensor with six 16-bit values
#define DP_SAM__LEN_FIELD_VAL_MIN 2     // sensor with single 16-bit value
#define DP_SAM__LEN_FIELD_VAL_TIME 4
#define DP_SAM__LEN_FIELD_VAL_DIAG 4
#define DP_SAM__LEN_FIELD_HEAD 1
#define DP_SAM__LEN_DATL_HEAD 1
#define DP_SAM__LEN_PAYL_HEAD 1

#define DP_SAM__LEN_PAYL_MAX 26
    /* 1 byte payload header
     * 1 byte dataload header
     * 2 bytes timestamp field
     * 1 byte sensor header
     * 12 bytes sensor data
     * 1 byte diagnostic header
     * 8 bytes diagnostic data
     */

#define DP_SAM__PAYL_TYPE_DATA 0
#define DP_SAM__PAYL_TYPE_CONF 1

#define DP_SAM__FIELD_TYPE_TIME 0
#define DP_SAM__FIELD_TYPE_SENS 1
#define DP_SAM__FIELD_TYPE_DIAG 2

//TODO: change DP_SAM__ to DP_FRAME__ ?

typedef struct {
    uint8_t _ready_send;
    uint8_t _payload_ptr;
    uint8_t payload[DP_SAM__LEN_PAYL_MAX];
} dp_payload_t;

//=====================================
/*! @brief Reserve space in payload for field of desired length
 *
 * Increments internal payload pointer to end of required space for field
 * (i.e. reserves field). Calls pack_payload_header to build and write field
 * header to payload. Returns pointer to beginning of field value.
 *
 * @param type code representing the type of data/field to be reserved
 * @param len length of field value in bytes
 * @param payload_ptr pointer to internal payload pointer dp_payload._payload_ptr
 * @param header_ptr pointer to current position in payload
 *
 * @return pointer to start of field value in payload, -1 on failure
 */
uint8_t reserve_field(uint8_t, uint8_t, uint8_t*, uint8_t*);

//=====================================
/*! @brief Build and write field header to payload
 *
 * Given the desired field type and length of the field value in bytes,
 * this function constructs the appropriate field header and writes it
 * to the payload at the position indicated by the pointer provided.
 * 
 * Field value length is encoded as the first (most significant) three
 * bits of the field header such that:
 *   0b001XXXXX --> 2
 *   0b010XXXXX --> 4
 *   0b011XXXXX --> 6
 *   0b100XXXXX --> 8
 *   0b101XXXXX --> 10
 *   0b110XXXXX --> 12
 * 
 * Field type is encoded in the last (least significant) five bits of 
 * the field header. For instance:
 *   0bXXX11111 --> timestamp
 *   0bXXX11110 --> disgnostic
 * In the case of sensor data, the five LSBs are encoded with the sensor
 * type code (from system state variables).
 *
 * @param type code representing the type of field to be reserved
 * @param len length of field value in bytes
 * @param header_ptr pointer to current position in payload
 *
 * @return length of field header, -1 on failure
 */
uint8_t pack_field_header(uint8_t, uint8_t, uint8_t*);

//========== 
/*! @brief Clears the payload buffers
 *
 */
void dp_payload_flush(void);


#endif /* SAMPLE_H_ */