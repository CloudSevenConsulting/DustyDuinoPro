/*
 * dp_conf.h
 *
 * Created: 2017-09-27 19:13:51
 *  Author: kjph
 */ 


#ifndef DP_CONF_H_
#define DP_CONF_H_

#include <stdint.h>

/*******************************************************************************
 * DP Look-Up Table
 ******************************************************************************/
#define DP_LUT__N_PARAM 11
 
#define DP_LUT__COL_FIELD_LEN 0
#define DP_LUT__COL_MAX_VAL 1
#define DP_LUT__COL_MIN_VAL 2

#define LUT_IDX__LOG_LEVEL               0x00
#define LUT_IDX__SAMPLE_PERIOD           0x01
#define LUT_IDX__SLEEP_OVERHEAD          0x02
#define LUT_IDX__SENSOR_COMM_TYPE        0x03
#define LUT_IDX__SENSOR_RESOLUTION       0x04
#define LUT_IDX__SENSOR_CLK_SPEED        0x05
#define LUT_IDX__WSN_JOIN_DC_INIT        0x06
#define LUT_IDX__WSN_JOIN_DC_DECR        0x07
#define LUT_IDX__WSN_JOIN_WAIT_INIT      0x08
#define LUT_IDX__WSN_JOIN_WAIT_INCR      0x09
#define LUT_IDX__SLEEP_GUARD_TIMEOUT     0x10

//========== config_set
/** @brief Ensures configuration parameters are set. If not set, default
 *         parameters are loaded from non-volatile memory. Once set, if a packet
 *         payload is passed as an argument, then the payload is parsed and the
 *         parameters contained therein are updated accordingly.
 *
 * @param package_payload The full packet payload received in a configuration
 *                        packet sent by the Dusty network manager
 *
 * @return 0 on success, 1 on failure
 */
uint8_t dp_conf_set(char *);
 
 //========== config_default
 /** @brief Loads configuration from non-volatile memory and sets their values in
  *         volatile memory
  *
  * Default configurations will be set in non-volatile memory to ensure that the
  * device does not need to rely on a central host to broadcast configuration
  * information at startup. This will drastically reduce network startup loads.
  *
  * @return 0 on success, 1 on failure
  */
uint8_t dp_conf_default(void);

 //========== config_param_set
 /** @brief Set the parameter's value in volatile memory
  *
  * @param param the parameter type byte received in the configuration packet
  * @param value the parameter value byte(s) received in the configuration packet
  *
  * @return 0 on success, 1 on failure
  */
uint8_t dp_conf_param_set(uint8_t, uint8_t);
 
 //========== config_param_get_cur
 /** @brief Get the current value of the param set in volatile memory
  *
  * @param param the parameter index
  *
  * @return the current value of the parameter
  */
uint8_t dp_conf_param_get_cur(uint8_t);
 
 //========== config_param_lookup_max
 /** @brief Get a parameter's maximum allowable value
  *
  * This should be privately called
  *
  * @param param the parameter index
  *
  * @return the maximum value of the parameter
  */
uint8_t dp_conf_param_lookup_max(uint8_t);
 
 //========== config_param_lookup_length
 /** @brief Get the number of bytes for a parameter's value when received in a 
  *         configuration packet
  *
  * This should be privately called
  *
  * @param param the parameter index
  *
  * @return the number of bytes to expect for the parameter value in the
  *         configuration packet
  */
uint8_t dp_conf_param_lookup_max(uint8_t);
 
 //========== config_param_lookup_min
 /** @brief Get a parameter's minimum allowable value
  *
  * This should be privately called
  *
  * @param param the parameter index
  *
  * @return the minimum value of the parameter
  */
uint8_t dp_conf_param_lookup_min(uint8_t);



#endif /* DP_CONF_H_ */