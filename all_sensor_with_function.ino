
#include <OneWire.h>
#include <DallasTemperature.h>//for temperature sensor
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);  
DallasTemperature sensors(&oneWire);
const int trigPin1 = 7; //for ultra sensor one 
const int echoPin1 = 8; //for ultra sensor one
int duration1;   //for ultra sensor one
int distance1;   //for ultra sensor one
int x,y;
float TIME=0,FREQUENCY=0,WATER=0,TOTAL=0,LS=0;
const int flow=A0;
void setup()
{
sensors.begin();
pinMode(flow,0);
pinMode(A1,0);
pinMode(trigPin1, OUTPUT); 
pinMode(echoPin1, INPUT);
Serial.begin(9600);
}
void loop()
{
  ultra_sonic();
  temperature_sensor();
  flow_sensor();
  turbidity_sensor();
}
void ultra_sonic()
{
digitalWrite(trigPin1, LOW);
delay(1000);
digitalWrite(trigPin1, HIGH);
delayMicroseconds(2000);
digitalWrite(trigPin1, LOW);
duration1 = pulseIn(echoPin1, HIGH);
distance1= duration1*0.034/2;
Serial.print("Distance1: ");
Serial.println(distance1);
}
void temperature_sensor()
{
  sensors.requestTemperatures();
  Serial.print("Temperature: ");
  Serial.print(sensors.getTempCByIndex(0));
  Serial.print((char)176);
  Serial.print("C  |  ");//temperature in celcius
  Serial.println("C");
  delay(500);
}
void flow_sensor()
{
  x=pulseIn(flow,1);
  y=pulseIn(flow,0);
  TIME=x+y;
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
  delay(10000);
}
void turbidity_sensor()
  {
    int l=analogRead(A1);
    float p=l*(5.0/1024.0);
    Serial.println("Sensor Output(V):");
    Serial.println(p);
    delay(1000);
  }
