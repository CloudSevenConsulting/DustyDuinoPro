/*******************************************************************************
 * Build settings
 ******************************************************************************/
#define TEST_MODE 1

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

/* ****************************************************************************
 * SmartMesh QSL Includes
 * ***************************************************************************/
extern "C" {
	#include "sm_qsl/dn_qsl_api.h"
};

/* ****************************************************************************
 * DEBUG Includes
 * ***************************************************************************/
#if TEST_MODE
#include "Testing/tester.h"
tester SysTest;
#endif

/*******************************************************************************
 * System setup 
 ******************************************************************************/
void setup() 
{

	/*! Disable VBAT sense on INIT
	 * This prevent energy waste
	 */
	Board.enableVbatSense(false);

/*! Select UART TX/RX ties to AVR 
 * Serial debug mode (TEST_MODE) connects the AVR to USB
 * Serial module mode (!TEST_MODE) connects to module space 7
 */
#if TEST_MODE
	Board.uartUsbMode();
#else
	Board.uartModule7Mode();
#endif

}

/*******************************************************************************
 * Main 
 ******************************************************************************/
void loop() 
{

	setup();

#if TEST_MODE
	while(1)
	{
		SysTest.blink();
	}
#else
	while(1)
	{

	}
#endif
}
