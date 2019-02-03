#include <IR_Single.h>

IR_Single ir;
void setup() {
  // put your setup code here, to run once:
  ir.setIR(9,8);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  ir.p_updateIR();
}


/*
int val;

void setup() {
  // put your setup code here, to run once:
  pinMode(8,OUTPUT);
  pinMode(9,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  tone(8,38500,10);
  delay(1);
  val=digitalRead(9);
  delay(1);
  Serial.println(val);
  delay(100);
}
 */
