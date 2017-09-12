/*******************************************************************************
 * CONFIGURATION FUNCTIONS
 ******************************************************************************/

/* ----------
 * CONFIG_SET
 * ----------
 *      Parses configuration from payload and sets their value in volatile
 *      memory
 *
 * ARGUMENTS:
 *      - package_payload (char *): The data from the Dusty network
 *
 * RETURNS:
 *      0 on success, 1 on failure
 *
 */
int config_set(char *package_payload);

/* --------------
 * CONFIG_DEFAULT
 * --------------
 *      Loads configuration from non-volatile memory and sets their value in
 *      volatile memory
 *
 * ARGUMENTS:
 *      - none
 *
 * RETURNS:
 *      0 on success, 1 on failure
 *
 */
int config_default(void);

/* ----------------
 * CONFIG_PARAM_SET
 * ----------------
 *      Sets a single parameter (in volatile memory)
 *
 * ARGUMENTS:
 *      - param (int): The parameter index in volatile memory
 *      - value (int): The value to set the parameter to
 *
 * RETURNS:
 *      0 on success, 1 on failure
 *
 */
int config_param_set(int param, int value);

/* --------------------
 * CONFIG_PARAM_GET_CUR
 * --------------------
 *      Get the parameter's current value set in volatile memory
 *
 * ARGUMENTS:
 *      - param (int): the parameter index
 *
 * RETURNS:
 *      The parameter value if successful, 0 if failed
 *
 */
int config_param_get_cur(int param);

/* ---------------------
 * CONFIG_LOOKUP_GET_MAX
 * ---------------------
 *      Get a parameter's maximum allowable value (private)
 *
 * ARGUMENTS:
 *      - param (int): the parameter index
 *
 * RETURNS:
 *      The maximum allowable value
 *
 */
int config_lookup_get_max(int param);

/* ---------------------
 * CONFIG_LOOKUP_GET_MIN
 * ---------------------
 *      Get a parameter's minimum allowable value (private)
 *
 * ARGUMENTS:
 *      - param (int): the parameter index
 *
 * RETURNS:
 *      The minimum allowable value
 *
 */
int config_lookup_get_min(int param);

/*******************************************************************************
 * SYSTEM FUNCTIONS
 ******************************************************************************/
int sys_init(void);
void sys_sleep(int time_milliseconds);
void sys_reboot(void);

int sleepguard_set(void);
int sleepguard_free(void);

/*******************************************************************************
 * Calculation Functions
 ******************************************************************************/
int calc_time_sleep(int time_now);
int calc_time_wait(int time_now);

/*******************************************************************************
 * SAMPLING FUNCTIONS
 ******************************************************************************/
int sample_read(char slave_addr);
int sample_frame();

/*******************************************************************************
 * NETWORK FUNCTIONS
 ******************************************************************************/
int wsn_join(void);
int wsn_push(void);
int wsn_get_timenow(void);
int wsn_get_payload(void);

