#ifndef HC04_h
#define HC04_h

#include <inttypes.h>

class HC04
{

private:
	unsigned int m_l_lastTime;
	unsigned int m_h_lastTime;
	uint8_t m_trigpin;
	uint8_t m_echopin;

public:
	unsigned long duration;
	double cm;
	
	HC04(void);//«Øºc
	~HC04();//¸Ñºc
	void set(uint8_t trigpin, uint8_t echopin, unsigned int l_lastTime, unsigned int h_lastTime);
	void update(void);

};

#endif