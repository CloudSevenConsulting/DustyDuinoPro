/*
 * ISerial.h
 *
 * Created: 2017-09-26 01:43:07
 *  Author: kjph
 */ 


#ifndef ISERIAL_H_
#define ISERIAL_H_

void dp_usart_init(int);
void dp_usart_end(void);
void dp_usart_flush(void);
size_t dp_usart_write(uint8_t);
int dp_usart_read(void);



#endif /* ISERIAL_H_ */