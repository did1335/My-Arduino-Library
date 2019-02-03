/*可透過本程式利用手機等藍芽裝置來控制自走車*/

函式庫指令:
BT_communication <物件>; //建立物件
void commute(); //預設Baud Rate為9600
void set(uint8_t rxpin, uint8_t txpin, uint8_t lpin, uint8_t rpin); //RX腳,TX腳,左輪PIN,右輪PIN
