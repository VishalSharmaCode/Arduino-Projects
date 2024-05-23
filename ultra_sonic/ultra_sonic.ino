const int trigPin1 = 7;//for ultra sensor one 
const int echoPin1 = 8;//for ultra sensor one
long duration1;//for ultra sensor one
int distance1;//for ultra sensor one
void setup()
{
pinMode(trigPin1, OUTPUT); 
pinMode(echoPin1, INPUT);
Serial.begin(115200);
}
void loop()
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
