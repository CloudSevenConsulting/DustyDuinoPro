/*============================================================================*/
/*!
 * @file TestCase.h
 *
 * @brief Unit Test DP system
 *
 * Test DP system
 *
 * @date 2017/10/02
 * @author Jamie K. Phan
 *
 */
/*============================================================================*/

#ifndef TESTDPSYS_H_
#define TESTDPSYS_H_
 
#include "TestCase.h"

class TestDpSys: public TestCase {
    private:

    protected:

    public:
        TestDpSys(void);
        void run(void);

        //=====================================
		/*! Simple test to see build/flash works

			DP should simply blink. No connections
		*/
        void TU_SH_DPSys_FlashBlink_Op(void);
};

#endif /* TESTDPSYS_H_ */