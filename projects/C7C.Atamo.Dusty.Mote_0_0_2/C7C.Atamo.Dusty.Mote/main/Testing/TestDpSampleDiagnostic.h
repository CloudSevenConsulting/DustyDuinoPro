/*============================================================================*/
/*!
 * @file TestDpSampleDiagnostic.h
 *
 * @brief Test cases for sample_diagnostic function
 * 
 * Tests business as usual (BAU) operation of this function.
 * 
 * Note that any further tests of this function would require integration testing
 * since it is dependent on other functions.
 * 
 * @date 2017/10/16
 * @author Aaron Hurst
 *
 */
/*============================================================================*/

#ifndef TESTDPSAMPLEDIAGNOSTIC_H_
#define TESTDPSAMPLEDIAGNOSTIC_H_

#include "TestCase.h"

class TestDpSampleDiagnostic: public TestCase {
	private:

	protected:

	public:
		TestDpSampleDiagnostic(void);
		void run(void);
		void TU_SH_DpSampleDiagnostic_op(void);
};


#endif /* TESTDPSAMPLEDIAGNOSTIC_H_ */