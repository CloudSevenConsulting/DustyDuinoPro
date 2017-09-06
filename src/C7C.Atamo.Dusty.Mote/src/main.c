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

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <asf.h>

/* ****************************************************************************
 * DEBUG Settings
 * ***************************************************************************/

/*Comment this out to turn off debug*/
#define TEST_MODE 0

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
void system_init (void)
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

