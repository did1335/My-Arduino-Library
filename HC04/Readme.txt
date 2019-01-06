本Arduino函式庫適用於HC04超音波

函式庫指令:
HC04 <物件>; //建立物件
void set(uint8_t trigpin, uint8_t echopin, unsigned int l_lastTime, unsigned int h_lastTime); //初始化物件
void update(void); //執行超音波掃描