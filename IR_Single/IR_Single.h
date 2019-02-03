#include <inttypes.h>

class IR_Single
{
private:
	uint8_t IN;
	uint8_t OUT;
public:
	int VAL;
	void setIR(uint8_t in ,uint8_t out);
	void updateIR(void);
	void updateIR(int t);
	void p_updateIR(void);
	void p_updateIR(int t);
};