 /* ============================================================================
 * C7C.Atamo.Dusty.Mote.main
 * -------------------------
 * 
 * -------
 * PURPOSE
 * -------
 *      Function entry point
 *
 * ------------------
 * DEVELOPMENT STATUS
 * ------------------
 *      Last Updated: 2017-09-04
 *      Last Editor: Phan, J.
 * 
 *		Modified skeleton
 *
 * ----------------
 * ADDITIONAL NOTES
 * ----------------
 *		Comment/Un-comment the #define DEBUG to compile in production or debug mode
 *		With DEBUG defined, several tests will be performed and the main 
 *		functionality will not.
 *		Individual testing can be selected by defining/not-defining certain
 *		tags; set "DEBUG Settings"
 *
 * ==========================================================================*/

/* ****************************************************************************
 * Standard Headers
 * ***************************************************************************/
#include <avr/io.h>

/* ****************************************************************************
 * DEBUG Settings
 * ***************************************************************************/

/*Comment this out to turn off debug*/
#define TEST_MODE 1

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
	continue;/*TODO*/
}


void main (void)
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

