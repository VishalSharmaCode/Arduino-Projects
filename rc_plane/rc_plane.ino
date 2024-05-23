#include <Servo.h>

Servo servo_left;  // create servo object to control a servo
Servo servo_right;
int channel_1 = A0;
int channel_2 = A1;

void setup() {
  servo_left.attach(9);  // attaches the servo on pin 9 to the servo object
  servo_right.attach(10);
  pinMode(channel_1, INPUT);
}

void loop() {
  int angle = 0;   
  int value = pulseIn(channel_1, HIGH, 25000);
  int value2 = pulseIn(channel_2, HIGH);
   Serial.print(value);
   Serial.print("  ||  ");
  Serial.println(value2); 
  if(value==0 and value2==0)
  {
   servo_left.write(0);
   servo_right.write(0); 
  }
  else if(value2<1460)// Upward 
  {
    
  }
  else if()//Downward
  {
    
  }
  else if(value > 1530)//Right
  {
   angle = map(value, 1530, 2000, 20, 110);  
   servo_left.write(0);
   servo_right.write(90+angle);
  }
  else if(value<1460)//Left
  {
    angle = map(value, 1460, 900, 20,110);
  }
                  
  delay(10);                          
}
