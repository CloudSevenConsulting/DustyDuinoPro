/*
 * sensor.h
 *
 * Created: 2017-09-27 19:34:11
 *  Author: kjph
 */ 


#ifndef SENSOR_H_
#define SENSOR_H_

#include <stdint.h>

/*******************************************************************************
 * Sensor lookup (most likely will be in sensor header)
 ******************************************************************************/
#define DP_SENS__TYPE_A 0x00

uint8_t sensor_read(uint8_t *buf);

#endif /* SENSOR_H_ */