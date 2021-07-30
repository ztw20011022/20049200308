//C++  Code
#include <MsTimer2.h> 
volatile int pinInterrupt=2;
volatile int a = 1;
volatile int b= 1;
void xianshi()
{
  digitalWrite(10,LOW);
  a=0;
  b=0;
  digitalWrite(3,(byte(b)-'0')&0x1);
  digitalWrite(4,((byte(b)-'0')>>1)&0x1);
  digitalWrite(5,((byte(b)-'0')>>2)&0x1);
  digitalWrite(6,((byte(b)-'0')>>3)&0x1);
  digitalWrite(10,HIGH);
}
void Timer()      //时间显示器 
{
    if(b>=10)
  {
    b=0;
    digitalWrite(10,LOW);

    digitalWrite(3,(byte(a)-'0')&0x1);
    digitalWrite(4,((byte(a)-'0')>>1)&0x1);
    digitalWrite(5,((byte(a)-'0')>>2)&0x1);
    digitalWrite(6,((byte(a)-'0')>>3)&0x1);
    digitalWrite(10,HIGH);
    a++;        //十位计数
    if(a==10)
      a=0;
    
  }
  digitalWrite(3,(byte(b)-'0')&0x1);
  digitalWrite(4,((byte(b)-'0')>>1)&0x1);
  digitalWrite(5,((byte(b)-'0')>>2)&0x1);
  digitalWrite(6,((byte(b)-'0')>>3)&0x1);
  
  b++;           //个位计数

}
void setup()
{
  
  Serial.begin(9600); //初始化串口
  pinMode(2,INPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  digitalWrite(9,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  MsTimer2::set(1000,Timer);
  MsTimer2::start();
  attachInterrupt(digitalPinToInterrupt(pinInterrupt), xianshi,CHANGE);
  
}
void loop()
{}
