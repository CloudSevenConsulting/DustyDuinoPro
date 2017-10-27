/*============================================================================*/
/*!
 * @file tester.h
 *
 * @brief Handles system testing 
 *
 * The tester module provides testers fine grain control over what tests are 
 * performed. This is done by defining the macros DP_BUILD__TCTRL. Setting the
 * macro to 1 will run the tests and vv.
 *
 * @date 2017/10/01
 * @author Jamie K. Phan
 *
 */
/*============================================================================*/

#ifndef TESTER_H_
#define TESTER_H_

#define DP_BUILD__TCTRL_DNJOIN 0
#define DP_BUILD__TCTRL_DPUART 0
#define DP_BUILD__TCTRL_DPSYS 1
#define DP_BUILD__TCTRL_DPFRAMING 1
#define DP_BUILD__TCTRL_DPSAMPLE 1
#define DP_BUILD__TCTRL_DPSAMPLE_DIAG 1
#define DP_BUILD__TCTRL_DPSAMPLE_TIME 1
#define DP_BUILD__TCTRL_DPSAMPLE_SENS 1
#define DP_BUILD__TCTRL_PORT 1

//=====================================
/*! @brief Runs all tests in Testing package
*
*/
void do_system_test(void);

#endif /* TESTER_H_ */