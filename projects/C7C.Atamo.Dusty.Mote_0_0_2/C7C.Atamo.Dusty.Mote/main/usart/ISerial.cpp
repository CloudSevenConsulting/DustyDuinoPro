/*
 * ISerial.cpp
 *
 * Created: 2017-09-26 01:40:54
 *  Author: kjph
 */ 

#include <HardwareSerial.h>
#include <Arduino.h>
#include "usart_flow.h"

extern "C" void dp_usart_init(int baud_rate)
{
    Serial.begin(baud_rate);

    // De-assert all lines
    usart_mode4_flow(USART__DIRECTION_PN, USART__FLOWCTRL_DEASSERT);
    usart_mode4_flow(USART__DIRECTION_NP, USART__FLOWCTRL_DEASSERT);
    
}

extern "C" void dp_usart_end(void)
{
    Serial.end();
}

extern "C" void dp_usart_flush(void)
{
    usart_mode4_flow(USART__DIRECTION_PN, USART__FLOWCTRL_DEASSERT);
    Serial.flush();
}

extern "C" size_t dp_usart_write(uint8_t c)
{
    delay(1);
    usart_mode4_flow(USART__DIRECTION_PN, USART__FLOWCTRL_ASSERT);

    //If the line is not clear, wait until it is
    while (usart_cts_status())
    {  
        update_port_usart();
    }

    Serial.write(c);
    return sizeof(c);

}
