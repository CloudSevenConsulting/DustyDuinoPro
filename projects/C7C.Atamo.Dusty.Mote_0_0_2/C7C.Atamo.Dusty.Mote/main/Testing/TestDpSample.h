/*============================================================================*/
/*!
 * @file TestDpSample.h
 *
 * @brief Test cases for framing routines
 *
 * @date 2017/10/16
 * @author Aaron Hurst
 *
 */
/*============================================================================*/

#ifndef TESTDPSAMPLE_H_
#define TESTDPSAMPLE_H_

#include "TestCase.h"

class TestDpSample: public TestCase {
	private:

	protected:

	public:
		TestDpSample(void);
		void run(void);
		void TU_SH_DpSample_op(void);
};

#endif /* TESTDPSAMPLE_H_ */