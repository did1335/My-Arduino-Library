#include <IR_Moudule.h>

IR_Moudule ir;

void setup()
{
  ir.set(8,100,9600);
}

void loop()
{
  ir.printir();
}

/*const int ir=8;
int state;

void setup() {
  // put your setup code here, to run once:
  pinMode(ir,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  state=digitalRead(ir);
  Serial.println(state);
  delay(100);
}*/
