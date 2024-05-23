#include <OneWire.h>
#include <DallasTemperature.h>//for temperature sensor
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);  
DallasTemperature sensors(&oneWire);
const int trigPin1 = 7;//for ultra sensor one 
const int echoPin1 = 8;//for ultra sensor one
const int trigPin2 = 9;//for ultra sensor two
const int echoPin2 = 10;//for ultra sensor two

long duration1,duration2;//for ultra sensor one
int distance1, distance2;//for ultra sensor two
int x,y,z,a,b,c,d,e,f,g;//for fllow sensor
float TIME=0,FREQUENCY=0,WATER=0,TOTAL=0,LS=0;
const int flow=A0, flow2=A1,flow3=A3, flow4=A4, flow5=A5;
void setup() 
{
  sensors.begin();
pinMode(trigPin1, OUTPUT); 
pinMode(echoPin1, INPUT); 
pinMode(trigPin2, OUTPUT); 
pinMode(echoPin2, INPUT);
pinMode(flow,0);
pinMode(flow2,0);
pinMode(flow3,0);
pinMode(flow4,0);
pinMode(flow5,0);
  Serial.begin(9600); 
}
void loop() 
{
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
duration1 = pulseIn(echoPin1, HIGH);
distance1= duration1*0.034/2;
Serial.print("Distance1: ");
Serial.println(distance1);//for ultra sensor one
digitalWrite(trigPin2, LOW);//for ultra sensor two
delayMicroseconds(2);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
duration2 = pulseIn(echoPin2, HIGH);
distance2= duration2*0.034/2;
Serial.print("Distance2: ");
Serial.println(distance2);
if(distance2 >= 20)
  d=pulseIn(flow4,1);
  e=pulseIn(flow4,0);
  TIME=d+e;
  f=pulseIn(flow5,1);
  g=pulseIn(flow5,0);
  TIME=f+g;
if(distance1 >= 10)
 x=pulseIn(flow,1);
  y=pulseIn(flow,0);
  TIME=x+y;
  z=pulseIn(flow2,1);
  a=pulseIn(flow2,0);
  TIME=z+a;
  b=pulseIn(flow3,1);
  c=pulseIn(flow3,0);
  TIME=b+c;
  
  FREQUENCY=1000000/TIME;
  WATER=FREQUENCY/7.5;
  LS=WATER/60;
  if(FREQUENCY>=0)
  {
    if(isinf(FREQUENCY))
    {
      Serial.println("VOL. :0.00");
      Serial.println("TOTAL: ");
      Serial.print(TOTAL);
    }
    else
    {
      TOTAL=TOTAL+LS;
      Serial.println(FREQUENCY);
      Serial.println("Vol.: ");
      Serial.print(WATER);
      Serial.print(" L/M");
      Serial.println("TOTAL: ");
      Serial.print(TOTAL);
      Serial.print(" L");
      }
  }
delay(1000);
sensors.requestTemperatures();
  Serial.print("Temperature: ");
  Serial.print(sensors.getTempCByIndex(0));
  Serial.print((char)176);
  Serial.print("C  |  ");//temperature in celcius
  Serial.println("C");
 
  delay(500);
}
