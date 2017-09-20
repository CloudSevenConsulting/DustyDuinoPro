/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

 #define TEST_MODE 0/*Set this to turn on debug*/

/* ****************************************************************************
 * Standard Libraries
 * ***************************************************************************/
#include <asf.h>
#include <avr/io.h>

/* ****************************************************************************
 * Drivers
 * ***************************************************************************/
#include "sm_qsl/dn_qsl_api.h"

/* ****************************************************************************
 * DEBUG Includes
 * ***************************************************************************/
#if TEST_MODE
#include "tester/tester.h"
#endif

/* ****************************************************************************
 * FUNCTION: system_init
 * *********************
 * To keep the main routine clean; these commands refer to initialisation 
 * and should only be run during startup
 *
 * ***************************************************************************/
static void system_init (void)
{
	board_init();
	sysclk_init();
}

int main (void)
{

	system_init();

#if TEST_MODE
	while(1)
	{
		tester();
	}
#else
	while(1)
	{
	}
#endif
}

