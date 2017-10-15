/*
 * ISerial.cpp
 *
 * Created: 2017-09-26 01:40:54
 *  Author: kjph
 */ 

#include <HardwareSerial.h>
#include "usart_vars.h"
#include "usart_flow.h"

dn_uart_vars_t dn_uart_vars;

extern "C" void dp_usart_init(int baud_rate)
{
    Serial.begin(baud_rate);
}

extern "C" void dp_usart_end(void)
{
    Serial.end();
}

extern "C" void dp_usart_flush(void)
{
    Serial.flush();
}

extern "C" size_t dp_usart_write(uint8_t c)
{

    // Flow control not required for DN's RX line in Mode 4

    //TODO: handle method overloading of different sizes
    Serial.write(c);

    return sizeof(c);//TODO: check this
}

extern "C" int dp_usart_read(void)
{
    return Serial.read();
}

extern "C" void dp_usart_mode4_flow(int direction, int flow)
{
    usart_mode4_flow(direction, flow);
}

