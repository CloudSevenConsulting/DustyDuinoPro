/*============================================================================*/
/*!
 * @file dp_sm.h
 *
 * @brief State Machine (SM) Module for DuinoPro (DP)
 *
 * The SM module is responsible for controlling the state of the system. It
 * provides an interface to the state variables that define the system and
 * ensures resources have correct control over state resoruces
 *
 * @date 2017/10/01
 * @author Jamie K. Phan
 *
 */
/*============================================================================*/

#ifndef DP_SM_H_
#define DP_SM_H_

#include <stdint.h>

#define DP_SYS__SYS_READY 1
#define DP_SYS__SYS_NOT_READY 0 

/*!
 * @struct sys_state
 * 
 * @var sys_state::_conf_set_flag
 *      Used by configuration module to determine if system has loaded a config
 *      into memory or not.
 * @var sys_state::_conf
 *      Pointer to the configuration used during run-time
 * @var sys_state::_sys_sleepguard
 *      Prevents system from sleeping wheng greater than 0
 * @var sys_state::_sensor_type
 *      Indicates which sensor driver to use for current session
 * @var sys_state::_sensor_addr
 *      Indicates the sensor's slave address. Depends on communication (drive) 
 *      used.
 * @var sys_state::_sensor_status
 *      Indicates the status of the sensor module
 * @var sys_state:_sys_ready_flag
 *      Indicates if the system is fully initialised
 */
typedef struct {
    uint8_t _conf_set_flag;
	char *_conf;
	uint8_t _sys_sleepguard;
    uint8_t _sys_ready_flag;
    uint8_t _sensor_status;
	uint8_t _sensor_type;
	uint8_t _sensor_addr;
} sys_state;

//=====================================
/*! @brief Initialise state variables
*
* Ensures memory for system state variables is allocated correctly
*
*/
void dp_state_init(void);

//=====================================
/*! @brief Brief
*
* Interface for external modules to check if system is ready. This is relevant
* after the system has woke up from a sleep.
*
* @param param
*
* @return DP_SYS__SYS_READY=1 if system ready, DP_SYS__SYS_NOT_READY=0 elsewise
*/
int dp_is_sys_ready(void);

//=====================================
/*! @brief Put the system to sleep
 *
 * Sleep in this context refers to a low-power mode in which pre-determined
 * peripherals are turned off to reduce energy consumption by the device. Note
 * that these peripherals will require rebooting on wakeup.
 * This routine can fail if the sleepguard is set, preventing the system from
 * sleeping
 *
 * @param time_milliseconds The time to put the system to sleep for in
 *                          milliseconds
 *
 * @return 0 on success, 1 on failure
 */
 void dp_sleep(uint32_t time_milliseconds);
 
 //=====================================
 /*! @brief Reboots system peripherals that were turned off in sys_sleep.
  *
  * Note that this routine will take time before all peripherals are operational.
  * The routine will set a global flag when this is done
  *
  * @return 0 on success, 1 on failure
  */
 int dp_wake(void);
 
 //=====================================
 /*! @brief Public function to set the global sleepguard flag
  *
  * Note that if the flag is already set, this will increment the flag to
  * indicate how many resources require the system to be on. The complimentary
  * function sleepguard_free will decrease this flag value, until eventually the
  * the value is zero (false)
  *
  */
 void dp_sleepguard_set(void);
 
 //=====================================
 /*! @brief Public function to free the global sleepguard flag
  */
 void dp_sleepguard_free(void);
 

#endif /* DP_SM_H_ */