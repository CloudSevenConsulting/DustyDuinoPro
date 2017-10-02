/*============================================================================*/
/*!
 * @file globals.h
 *
 * @brief DuinoPro (DP) global variables required across modules
 *
 * @date 2017/10/01
 * @author Jamie K. Phan
 *
 */
/*============================================================================*/

#ifndef GLOBALS_H_
#define GLOBALS_H_

#define FAILURE 1
#define SUCCESS 0

/*******************************************************************************
 * Key System Libraries
 ******************************************************************************/
#include "dp_sm.h"
#include "dp_conf.h"
#include <duinoPRO.h>

/*******************************************************************************
 * Singletons/Globals
 ******************************************************************************/
extern duinoPRO Board;
extern sys_state SystemState;
extern char sys_conf[DP_LUT__N_PARAM];

#endif /* GLOBALS_H_ */