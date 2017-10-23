/*============================================================================*/
/*!
 * @file TestDpFraming.h
 *
 * @brief Test cases for framing routines
 *
 * @date 2017/10/16
 * @author Aaron Hurst
 *
 */
/*============================================================================*/

#ifndef TESTDPFRAMING_H_
#define TESTDPFRAMING_H_

#include "TestCase.h"

class TestDpFraming: public TestCase {
    private:

    protected:

    public:
        TestDpFraming(void);
        void run(void);
        void TU_SH_DpFraming_op(void);
};


#endif /* TESTDPFRAMING_H_ */