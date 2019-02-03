#pragma once

// For Arduino 1.0 and earlier
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include <inttypes.h>

	class BT_communication
	{

	private:
		uint8_t rx_pin;
		uint8_t tx_pin;
		uint8_t l_pin;
		uint8_t r_pin;

	public:
		char InWord;
		float speed_l = 100, speed_r = 100; //speed from 0 to 100 (unit:0.5)
		int steps = 10;

		BT_communication(void);//«Øºc
		~BT_communication();//¸Ñºc

		void commute(void);
		void commute(byte state);

		void set_speed(float left, float right);
		void set_step(int new_steps);
		void set(uint8_t rxpin, uint8_t txpin, uint8_t lpin, uint8_t rpin);
		void detect(void);

		void forward();
		void back();
		void left();
		void right();

		void turn(int pin, int delaytime);
		int conv1(int s);
		int conv2(int s);

		void version(void);
	};
