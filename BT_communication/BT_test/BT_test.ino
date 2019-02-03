#include <BT_communication.h>

BT_communication  BT;

void setup()
{
  BT.commute();
  BT.set_step(10);
  BT.set(0,1,10,11);  
}

void loop()
{
  BT.detect();
}


/*原始碼
int rx=0,tx=1;
int l=10,r=11;//左輪pin l,右輪pin r;
char InWord;
float speed_l=100,speed_r=100; //speed from 0 to 100 (unit:0.5)
int steps=20;//前進步數

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(rx,INPUT);
  pinMode(tx,OUTPUT);
  pinMode(l,OUTPUT);
  pinMode(r,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    InWord=Serial.read();
    Serial.println(InWord);    
  }
 
  switch(InWord)
  {
    case 'f':
      forward();
      break;
    case 'b':
      back();
      break;
    case 'l':
      left();
      break;
    case 'r':
      right();
      break;
  }
  InWord=0;
}

void forward()
{
  for (int i=1;i<=steps;i++){
  turn(l,conv2(speed_l));
  turn(r,conv1(speed_r));
  }
}

void back()
{
  for (int i=1;i<=steps;i++){
  turn(l,conv1(speed_l));
  turn(r,conv2(speed_r));
  }
}

void left()
{ 
  for (int i=1;i<=steps;i++){
  turn(l,conv1(speed_l));
  turn(r,conv1(speed_r));
  }
}

void right()
{
  for (int i=1;i<=steps;i++){
  turn(l,conv2(speed_l));
  turn(r,conv2(speed_r));
  }
}

void turn(int pin,int delaytime)
{
  digitalWrite(pin,1);
  delayMicroseconds(delaytime);
  digitalWrite(pin,0);
  delay(20);
}

int conv1(int s)
{
  int news=1500-(2.0*s);
  return news;
}

int conv2(int s)
{
  int news=1500+(2.0*s);
  return news;
}

void commute(byte state)
{
  switch (state) {
  case 1:
    Serial.begin(9600);
    Serial.println("9600");
    break;
  case 2:
    Serial.begin(19200);
    Serial.println("19200");
    break;
  case 3:
    Serial.begin(38400);
    Serial.println("38400");
    break;
  case 4:
    Serial.begin(57600);
    Serial.println("57600");
    break;
  case 5:
    Serial.begin(115200);
    Serial.println("115200");
    break;
  case 6:
    Serial.begin(4800);
    Serial.println("4800");
    break;
  case 7:
    Serial.begin(2400);
    Serial.println("2400");
    break;
  case 8:
    Serial.begin(1200);
    Serial.println("1200");
    break;
  case 9:
    Serial.begin(300);
    Serial.println("300");
    break;

  default:
    Serial.begin(9600);
    Serial.println("9600");
    break;
  }
}

*/
