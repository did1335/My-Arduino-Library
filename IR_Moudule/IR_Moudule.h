#include <inttypes.h>

class IR_Moudule
{

private:
	unsigned int lastTime;
	uint8_t ir_pin;

public:
	unsigned int state;
	
	IR_Moudule(void);//�غc
	~IR_Moudule();//�Ѻc
	void set(uint8_t ir,unsigned int time);
	void set(uint8_t ir, unsigned int time, unsigned int baud);
	void update(void);
	void printir(void);

};

