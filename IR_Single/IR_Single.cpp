#include "Arduino.h"
#include "IR_Single.h"

void IR_Single::setIR(uint8_t in, uint8_t out){
	IN = in;
	OUT = out;

	pinMode(IN, INPUT);
	pinMode(OUT, OUTPUT);
}

void IR_Single::updateIR(void) {
	tone(OUT, 38500, 10);
	delay(1);
	IR_Single::VAL = digitalRead(IN);
	delay(1);
	delay(100);
}

void IR_Single::updateIR(int t) {
	tone(OUT, 38500, 10);
	delay(1);
	IR_Single::VAL = digitalRead(IN);
	delay(1);
	delay(t);
}

void IR_Single::p_updateIR(void) {
	tone(OUT,38500,10);
	delay(1);
	IR_Single::VAL = digitalRead(IN);
	delay(1);
	Serial.println(IR_Single::VAL);
	delay(100);
}

void IR_Single::p_updateIR(int t) {
	tone(OUT, 38500, 10);
	delay(1);
	IR_Single::VAL = digitalRead(IN);
	delay(1);
	Serial.println(IR_Single::VAL);
	delay(t);
}


