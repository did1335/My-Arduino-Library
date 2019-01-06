#include <HC04.h>

HC04 ultra;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ultra.set(12,11,5,10);//trigpin,echopin,lowtime,hightime
}

void loop() {
  // put your main code here, to run repeatedly:
  ultra.update();
}
