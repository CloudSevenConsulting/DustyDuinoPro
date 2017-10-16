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
#define DP_SENS__ACCEL_MAGNO 0x0

//TODO: sensor info LUT: number of outputs + polling command and expected response (only needed for sensor config)

/*******************************************************************************
 * Sensor Status codes
 ******************************************************************************/
#define DP_SENS__STATUS_NOT_SET 0


uint8_t sensor_read(uint16_t *buf);


/*******************************************************************************
 * Sensor Drivers
 ******************************************************************************/
uint8_t sensor_drive_accel_magno(uint8_t sensor_addr, uint16_t *buf);

#endif /* SENSOR_H_ */