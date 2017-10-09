/*
 * tester.cpp
 *
 * Created: 2017-09-26 23:03:16
 *  Author: kjph
 */ 

#include "tester.h"

/*******************************************************************************
 * TEST CONTROL 
 ******************************************************************************/
#if DP_BUILD__TCTRL_DPSYS
    #include "Testing/TestDpSys.h"
#endif

 #if DP_BUILD__TCTRL_DNJOIN
    #include "Testing/TestDnJoin.h"
#endif

#if DP_BUILD__TCTRL_DPUART
    #include "Testing/TestDpUart.h"
#endif

/*******************************************************************************
 * TEST ROUTINE 
 ******************************************************************************/
void do_system_test(void)
{

/*-----------------------------------*/
#if DP_BUILD__TCTRL_DPSYS
    TestDpSys test_dp_sys;
    test_dp_sys.run();
#endif

/*-----------------------------------*/
#if DP_BUILD__TCTRL_DNJOIN
    TestDnJoin test_dn_join;
    test_dn_join.run();
#endif

/*-----------------------------------*/
#if DP_BUILD__TCTRL_DPUART
    TestDpUart test_dp_uart;
    test_dp_uart.run();
#endif
}