/*
 * tester.h
 *
 * Created: 2017-09-21 08:31:48
 *  Author: kjph
 */ 


#ifndef TESTCASE_H_
#define TESTCASE_H_

/*! TestCase base class for unit-testing in Embedded App

	This is the base class in which other unit-tests should derive from.
	This class guarantees the methods run, t_fail, t_pass.
*/
class TestCase {
	private:

	protected:

	public:
		bool tctrl_stop_on_success;

		TestCase(void);

		/*! Simple blink procedure for visual feedback on the DP
		*/
		void blink(void);

		/*! Entry point for test cases
		*/
		virtual void run(void);

		/*! Standardised routine for failures.

			This routine holds on a while(1) with visual feedback
		*/
		void t_fail(void);

		/*! Standardised routine for passes

			This routine has the option to pass on success using
			the attribute (tctrl_stop_on_success)
		*/
		void t_pass(void);
};

#endif /* TESTCASE_H_ */