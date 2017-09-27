/*
 * ITime.h
 *
 * Created: 2017-09-26 02:14:58
 *  Author: kjph
 */ 


#ifndef ITIME_H_
#define ITIME_H_

#include <stdint.h>

void dp_delay(uint32_t);
uint32_t dp_time_now(void);
uint32_t time_now_dn(void);
uint32_t time_next_sample(void);
uint32_t time_until_next_sample(uint32_t);

#endif /* ITIME_H_ */