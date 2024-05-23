#define IR_sensor1Pin A1
#define IR_sensor2Pin A2

int trig_Pin=1;
int echo_Pin=2;

int IR_sensor1Pin_value;
int IR_sensor2Pin_value;
int time;
int distance;
String values;
String get_distance_Value();

void setup()
{
  pinMode(trig_Pin, OUTPUT);
  pinMode(echo_Pin, INPUT);
  Serial.begin(9600);
  delay(2000);
}

void loop()
{
  values=(get_distance_Value()+','+get_IR_Sensor1_Value+','+get_IR_Value);
  delay(1000);
  Serial.flush();
  delay(1000);
  Serial.print(values);
  delay(2000)
}

String get_distance_Value()
{
  digitalWrite(trig_Pin,HIGH);
  delay(10);
  digitalWrite(trig_pin, LOW);
  time= pulseIn(echo_Pin, HIGH);
  distance=(time*0.034)/2;
  return String(distance);
  
}
String get_IR_sensor1_Value()
{
  IR_sensor1_Value=analogRead(IR_sensor1Pin);
  delay(1000);
  return String(IR_sensor1_Value)
}
String get_IR_sensor2_Value()
{
  IR_sensor2_Value=analogRead(IR_sensor2Pin);
  delay(1000);
  return String(IR_sensor2_Value);
}
