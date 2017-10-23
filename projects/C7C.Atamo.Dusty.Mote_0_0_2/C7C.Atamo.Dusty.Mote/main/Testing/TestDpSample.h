/*============================================================================*/
/*!
 * @file TestDpSample.h
 *
 * @brief Test cases for main sample function
 * 
 * Tests sample for each business as usual case with dummy timestamp, sensor 
 * data and battery voltage (diagnostic data). The dummy values are hard-coded
 * into the dn_time_ms, sensor_read and sample_diagnostic functions, 
 * respectively.
 * 
 * Each business as usual (BAU) case is tested, as well as some input
 * validation cases.
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