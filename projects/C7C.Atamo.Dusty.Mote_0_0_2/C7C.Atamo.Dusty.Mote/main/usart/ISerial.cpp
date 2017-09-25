/*
 * ISerial.cpp
 *
 * Created: 2017-09-26 01:40:54
 *  Author: kjph
 */ 


#include <HardwareSerial.h>

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

    //TODO: handle method overloading of different sizes
    Serial.write(c);
}

extern "C" int dp_usart_read(void)
{
    return Serial.read();
}