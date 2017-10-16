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

#ifndef TESTPORT_H_
#define TESTPORT_H_

#include "TestCase.h"

class TestPort: public TestCase {
private:

protected:

public:
    TestPort(void);
    void run(void);
};

#endif /* TESTPORT_H_ */