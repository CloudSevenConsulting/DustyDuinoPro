/* ============================================================================
 * C7C.Atamo.Dusty.Mote.Tester.tester.h
 * ------------------------------------
 *
 * -------
 * PURPOSE
 * -------
 *      Header for tester.c
 *
 * ------------------
 * DEVELOPMENT STATUS
 * ------------------
 *      Last Updated: 2017-09-04
 *      Last Editor: Phan, J.
 *
 *		Created.
 *
 * ----------------
 * ADDITIONAL NOTES
 * ----------------
 *
 *
 * ==========================================================================*/
#ifndef TESTER_H_
#define TESTER_H_

/* ****************************************************************************
 * FUNCTION: TestFail
 * ------------------
 * raise an alert to notify user that test failed! This function should
 * be called everytime a test fails
 * If the notification procedures needs to change, then only this function
 * needs to change
 * ***************************************************************************/
void TestFail(void);

/* ****************************************************************************
 * FUNCTION: tester
 * ----------------
 * Main routine for all testing function
 *
 * ***************************************************************************/
void tester(void);

#endif

