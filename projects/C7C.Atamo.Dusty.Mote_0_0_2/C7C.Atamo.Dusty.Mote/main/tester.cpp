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

#if DP_BUILD__TCTRL_DPFRAMING
	#include "Testing/TestDpFraming.h"
#endif

#if DP_BUILD__TCTRL_DPSAMPLE
    #include "Testing/TestDpSample.h"
#endif

#if DP_BUILD__TCTRL_DPSAMPLE_DIAG
    #include "Testing/TestDpSampleDiagnostic.h"
#endif

#if DP_BUILD__TCTRL_DPSAMPLE_TIME
    #include "Testing/TestDpSampleTime.h"
#endif

#if DP_BUILD__TCTRL_DPSAMPLE_SENS
    #include "Testing/TestDpSampleSensor.h"
#endif

#if DP_BUILD__TCTRL_PORT
    #include "Testing/TestPort.h"
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

/*-----------------------------------*/
#if DP_BUILD__TCTRL_DPFRAMING
    TestDpFraming test_dp_framing;
    test_dp_framing.run();
#endif

/*-----------------------------------*/
#if DP_BUILD__TCTRL_DPSAMPLE
    TestDpSample test_dp_sample;
    test_dp_sample.run();
#endif

/*-----------------------------------*/
#if DP_BUILD__TCTRL_DPSAMPLE_DIAG
    TestDpSampleDiagnostic test_dp_sample_diag;
    test_dp_sample_diag.run();
#endif

/*-----------------------------------*/
#if DP_BUILD__TCTRL_DPSAMPLE_TIME
    TestDpSampleTime test_dp_sample_time;
    test_dp_sample_time.run();
#endif

/*-----------------------------------*/
#if DP_BUILD__TCTRL_DPSAMPLE_SENS
    TestDpSampleSensor test_dp_sample_sens;
    test_dp_sample_sens.run();
#endif

/*-----------------------------------*/
#if DP_BUILD__TCTRL_PORT
    TestPort test_port;
    test_port.run();
#endif
}