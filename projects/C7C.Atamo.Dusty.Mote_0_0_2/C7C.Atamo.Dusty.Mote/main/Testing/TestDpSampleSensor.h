/*============================================================================*/
/*!
 * @file TestDpSampleSensor.h
 *
 * @brief Test cases for framing routines
 *
 * @date 2017/10/16
 * @author Aaron Hurst
 *
 */
/*============================================================================*/

#ifndef TESTDPSAMPLESENSOR_H_
#define TESTDPSAMPLESENSOR_H_

#include "TestCase.h"

class TestDpSampleSensor: public TestCase {
	private:

	protected:

	public:
		TestDpSampleSensor(void);
		void run(void);
		void TU_SH_DpSampleSensor_op(void);
};

#endif /* TESTDPSAMPLESENSOR_H_ */