/*
 * sensor.h
 *
 * Created: 2017-09-27 19:34:11
 *  Author: kjph
 */ 

#ifndef SENSOR_H_
#define SENSOR_H_

#include <stdint.h>

#define DP_SENS__OUTPUTS_MAX 6     /*max number of sensor outputs (16 bit each)*/
#define DP_SENS__RESOLUTION_MAX 2  /*bytes per sensor output*/

/*******************************************************************************
 * Sensor lookup
 ******************************************************************************/
#define DP_SENS__ACCEL_MAGNO 0x00

//TODO: sensor info LUT: number of outputs + polling command and expected response
//This is only needed for sensor config so could be done in a separate file

/*******************************************************************************
 * Sensor Status codes
 ******************************************************************************/
#define DP_SENS__STATUS_NOT_SET 0


//=====================================
/*! @brief Manages the selection of sensor driver and reading of sensor data
 *
 * Checks that a sensor has been configured (if not, the sensor configuration
 * routine is called), then calls the correct sensor driver function based
 * on the sensor type recorded in SystemState.
 *
 * @param buf buffer for storing sensor reading, passed to driver function
 * @param buf_size length of buffer in bytes (not number of elements)
 * 
 * @return 0 on success, 1 on failure
 */
uint8_t sensor_read(uint16_t*, uint8_t);


/*******************************************************************************
 * Sensor Drivers
 ******************************************************************************/

//=====================================
/*! @brief Read sensor data from the LSM303D accelerometer/magnetometer sensor
 *
 * Initiates communication with the LSM303D sensor, disables its low power mode
 * and enables its outputs. Then acquires sensor data, storing this in the
 * provided buffer. The sensor is returned to low power mode once sensor data is
 * read.
 *
 * @param sensor_addr module address at which sensor is located on the duinoPRO (1-6)
 * @param buf buffer for storing sensor reading, passed to driver function
 * 
 * @return 0 on success, 1 on failure
 */
uint8_t sensor_drive_accel_magno(uint8_t, uint16_t*);


#endif /* SENSOR_H_ */