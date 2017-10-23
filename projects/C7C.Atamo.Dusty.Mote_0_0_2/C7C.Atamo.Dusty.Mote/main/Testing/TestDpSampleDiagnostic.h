/*============================================================================*/
/*!
 * @file TestDpSampleDiagnostic.h
 *
 * @brief Test cases for framing routines
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