int joyX=A0;
int joyY=A1;

void setup()
{
pinMode(joyX,INPUT);
pinMode(joyY,INPUT);
Serial.begin(9600);
}
void loop()
{
  int x=analogRead(joyX);
  int y=analogRead(joyY);
  x=map(x,0,1021,0,255);
  y=map(y,0,1021,0,255);
  //Serial.print("x=""y=");
  Serial.println(x);
  if(x >= 125 || x<=126)
  {
    Serial.println("Center");
  }
  if(x > 126)
  {
    Serial.println("Forward");
  }
  if(x < 125 )
  {
    Serial.println("Backward");
  }
  delay(100);
}