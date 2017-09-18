/*******************************************************************************
 * Standard Defines
 ******************************************************************************/
#define SUCCESS 1
#define FAILURE 0

/*******************************************************************************
 * Configuration Lookup Table
 ******************************************************************************/
#define CONFIG__LUT_SENSOR_RESOLUTION 0x00
/*.. etc*/

/*******************************************************************************
 * Sensor lookup (most likely will be in sensor header)
 ******************************************************************************/
#define SENSOR__TYPE_A 0x00
/*.. etc*/

/*******************************************************************************
 * STATE CONTROL
 ******************************************************************************/
typedef struct {
    int _config_set_flag = 0;
    int *_config;
    int _sys_sleepguard = 0;
    int _sys_ready_flag = 0;
    int _sensor_type;
    int _sensor_addr;
    int _sensor_conf_flag; /*Has the sensor been found and is it set?*/
} sys_state;

static sys_state SystemState;

/*******************************************************************************
 * CONFIGURATION FUNCTIONS
 ******************************************************************************/

//========== config_set
/** @brief Ensures configuration parameters are set. If not set, default
 *         parameters are loaded from non-volatile memory. If set and a packet
 *         payload is passed as an argument, then the payload is parsed and the
 *         parameters contained therein are updated accordingly.
 *
 * @param package_payload The full packet payload received in a configuration
 *                        packet sent by the Dusty network manager
 *
 * @return 0 on success, 1 on failure
 */
int config_set(char *package_payload);

//========== config_default
/** @brief Loads configuration from non-volatile memory and sets their values in
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
/** @brief Set the parameter's value in volatile memory
 *
 * @param param the parameter type byte received in the configuration packet
 * @param value the parameter value byte(s) received in the configuration packet
 *
 * @return 0 on success, 1 on failure
 */
int config_param_set(int type, int value);

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

//========== sensor_read
/** @brief Standard inteface between Duino and sensor; sensor agnostic
 *
 * sensor drivers are called in this routine which are modular to allow for
 * sensor agnostic reading
 *
 * @param buf the buffer to read data into
 *
 * @return 0 on success, 1 on failure
 */
int sensor_read(char *buf);
int sensor_frame(char *buf);

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
