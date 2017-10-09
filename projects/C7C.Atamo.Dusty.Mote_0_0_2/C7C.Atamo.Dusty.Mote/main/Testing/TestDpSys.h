/*============================================================================*/
/*!
 * @file TestDpUart.h
 *
 * @brief Test cases for SH/DP Uart
 *
 * @date 2017/10/01
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
        void TU_SH_DpSys_FlashBlink_Op(void);
};




#endif /* TESTDPSYS_H_ */