#ifndef DUINOPRO_H
#define DUINOPRO_H

// #include <Arduino.h>
// #include <Pin.h>

#ifdef __cplusplus
 
class duinoPRO {
    private:
	
    protected:
    //    Pin *vbatSenseEnPin;
	//    Pin *vbatSensePin;
	
    public:
 	duinoPRO(void);
	
	void enableVbatSense(bool enable);
	float getVbat();
	
    void setLed(bool on);
	
	void uartUsbMode();
	void uartModule7Mode();
};


#endif

#endif /* DUINOPRO_H */