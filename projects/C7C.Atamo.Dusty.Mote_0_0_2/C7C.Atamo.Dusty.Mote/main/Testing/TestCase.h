/*============================================================================*/
/*!
 * @file TestCase.h
 *
 * @brief Unit Test Base Class
 *
 * This base class provides a unit testing module. Unit tests should derive from
 * this base class and use the exposed functions to perform testing
 * Testing must then be integrated to the tester.h module in the TLD
 *
 * @date 2017/10/01
 * @author Jamie K. Phan
 *
 */
/*============================================================================*/

#ifndef TESTCASE_H_
#define TESTCASE_H_

class TestCase {
	public:
		
		//=====================================
		/*! TestCase base class for unit-testing in Embedded App

			This is the base class in which other unit-tests should derive from.
			This class guarantees the methods run, t_fail, t_pass.
		*/
		TestCase(void);

		//=====================================
		/*! Allows tester to specify if successful tests should hold the device
		*/
		bool tctrl_stop_on_success;

		//=====================================
		/*! Simple blink procedure for visual feedback on the DP
		*/
		void blink(void);

		//=====================================
		/*! Entry point for test cases
		*/
		virtual void run(void);

		//=====================================
		/*! Standardised routine for failures.

			This routine holds on a while(1) with visual feedback
		*/
		void t_fail(void);

		//=====================================
		/*! Standardised routine for passes

			This routine has the option to pass on success using
			the attribute (tctrl_stop_on_success)
		*/
		void t_pass(void);

	private:
		
	protected:
};

#endif /* TESTCASE_H_ */