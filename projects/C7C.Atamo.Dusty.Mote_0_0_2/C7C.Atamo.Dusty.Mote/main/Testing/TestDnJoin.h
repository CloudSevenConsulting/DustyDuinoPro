/*
 * test_dnJoin.h
 *
 * Created: 2017-09-26 22:42:39
 *  Author: kjph
 */ 


#ifndef TEST_DNJOIN_H_
#define TEST_DNJOIN_H_

#include "TestCase.h"

#define NETID			0		// Factory default value used if zero (1229)
#define JOINKEY			NULL	// Factory default value used if NULL (44 55 53 54 4E 45 54 57 4F 52 4B 53 52 4F 43 4B)
#define BANDWIDTH_MS	9000	// Not changed if zero (default base bandwidth given by manager is 9 s)
#define SRC_PORT		60000	// Default port used if zero (0xf0b8)

/*! Test if Mote can join to NM

    Attempts to connect to a network manager
    
    Simple. Todo: advance joining tests
*/
class TestDnJoin: public TestCase {
    private:

    protected:

    public:
        TestDnJoin(void);
        void run(void);
};

#endif /* TEST_DNJOIN_H_ */