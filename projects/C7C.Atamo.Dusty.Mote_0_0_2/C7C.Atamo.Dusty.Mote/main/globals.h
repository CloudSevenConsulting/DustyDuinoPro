/*
 * globals.h
 *
 * Created: 2017-09-20 18:47:14
 *  Author: kjph
 */ 


#ifndef GLOBALS_H_
#define GLOBALS_H_

/*******************************************************************************
 * DP Look-Up Table
 ******************************************************************************/
 #define DP_LUT__N_PARAM 10
 
 #define DP_LUT__LOG_LEVEL               0x00
 #define DP_LUT__SAMPLE_PERIOD           0x01
 #define DP_LUT__SLEEP_OVERHEAD          0x02
 #define DP_LUT__SENSOR_COMM_TYPE        0x03
 #define DP_LUT__SENSOR_RESOLUTION       0x04
 #define DP_LUT__SENSOR_CLK_SPEED        0x05
 #define DP_LUT__WSN_JOIN_DC_INIT        0x06
 #define DP_LUT__WSN_JOIN_DC_DECR        0x07
 #define DP_LUT__WSN_JOIN_WAIT_INIT      0x08
 #define DP_LUT__WSN_JOIN_WAIT_INCR      0x09

/*******************************************************************************
 * Key System Libraries
 ******************************************************************************/
#include "dp_sm.h"
#include <duinoPRO.h>

/*******************************************************************************
 * Singletons/Globals
 ******************************************************************************/
extern duinoPRO Board;
extern sys_state SystemState;
extern char sys_config[DP_LUT__N_PARAM];

/*******************************************************************************
 * Sensor lookup (most likely will be in sensor header)
 ******************************************************************************/
 #define DP_SENS_TYPE 0x00


#endif /* GLOBALS_H_ */