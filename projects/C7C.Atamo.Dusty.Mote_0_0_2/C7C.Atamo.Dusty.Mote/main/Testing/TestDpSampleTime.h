/*============================================================================*/
/*!
 * @file TestDpSampleTime.h
 *
 * @brief Test cases for sample_time routine
 *
 * @date 2017/10/19
 * @author Aaron Hurst
 * 
 */
/*============================================================================*/

#ifndef TESTDPSAMPLETIME_H_
#define TESTDPSAMPLETIME_H_

#include "TestCase.h"

class TestDpSampleTime: public TestCase {
	private:

	protected:

	public:
		TestDpSampleTime(void);
		void run(void);
		void TU_SH_DpSampleTime_op(void);
};


#endif /* TESTDPSAMPLETIME_H_ */