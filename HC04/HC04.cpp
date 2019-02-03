/*
***************�{����T***************
�}�o��:���x��
����:ver1.0
���:20190106
*/

// For Arduino 1.0 and earlier
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "HC04.h"

HC04::HC04(void)
{

}


void HC04::set(uint8_t trigpin, uint8_t echopin, unsigned int l_lastTime, unsigned int h_lastTime)
{
	m_trigpin = trigpin;
	m_echopin = echopin;
	m_l_lastTime = l_lastTime;
	m_h_lastTime = h_lastTime;	
		
	pinMode(m_trigpin, OUTPUT);
	pinMode(m_echopin, INPUT);
	
}

void HC04::update(void)
{
	digitalWrite(m_trigpin, LOW);
	delayMicroseconds(m_l_lastTime);
	digitalWrite(m_trigpin, HIGH);     // �� Trig ���q��A���� 10�L��
	delayMicroseconds(m_h_lastTime);
	digitalWrite(m_trigpin, LOW);

	HC04::duration = pulseIn(m_echopin, HIGH);   // ���찪�q��ɪ��ɶ�
	HC04::cm = (duration / 2) / 29.1;         // �N�ɶ����⦨�Z�� cm �� inch  1/29.1=0.034

	Serial.print("Distance : ");
	Serial.print(cm);
	Serial.print("cm");
	Serial.println();

	delay(250);
}

HC04::~HC04() 
{
  //�Ѻc��
}