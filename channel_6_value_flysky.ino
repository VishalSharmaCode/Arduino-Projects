int channel_1=13;
int channel_2=12;
int channel_3=14;
int channel_4=A1;
int channel_5=26;
int channel_6=25;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  int value1 = pulseIn(channel_1, HIGH, 25000);
  int value2 = pulseIn(channel_2, HIGH,25000);
  int value3 = pulseIn(channel_3, HIGH,25000);
  int value4 = pulseIn(channel_4, HIGH,25000);
  int value5 = pulseIn(channel_5, HIGH,25000);
  int value6 = pulseIn(channel_6, HIGH,25000);
  Serial.print(value1);
  Serial.print("   ");
    Serial.print(value2);
  Serial.print("   ");
    Serial.print(value3);
  Serial.print("   ");
    Serial.print(value4);
  Serial.print("   ");
    Serial.print(value5);
  Serial.print("   ");
    Serial.print(value6);
  Serial.println("   ");
    delay(10);
}
