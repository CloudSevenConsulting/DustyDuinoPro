/* ============================================================================
 * C7C.Atamo.Dusty.Mote.Tester.tester.c
 * ------------------------------------
 *
 * -------
 * PURPOSE
 * -------
 *      Main routine for running all tests
 *
 * ------------------
 * DEVELOPMENT STATUS
 * ------------------
 *      Last Updated: 2017-09-04
 *      Last Editor: Phan, J.
 *
 *      Created
 *
 * ----------------
 * ADDITIONAL NOTES
 * ----------------
 *      Setting the #defines to 1 in the 'Test Selection' section will enable
 *      the test routines in build. Setting them to 0 will result in the pre-
 *      -processor ignoring the test block and not building them.
 *
 * ----
 * TODO
 * ----
 *      - TestFail() routine should have better reporting
 *      - consider a TestPass() routine
 *
 * ==========================================================================*/
#include "tester.h"

/* ****************************************************************************
 * Test Selection
 * ***************************************************************************/
#define TEST_MEMORY_ENABLE 0

/* ****************************************************************************
 * Test Headers
 * ***************************************************************************/
#if TEST_MEMORY_ENABLE
#include "memory.h"
#endif

/* ****************************************************************************
 * FUNCTION: TestFail
 * ------------------
 * raise an alert to notify user that test failed!
 * ***************************************************************************/
void TestFail(void)
{
    while(1)
    {
        /*Poll here to indiciate failure*/
    }

    /*TODO: more elaborate reporting*/
}

/* ****************************************************************************
 * FUNCTION: tester
 * ----------------
 * Main routine for all testing function
 *
 * ***************************************************************************/
void tester(void)
{

	int ret;

#if TEST_MEMORY_ENABLE
	ret = test_data_bus();/*TODO: Memory testing check*/
	if (ret)
	{
		TestFail();
	}
#endif/*TEST_MEMORY*/
}

