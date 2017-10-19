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

//TODO: sensor info LUT: number of outputs + polling command and expected response (only needed for sensor config)

/*******************************************************************************
 * Sensor Status codes
 ******************************************************************************/
#define DP_SENS__STATUS_NOT_SET 0

//TODO: documentation: note that the second argument is the number of bytes in buf (not the number of elements)
uint8_t sensor_read(uint16_t*, uint8_t);


/*******************************************************************************
 * Sensor Drivers
 ******************************************************************************/
uint8_t sensor_drive_accel_magno(uint8_t, uint16_t*);

#endif /* SENSOR_H_ */