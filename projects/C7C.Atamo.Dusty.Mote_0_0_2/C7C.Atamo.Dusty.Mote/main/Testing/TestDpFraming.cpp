/*
 * TestDpFraming.cpp
 *
 * Created: 16/10/2017 4:32:03 PM
 *  Author: Aaron Hurst
 */ 

#include <stdint.h>
#include <stddef.h>

#include "TestDpFraming.h"
#include "../sample/frame.h"
#include "../globals.h"


#define FRAMING_FAIL 255

TestDpFraming::TestDpFraming(void)
{
};

void TestDpFraming::run(void)
{
    TU_SH_DpFraming_op();
}

void TestDpFraming::TU_SH_DpFraming_op(void)
{
    uint8_t ret = 0;
    uint8_t buf = 0;
    uint8_t ptr = 0;

    /*******************************************************************************
     * Test pack_field_header
     ******************************************************************************/
    /*type*/
    ret = pack_field_header(-1, 6, &buf);
    if (ret != 255) {
        t_fail();
    }
    ret = pack_field_header(3, 6, &buf);
    if (ret != 255) {
        t_fail();
    }

    /*len*/
    ret = pack_field_header(1, -1, &buf);
    if (ret != 255) {
        t_fail();
    }
    ret = pack_field_header(1, 0, &buf);
    if (ret != 255) {
        t_fail();
    }
    ret = pack_field_header(1, 13, &buf);
    if (ret != 255) {
        t_fail();
    }

    /*pointer*/
    ret = pack_field_header(1, 6, NULL);
    if (ret != 255) {
        t_fail();
    }

    /*Invalid types*/
    ret = pack_field_header('a', 6, &buf);
    if (ret != 255) {
        t_fail();
    }
    ret = pack_field_header(1,'a', &buf);
    if (ret != 255) {
        t_fail();
    }

    /*BAU*/
    ret = pack_field_header(0, 6, &buf);
    if (ret != 1 || buf != 0b01111111) {
        t_fail();        
    }
    ret = pack_field_header(1, 6, &buf);
    if (ret != 1 || buf != (0b01100001 | SystemState._sensor_type)) {
        t_fail();
    }
    ret = pack_field_header(2, 6, &buf);
    if (ret != 1 || buf != 0b01111110) {
        t_fail();
    }
    ret = pack_field_header(0, 2, &buf);
    if (ret != 1 || buf != 0b00111111) {
        t_fail();
    }
    ret = pack_field_header(0, 12, &buf);
    if (ret != 1 || buf != 0b11011111) {
        t_fail();
    }

    /*******************************************************************************
     * Test reserve_field
     ******************************************************************************/
    /*type*/
    ret = reserve_field(-1, 6, &ptr, &buf);
    if (ret != 255) {
        t_fail();
    }
    ret = reserve_field(3, 6, &ptr, &buf);
    if (ret != 255) {
        t_fail();
    }

    /*len*/
    ret = reserve_field(3, -1, &ptr, &buf);
    if (ret != 255) {
        t_fail();
    }
    ret = reserve_field(3, 0, &ptr, &buf);
    if (ret != 255) {
        t_fail();
    }
    ret = reserve_field(3, 13, &ptr, &buf);
    if (ret != 255) {
        t_fail();
    }

     /*pointer*/
     ret = reserve_field(3, 13, &ptr, NULL);
     if (ret != 255) {
         t_fail();
     }
 
     /*Invalid types*/
     ret = reserve_field('a', 6, &ptr, &buf);
     if (ret != 255) {
         t_fail();
     }
     ret = reserve_field(1,'a', &ptr, &buf);
     if (ret != 255) {
         t_fail();
     }
 
     /*BAU*/
     ptr = 0;
     buf = 0;
     ret = reserve_field(0, 6, &ptr, &buf);
     if (ret != 1 || ptr != 7 || buf != 0b01111111) {
        t_fail();
    }
     
     ptr = 0;
     buf = 0;
     ret = reserve_field(1, 6, &ptr, &buf);
     if (ret != 1 || ptr != 7 || buf != (0b01100001 | SystemState._sensor_type)) {
        t_fail();
     }
     
     ptr = 0;
     buf = 0;
     ret = reserve_field(2, 6, &ptr, &buf);
     if (ret != 1 || ptr != 7 || buf != 0b01111110) {
         t_fail();
     }
 
     ptr = 0;
     buf = 0;
     ret = reserve_field(0, 2, &ptr, &buf);
     if (ret != 1 || ptr != 3 || buf != 0b00111111) {
         t_fail();
     }
 
     ptr = 0;
     buf = 0;
     ret = reserve_field(0, 12, &ptr, &buf);
     if (ret != 1 || ptr != 13 || buf != 0b11011111) {
         t_fail();
     }
 
     /*******************************************************************************
     * Test endpoint: no failures
     ******************************************************************************/
     t_pass();
}