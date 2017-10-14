/*
 * sample.h
 *
 * Created: 8/10/2017 7:28:31 PM
 *  Author: Aaron Hurst
 */ 


#ifndef SAMPLE_H_
#define SAMPLE_H_


//=====================================
/*! @brief Fully prepares payload ready for push operation
 *
 * Loads required information into the dp_payload ready for sending.
 * The system timestamp is always included as the first field in the 
 * payload. The remaining information to be loaded is specified by
 * calling function:
 *  1. sensor data only, 
 *  2. diagnostic data only, or
 *  3. both.
 *
 * @param sample_type  type of sample operation to perform (1, 2 or 3)
 *
 * @return 0 on success, 1 on failure
 */
uint8_t sample(uint8_t);

//=====================================
/*! @brief Sample current timestamp
 *
 * @return 0 on success, 1 on failure
 */
uint16_t sample_time(void);

//=====================================
/*! @brief Sample sensor data
 *
 * @return 0 on success, 1 on failure
 */
uint8_t sample_sensor(void);

 //=====================================
/*! @brief Sample diagnostic data
 *
 * @return 0 on success, 1 on failure
 */
uint8_t sample_diagnostic(void);

#endif /* SAMPLE_H_ */