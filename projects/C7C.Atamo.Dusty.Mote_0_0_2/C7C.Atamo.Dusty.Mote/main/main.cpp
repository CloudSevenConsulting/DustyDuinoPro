﻿/*******************************************************************************
 * Build settings
 ******************************************************************************/
#define DP_BUILD__TEST_MODE 0
#define DP_BUILD__UART_USB_MODE 0

/*******************************************************************************
 * Arduino Libraries
 ******************************************************************************/
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <duinoPRO.h>

/*******************************************************************************
 * Globals
 ******************************************************************************/
#include "globals.h"
duinoPRO Board;/*This is public globally in globals.h*/

/*******************************************************************************
 * Core
 ******************************************************************************/
#include "port.h"
#include "dp_sm.h"
#include "dp_conf.h"
#include "sample/sensor.h"

/* ****************************************************************************
 * SmartMesh QSL Includes
 * ***************************************************************************/
extern "C" {
	#include "sm_qsl/dn_qsl_api.h"
};

/* ****************************************************************************
 * DEBUG Includes
 * ***************************************************************************/
#if DP_BUILD__TEST_MODE
	#include "tester.h"
#endif

/*******************************************************************************
 * System setup 
 ******************************************************************************/
void setup() 
{

	dp_state_init();
	dp_conf_default();

	/*! Disable VBAT sense on INIT
	 * This prevent energy waste
	 */
	 Board.enableVbatSense(false);

/*! Select UART TX/RX ties to AVR 
 * Serial debug mode (TEST_MODE) connects the AVR to USB
 * Serial module mode (!TEST_MODE) connects to module space 7
 */
#if DP_BUILD__UART_USB_MODE
	Board.uartUsbMode();
#else
	Board.uartModule7Mode();
#endif
	
/*! Production specific build environment
 * Tests should setup their own environments to ensure controlled testing
 */
 #if !DP_BUILD__TEST_MODE
	port_init();
	dn_qsl_init();
 #endif

}

/*******************************************************************************
 * Main 
 ******************************************************************************/
void loop() 
{

	setup();

	uint8_t buf[3] = {0x01, 0x02, 0x04};

#if DP_BUILD__TEST_MODE
	do_system_test();
#else
	while(1)
	{
		if(dn_qsl_isConnected())
		{
			while(1)
			{
				delay(500);
				Board.setLed(true);
				dn_qsl_send(buf, sizeof(buf), 0);
				delay(500);
				Board.setLed(false);
			}
		}
		else
		{
			Board.setLed(true);
			if (dn_qsl_connect(25, NULL, 0, 0))//Default values
			{
			} else
			{
				Board.setLed(false);
			}
		}
	}
#endif
}
