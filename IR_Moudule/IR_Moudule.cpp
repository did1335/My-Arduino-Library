/*
***************程式資訊***************
開發者:朱庭宏
版本:ver1.0
日期:20190106
*/

// For Arduino 1.0 and earlier
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "IR_Moudule.h"

IR_Moudule::IR_Moudule(void)
{
  //建構式
}



void IR_Moudule::set(uint8_t ir, unsigned int time)
{	
	ir_pin = ir;
	lastTime = time;
	
	pinMode(ir_pin, INPUT_PULLUP);
}

void IR_Moudule::set(uint8_t ir, unsigned int time, unsigned int baud)
{
	ir_pin = ir;
	lastTime = time;
	
	pinMode(ir_pin, INPUT_PULLUP);
	Serial.begin(baud);
}


void IR_Moudule::update(void)
{
	IR_Moudule::state = digitalRead(ir_pin);
	delay(lastTime);
}

void IR_Moudule::printir(void)
{
	IR_Moudule::state = digitalRead(ir_pin);
	Serial.println(IR_Moudule::state);
	delay(lastTime);
}


IR_Moudule::~IR_Moudule()
{
  //解構式
}