/*
 * sensor.h
 *
 * Created: 2017-09-27 19:34:11
 *  Author: kjph
 */ 


#ifndef SENSOR_H_
#define SENSOR_H_

#include <stdint.h>
#include "../globals.h" // SystemState

/*******************************************************************************
 * Sensor lookup
 ******************************************************************************/
#define DP_SENS__TYPE_A 0x00

/*******************************************************************************
 * Sensor Status codes
 ******************************************************************************/
#define DP_SENS__STATUS_NOT_SET 0x00


uint8_t sensor_read(uint8_t *buf);


/*******************************************************************************
 * Sensor Drivers
 ******************************************************************************/
uint8_t sensor_drive_type_a(uint8_t sensor_addr, uint8_t *buf);

#endif /* SENSOR_H_ */