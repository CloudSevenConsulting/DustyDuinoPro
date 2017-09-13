/*******************************************************************************
 * STATE CONTROL
 ******************************************************************************/
typedef struct {
    int _config_set_flag = 0;
    int *_config;
    int _sys_sleepguard = 0;
    int _sys_ready_flag = 0;
} sys_state;

static sys_state SystemState;

/*******************************************************************************
 * CONFIGURATION FUNCTIONS
 ******************************************************************************/

//========== config_set
/** @brief Parses configuration from payload and sets their value in volatile
 *         memory
 *
 * @param package_payload The data from the Dusty network
 *
 * @return 0 on success, 1 on failure
 */
int config_set(char *package_payload);

//========== config_default
/** @brief Loads configuration from non-volatile memory and sets their value in
 *         volatile memory
 *
 * Default configurations will be set in volatile memory to ensure that the
 * device does not need to rely on a central host to broadcast configuration
 * information at startup. This will drastically reduce network startup loads.
 *
 * @return 0 on success, 1 on failure
 */
int config_default(void);

//========== config_param_set
/** @brief Set the parameter's value set in volatile memory
 *
 * @param param the parameter index
 * @param value the value to set the value
 *
 * @return 0 on success, 1 on failure
 */
int config_param_set(int param, int value);

//========== config_param_get_cur
/** @brief Get the current value of the param set in volatile memory
 *
 * @param param the parameter index
 *
 * @return the current value of the parameter
 */
int config_param_get_cur(int param);

//========== config_param_lookup_max
/** @brief Get a parameter's maximum allowable value
 *
 * This should be privately called
 *
 * @param param the parameter index
 *
 * @return the maximum value of the parameter
 */
int config_param_lookup_max(int param);

//========== config_param_lookup_min
/** @brief Get a parameter's minimum allowable value
 *
 * This should be privately called
 *
 * @param param the parameter index
 *
 * @return the minimum value of the parameter
 */
int config_param_lookup_min(int param);

/*******************************************************************************
 * SYSTEM FUNCTIONS
 ******************************************************************************/

//========== sys_init
/** @brief Initialize the system and its core peripherals
 *
 * @return 0 on success, 1 on failure
 */
int sys_init(void);

int sysclk_init(void);
int wdt_init(void);
int port_init(void);
int timern_init(void);
int uart_init(void);
int iic_init(void);
int sensor_init(void);
int wsn_init(void);

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
int sys_sleep(int time_milliseconds);

//========== sys_reboot
/** @brief Reboots system peripherals that were turned off in sys_sleep.
 *
 * Note that this routine will take time before all peripherals are operational.
 * The routine will set a global flag when this is done
 *
 * @return 0 on success, 1 on failure
 */
int sys_reboot(void);

//========== sleepguard_set
/** @brief Public function to set the global sleepguard flag
 *
 * Note that if the flag is already set, this will increment the flag to
 * indicate how many resources require the system to be on. The complimentary
 * function sleepguard_free will decrease this flag value, until eventually the
 * the value is zero (false)
 *
 */
void sleepguard_set(void);

//========== sleepguard_free
/** @brief Public function to free the global sleepguard flag
 */
void sleepguard_free(void);

/*******************************************************************************
 * Calculation Functions
 ******************************************************************************/

//========== calc_time_sleep
/** @brief Determine the time to sleep before the next sampling time
 *
 * The next sampling time is next multiple of the sampleing_period (conf
 * parameter) rounded down.
 *
 * @param time_now time in milliseconds second last epoch
 *
 * @return 0 on success, 1 on failure
 */
int calc_time_sleep(int time_now);
int calc_time_wait(int time_now);

/*******************************************************************************
 * SAMPLING FUNCTIONS
 ******************************************************************************/
int sample_read(char *slave_addr, char *buf);
int sample_frame(char *buf);

/*******************************************************************************
 * NETWORK FUNCTIONS
 ******************************************************************************/
int wsn_join(void);
int wsn_push(void);
int wsn_get_timenow(void);
int wsn_get_payload(void);

/*******************************************************************************
 * COMMUNICATIONS FUNCTIONS
 ******************************************************************************/
int uart_tx(void);
int uart_rx(void);

int iic_write(void);
int iic_write_read(void);
int iic_read(void);
