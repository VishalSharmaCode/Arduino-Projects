int channel_2 = 6;  // pin with ~ symbol

void setup() {
  // put your setup code here, to run once:
 pinMode(channel_2, INPUT);
 Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:
int value = pulseIn(channel_2, HIGH, 25000);
Serial.println(value);
delay(10);
}
