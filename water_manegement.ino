#include <OneWire.h>
#include <DallasTemperature.h>//for temperature sensor
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);  
DallasTemperature sensors(&oneWire);
void flow_sensor1();
void flow_sensor2();
void flow_sensor3();
void flow_sensor4();
void flow_sensor5();
void flow_sensor6();
void flow_sensor7();
void turbidity_sensor();
void temperature_sensor();
const int trigPin1 = 7; //for ultra sensor one 
const int echoPin1 = 8; //for ultra sensor one
const int trigPin2 = 9; //for ultra sensor two
const int echoPin2 = 10; //for ultra sensor two
int duration1;   //for ultra sensor one
int distance1;   //for ultra sensor one
int duration2;   //for ultra sensor two
int distance2;   //for ultra sensor two
int x,y,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,x7,y7;
float TIME=0,FREQUENCY=0,WATER=0,TOTAL=0,LS=0;
float TIME2=0,FREQUENCY2=0,WATER2=0,TOTAL2=0,LS2=0;
float TIME3=0,FREQUENCY3=0,WATER3=0,TOTAL3=0,LS3=0;
float TIME4=0,FREQUENCY4=0,WATER4=0,TOTAL4=0,LS4=0;
float TIME5=0,FREQUENCY5=0,WATER5=0,TOTAL5=0,LS5=0;
float TIME6=0,FREQUENCY6=0,WATER6=0,TOTAL6=0,LS6=0;
float TIME7=0,FREQUENCY7=0,WATER7=0,TOTAL7=0,LS7=0;
const int flow=A0,flow2=A1,flow3=A2,flow4=A3,flow5=A4,flow6=A5,flow7=A7;
void setup()
{
sensors.begin();
pinMode(flow,0);
pinMode(A0,0);
pinMode(flow2,0);
pinMode(A1,0);
pinMode(flow3,0);
pinMode(A2,0);
pinMode(flow4,0);
pinMode(A3,0);
pinMode(flow5,0);
pinMode(A4,0);
pinMode(flow6,0);
pinMode(A5,0);
pinMode(flow7,0);
pinMode(A7,0);
pinMode(trigPin1, OUTPUT); 
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT); 
pinMode(echoPin2, INPUT);
Serial.begin(9600);
}
void loop()
{
  ultra_sonic();
  temperature_sensor();
  flow_sensor1();
  flow_sensor2();
  flow_sensor3();
  flow_sensor4();
  flow_sensor5();
  flow_sensor6();
  flow_sensor7();
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
Serial.println("cm");
//second ultra sonic sensor
digitalWrite(trigPin2, LOW);
delay(1000);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(2000);
digitalWrite(trigPin2, LOW);
duration1 = pulseIn(echoPin2, HIGH);
distance1= duration2*0.034/2;
Serial.print("Distance2: ");
Serial.println(distance2);
Serial.println("cm");
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
void flow_sensor1()
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
void flow_sensor2()
{
  x=pulseIn(flow2,1);
  y=pulseIn(flow2,0);
  TIME2=x2+y2;
  FREQUENCY2=1000000/TIME2;
  WATER2=FREQUENCY2/7.5;
  LS2=WATER2/60;
  if(FREQUENCY2>=0)
  {
    if(isinf(FREQUENCY2))
    {
      Serial.println("VOL.2 :0.00");
      Serial.println("TOTAL:2= ");
      Serial.print(TOTAL2);
    }
    else
    {
      TOTAL2=TOTAL2+LS2;
      Serial.println(FREQUENCY2);
      Serial.println("Vol.2: ");
      Serial.print(WATER2);
      Serial.print(" L/M");
      Serial.println("TOTAL:2= ");
      Serial.print(TOTAL2);
      Serial.print(" L");
     }
  }
  delay(10000);
}
void flow_sensor3()
{
  x=pulseIn(flow3,1);
  y=pulseIn(flow3,0);
  TIME3=x3+y3;
  FREQUENCY3=1000000/TIME3;
  WATER3=FREQUENCY3/7.5;
  LS3=WATER3/60;
  if(FREQUENCY3>=0)
  {
    if(isinf(FREQUENCY3))
    {
      Serial.println("VOL.3 :0.00");
      Serial.println("TOTAL:3= ");
      Serial.print(TOTAL3);
    }
    else
    {
      TOTAL3=TOTAL3+LS3;
      Serial.println(FREQUENCY3);
      Serial.println("Vol.3: ");
      Serial.print(WATER3);
      Serial.print(" L/M");
      Serial.println("TOTAL:3= ");
      Serial.print(TOTAL3);
      Serial.print(" L");
     }
  }
  delay(10000);
}
void flow_sensor4()
{
  x=pulseIn(flow4,1);
  y=pulseIn(flow4,0);
  TIME4=x4+y4;
  FREQUENCY4=1000000/TIME4;
  WATER4=FREQUENCY4/7.5;
  LS4=WATER4/60;
  if(FREQUENCY4>=0)
  {
    if(isinf(FREQUENCY4))
    {
      Serial.println("VOL. 4:0.00");
      Serial.println("TOTAL:4= ");
      Serial.print(TOTAL4);
    }
    else
    {
      TOTAL4=TOTAL4+LS4;
      Serial.println(FREQUENCY4);
      Serial.println("Vol.4: ");
      Serial.print(WATER4);
      Serial.print(" L/M");
      Serial.println("TOTAL:4= ");
      Serial.print(TOTAL4);
      Serial.print(" L");
     }
  }
  delay(10000);
}
void flow_sensor5()
{
  x=pulseIn(flow5,1);
  y=pulseIn(flow5,0);
  TIME5=x5+y5;
  FREQUENCY5=1000000/TIME5;
  WATER5=FREQUENCY5/7.5;
  LS5=WATER5/60;
  if(FREQUENCY5>=0)
  {
    if(isinf(FREQUENCY5))
    {
      Serial.println("VOL.5:0.00");
      Serial.println("TOTAL:5=");
      Serial.print(TOTAL5);
    }
    else
    {
      TOTAL5=TOTAL5+LS5;
      Serial.println(FREQUENCY5);
      Serial.println("Vol.5: ");
      Serial.print(WATER5);
      Serial.print(" L/M");
      Serial.println("TOTAL:5=");
      Serial.print(TOTAL5);
      Serial.print(" L");
     }
  }
  delay(10000);
}
void flow_sensor6()
{
  x=pulseIn(flow6,1);
  y=pulseIn(flow6,0);
  TIME6=x6+y6;
  FREQUENCY6=1000000/TIME6;
  WATER6=FREQUENCY6/7.5;
  LS6=WATER6/60;
  if(FREQUENCY6>=0)
  {
    if(isinf(FREQUENCY6))
    {
      Serial.println("VOL.6 :0.00");
      Serial.println("TOTAL:6= ");
      Serial.print(TOTAL6);
    }
    else
    {
      TOTAL6=TOTAL6+LS6;
      Serial.println(FREQUENCY6);
      Serial.println("Vol.6: ");
      Serial.print(WATER6);
      Serial.print(" L/M");
      Serial.println("TOTAL:6= ");
      Serial.print(TOTAL6);
      Serial.print(" L");
     }
  }
  delay(10000);
}
void flow_sensor7()
{
  x=pulseIn(flow7,1);
  y=pulseIn(flow7,0);
  TIME7=x7+y7;
  FREQUENCY7=1000000/TIME7;
  WATER7=FREQUENCY7/7.5;
  LS7=WATER7/60;
  if(FREQUENCY7>=0)
  {
    if(isinf(FREQUENCY7))
    {
      Serial.println("VOL.7:0.00");
      Serial.println("TOTAL:7= ");
      Serial.print(TOTAL7);
    }
    else
    {
      TOTAL7=TOTAL7+LS7;
      Serial.println(FREQUENCY7);
      Serial.println("Vol.7: ");
      Serial.print(WATER7);
      Serial.print(" L/M");
      Serial.println("TOTAL:7= ");
      Serial.print(TOTAL7);
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
