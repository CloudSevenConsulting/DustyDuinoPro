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
 * @param sample_type type of sample operation to perform (1, 2 or 3)
 *
 * @return 0 on success, 1 on failure
 */
uint8_t sample(uint8_t);

//=====================================
/*! @brief Sample current timestamp
 * 
 * Reads and stores the current Dust Network time in the payload (global
 * variabele) starting from the current position of the payload internal
 * pointer.
 * 
 * The timestamp is a uint32_t natively. This is stored sequentially as
 * four uint8_t entries in the payload. The most significant byte of the
 * timestamp is stored first.
 */
void sample_time(void);

//=====================================
/*! @brief Sample sensor data
 *
 * Reads and stores current sensor readings in the payload (global
 * variable) starting from the current position of the payload internal
 * pointer.
 * 
 * Support is provided throughout the duinoPRO-Dusty software for sensor
 * data up to 16-bit resolution. The 16-bits for each sensor reading are
 * stored as two uint8_t entries in the payload. The most significant
 * byte of sensor data is stored first in the payload.
 * 
 * @return 0 on success, 1 on failure
 */
uint8_t sample_sensor(void);

 //=====================================
/*! @brief Sample diagnostic data
 *
 * Reads and stores the current battery voltage in the payload (global
 * variable) starting from the current position of the payload internal
 * pointer.
 * 
 * The duinoPRO battery voltage is measured using Board.getVbat(), which
 * is defined in the duinoPRO library.
 * 
 * Battery voltage sensing is toggled on and off during the call to this
 * function to minimise energy consumption.
 * 
 * The battery voltage is returned as a floating point number (32 bit).
 * In the payload, this is stored as a series of four uint8_t numbers.
 * This requires some additional re-assembly of the data at the network
 * manager. As usual, the most significent byte is stored first in the
 * payload.
 * 
 * @return 0 on success, 1 on failure
 */
uint8_t sample_diagnostic(void);

#endif /* SAMPLE_H_ */