/* ============================================================================
 * C7C.Atamo.Dusty.Mote.Tester.memory
 * ----------------------------------
 *
 * -------
 * PURPOSE
 * -------
 *      RAM testing
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
 *
 * ==========================================================================*/
int test_data_bus(volatile int * address)
{
    int pattern;

    /*
     * Perform a walking 1's test at the given address.
     */
    for (pattern = 1; pattern != 0; pattern <<= 1)
    {
        /*
         * Write the test pattern.
         */
        *address = pattern;

        /*
         * Read it back (immediately is okay for this test).
         */
        if (*address != pattern) 
        {
            return (pattern);
        }
    }

    return 1;

    //TODO: This function
    //This function was taken from: https://barrgroup.com/Embedded-Systems/How-To/Memory-Test-Suite-C

}   /* memTestDataBus() */