#include<SoftwareSerial.h>
SoftwareSerial bt(2,3);
int in1=6;
int in2=9;
//int enA=11;
int in3=10;
int in4=11;
//int enB=10;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
  bt.begin(9600);
 pinMode(in1,OUTPUT);
 pinMode(in2,OUTPUT);
// pinMode(enA,OUTPUT);
 pinMode(in3,OUTPUT);
 pinMode(in4,OUTPUT);
// pinMode(enB,OUTPUT);
}

void loop() {
    if (bt.available()) /* If data is available on serial port */
    {
     char n=(bt.read()); /* Print character received on to the serial monitor */
     Serial.println(n);
     if( n=='F'){
   forward();
     }
     else if(n=='B')
     {
      backward();
      
     }
     else if(n=='L'){
      left();
     }
     else if(n=='R'){
      right();
     }
     else if(n=='S'){
        stopr();
    }
    else if(n=='G'){
      f_left();
    }
    else if(n=='I')
    {
      f_right();
    }
    else if(n=='H')
    {
      b_left();
    }
    else if(n=='J')
    {
      b_right();
    }
}}
void forward(){
     digitalWrite(in1,HIGH);
 digitalWrite(in2,LOW);
// analogWrite(enA,250);
  digitalWrite(in3,HIGH);
 digitalWrite(in4,LOW);
// analogWrite(enB,250);
}
void backward(){
  digitalWrite(in1,LOW);
 digitalWrite(in2,HIGH);
// analogWrite(enA,250);
  digitalWrite(in3,LOW);
 digitalWrite(in4,HIGH);
// analogWrite(enB,250);
}
void stopr(){
   digitalWrite(in1,LOW);
 digitalWrite(in2,LOW);
// analogWrite(enA,0);
  digitalWrite(in3,LOW);
 digitalWrite(in4,LOW);
// analogWrite(enB,0);
}

void right(){
   digitalWrite(in1,LOW);
 digitalWrite(in2,HIGH);
// analogWrite(enA,250);
  digitalWrite(in3,HIGH);
 digitalWrite(in4,LOW);
// analogWrite(enB,250);
}
void left(){
   digitalWrite(in1,HIGH);
 digitalWrite(in2,LOW);
// analogWrite(enA,250);
  digitalWrite(in3,LOW);
 digitalWrite(in4,HIGH);
// analogWrite(enB,250);
}

void f_right(){
  digitalWrite(in1,HIGH);
 digitalWrite(in2,LOW);
// analogWrite(enA,150);
  digitalWrite(in3,HIGH);
 digitalWrite(in4,LOW);
// analogWrite(enB,250);
}
void f_left(){
  digitalWrite(in1,HIGH);
 digitalWrite(in2,LOW);
// analogWrite(enA,250);
  digitalWrite(in3,HIGH);
 digitalWrite(in4,LOW);
// analogWrite(enB,150);
}
void b_right(){
  digitalWrite(in1,LOW);
 digitalWrite(in2,HIGH);
// analogWrite(enA,100);
  digitalWrite(in3,LOW);
 digitalWrite(in4,HIGH);
// analogWrite(enB,250);
}
void b_left(){
  digitalWrite(in1,LOW);
 digitalWrite(in2,HIGH);
// analogWrite(enA,250);
  digitalWrite(in3,LOW);
 digitalWrite(in4,HIGH);
// analogWrite(enB,100);
}
