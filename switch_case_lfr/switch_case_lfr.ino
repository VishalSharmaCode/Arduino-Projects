byte ir1=12;
byte ir2=13;
byte motor1=11;//right motor
byte motor2=10;//left motor
void setup()
{
  pinMode(ir1.INPUT);
  pinMode(ir2.INPUT);
  pinMode(motor1.OUTPUT);
  pinMode(motor2.OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  int x=digitalRead(ir1);//right sensor
  delay(10);
  
  int y=digitalRead(ir2);//left sensor
  delay(10);
  if(x==1&&y==1)//drive lfr straight
  {
    analogWrite(motor1,225);
    analogWrite(motor2,225);
  }
  else if(x==1&&y==0)//trun left
  {
    analogWrite(motor1,250);
    analogWrite(motor2,150);
  }
  else if(x==0&&y==1)//trun right
  {
    analogWrite(motor1,150);
    analogWrite(motor2,255);
  }
  else
  {
    analogWrite(motor1,0);
    analogWrite(motor2,0);
  }
}
