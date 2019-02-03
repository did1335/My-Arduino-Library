/*
***************程式資訊***************
開發者:朱庭宏
版本:ver1.0
日期:20190203
*/


#include "BT_communication.h"

BT_communication::BT_communication(void)
{	
}


void BT_communication::commute()
{
	Serial.begin(9600);
	Serial.println("Baud:9600");
}


void BT_communication::commute(byte state)
{
	switch (state) {
	case 1:
		Serial.begin(9600);
		Serial.println("Baud:9600");
		break;
	case 2:
		Serial.begin(19200);
		Serial.println("Baud:19200");
		break;
	case 3:
		Serial.begin(38400);
		Serial.println("Baud:38400");
		break;
	case 4:
		Serial.begin(57600);
		Serial.println("Baud:57600");
		break;
	case 5:
		Serial.begin(115200);
		Serial.println("Baud:115200");
		break;
	case 6:
		Serial.begin(4800);
		Serial.println("Baud:4800");
		break;
	case 7:
		Serial.begin(2400);
		Serial.println("Baud:2400");
		break;
	case 8:
		Serial.begin(1200);
		Serial.println("Baud:1200");
		break;
	case 9:
		Serial.begin(300);
		Serial.println("Baud:300");
		break;


	default:
		Serial.begin(9600);
		Serial.println("Baud:9600");
		break;
	}
}


void BT_communication::set_step(int new_steps)
{
	BT_communication::steps = new_steps;
}


void BT_communication::set(uint8_t rxpin, uint8_t txpin, uint8_t lpin, uint8_t rpin)
{
	rx_pin = rxpin;
	tx_pin = txpin;
	l_pin = lpin;
	r_pin = rpin;

	pinMode(rx_pin, INPUT);
	pinMode(tx_pin, OUTPUT);
	pinMode(l_pin, OUTPUT);
	pinMode(r_pin, OUTPUT);
}

void BT_communication::set_speed(float left, float right)
{
	BT_communication::speed_l = left;
	BT_communication::speed_r = right;
}

void BT_communication::detect(void)
{
	if (Serial.available() > 0)
	{
		BT_communication::InWord = Serial.read();
		Serial.println(BT_communication::InWord);
	}
		
	switch (BT_communication::InWord)
	{
	case 'F':
		BT_communication::forward();
		Serial.println("forward");
		break;
	case 'B':
		BT_communication::back();
		Serial.println("back");
		break;
	case 'L':
		BT_communication::left();
		Serial.println("left");
		break;
	case 'R':
		BT_communication::right();
		Serial.println("right");
		break;	
	case 'V':
		BT_communication::version();
		break;
	}
	BT_communication::InWord = 0;
}

void BT_communication::forward()
{
	for (int i = 1; i <= BT_communication::steps; i++) {
		BT_communication::turn(l_pin, conv2(BT_communication::speed_l));
		BT_communication::turn(r_pin, conv1(BT_communication::speed_r));
	}
}

void BT_communication::back()
{
	for (int i = 1; i <= BT_communication::steps; i++) {
		BT_communication::turn(l_pin, conv1(BT_communication::speed_l));
		BT_communication::turn(r_pin, conv2(BT_communication::speed_r));
	}
}

void BT_communication::left()
{
	for (int i = 1; i <= BT_communication::steps; i++) {
		BT_communication::turn(l_pin, conv1(BT_communication::speed_l));
		BT_communication::turn(r_pin, conv1(BT_communication::speed_r));
	}
}

void BT_communication::right()
{
	for (int i = 1; i <= BT_communication::steps; i++) {
		BT_communication::turn(l_pin, conv2(BT_communication::speed_l));
		BT_communication::turn(r_pin, conv2(BT_communication::speed_r));
	}
}

void BT_communication::turn(int pin, int delaytime)
{
	digitalWrite(pin, 1);
	delayMicroseconds(delaytime);
	digitalWrite(pin, 0);
	delay(20);
}

int BT_communication::conv1(int s)
{
	int news = 1500 - (2.0*s);
	return news;
}

int BT_communication::conv2(int s)
{
	int news = 1500 + (2.0*s);
	return news;
}


void BT_communication::version()
{
	Serial.println("Version:1.0");
}



BT_communication::~BT_communication()
{
	//解構式
}