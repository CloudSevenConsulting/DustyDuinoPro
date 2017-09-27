/*
 * dp_sm.h
 *
 * Created: 2017-09-27 18:08:25
 *  Author: kjph
 */ 


#ifndef DP_SM_H_
#define DP_SM_H_

#include <stdint.h>

#define DP_SYS__SYS_READY 1
#define DP_SYS__SYS_NOT_READY 0

typedef struct {
	uint8_t _conf_set_flag;
	char *_conf;
	uint8_t _sys_sleepguard;
	uint8_t _sys_ready_flag;
	uint8_t _sensor_type;
	uint8_t _sensor_addr;
	uint8_t _sensor_conf_set; /*Has the sensor been found and is it set?*/
} sys_state;

void dp_state_init(void);
int dp_is_sys_ready(void);

//========== sys_sleep
/** @brief Put the system to sleep
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
 
 //========== sys_reboot
 /** @brief Reboots system peripherals that were turned off in sys_sleep.
  *
  * Note that this routine will take time before all peripherals are operational.
  * The routine will set a global flag when this is done
  *
  * @return 0 on success, 1 on failure
  */
 int dp_wake(void);
 
 //========== sleepguard_set
 /** @brief Public function to set the global sleepguard flag
  *
  * Note that if the flag is already set, this will increment the flag to
  * indicate how many resources require the system to be on. The complimentary
  * function sleepguard_free will decrease this flag value, until eventually the
  * the value is zero (false)
  *
  */
 void dp_sleepguard_set(void);
 
 //========== sleepguard_free
 /** @brief Public function to free the global sleepguard flag
  */
 void dp_sleepguard_free(void);
 

#endif /* DP_SM_H_ */