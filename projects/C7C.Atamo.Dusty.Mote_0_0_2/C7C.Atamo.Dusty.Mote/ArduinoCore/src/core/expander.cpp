#include <expander.h>
#include <../../libraries/Wire/Wire.h>
#include <pins_arduino.h>

#define EXPANDER_I2C_ADDR 0x20
#define expanderPinToConfigId(p)    (((p) & 0x7F) - 1)

void expanderPinMode(uint8_t pin, uint8_t mode)
{
    uint8_t modeCode;
	uint8_t pin_id;
    
	Serial.println("In expanderPinMode()");
    pin_id = expanderPinToConfigId(pin);
	
	Serial.print("  pin_id = ");
	Serial.println(pin_id);	
    
    if (mode==OUTPUT) 
    {
        modeCode = 0;
    }
    else
    {
        modeCode = 1;
    }
    //address the pin
    Wire.beginTransmission(EXPANDER_I2C_ADDR);
    Wire.write(0x18 + pin_id / 8);
    Wire.endTransmission();
    //read in current value
    Wire.requestFrom(EXPANDER_I2C_ADDR, 1);
    uint8_t old_value = Wire.read();
    //adjust to new value
    bitWrite(old_value, pin_id % 8, modeCode);
    //write out over I2C
    Wire.beginTransmission(EXPANDER_I2C_ADDR);
    Wire.write(0x18 + pin_id / 8);
    Wire.write(old_value);
    Wire.endTransmission();
}

void expanderWrite(uint8_t pin, uint8_t val)
{
	Serial.println("In expanderWrite()");

	uint8_t pin_id;
    pin_id = expanderPinToConfigId(pin);
	
	Serial.print("  pin_id = ");
	Serial.println(pin_id);	
	
    //address the pin
    Wire.beginTransmission(EXPANDER_I2C_ADDR);
    Wire.write(0x08 + pin_id / 8);
    Wire.endTransmission();
    //read in current value
    Wire.requestFrom(EXPANDER_I2C_ADDR, 1);
    uint8_t old_value = Wire.read();
    //adjust to new value
    bitWrite(old_value, pin_id % 8, val);
    //write out over I2C
    Wire.beginTransmission(EXPANDER_I2C_ADDR);
    Wire.write(0x08 + pin_id / 8);
    Wire.write(old_value);
    Wire.endTransmission();
}

int expanderRead(uint8_t pin)
{   
	uint8_t pin_id;
    pin_id = expanderPinToConfigId(pin);
	
	//address the pin
    Wire.beginTransmission(EXPANDER_I2C_ADDR);
    Wire.write(0x00 + pin_id / 8);
    Wire.endTransmission();
    //read in current value
    Wire.requestFrom(EXPANDER_I2C_ADDR, 1);
    return bitRead(Wire.read(), pin_id % 8);
}

