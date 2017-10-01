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

#ifndef TESTDPUART_H_
#define TESTDPUART_H_

#include "TestCase.h"

class TestDpUart: public TestCase {
private:

protected:

public:
    TestDpUart(void);
    void run(void);
    void TU_SH_DpUart_external_op(void);
};




#endif /* TESTDPUART_H_ */