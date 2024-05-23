#define SW 27

void setup() {
  Serial.begin(9600);
  pinMode(SW,INPUT);
  digitalWrite(SW,HIGH);
}

void loop() {
  Serial.print("VRX_value=");
  int X_value=analogRead(25);
  Serial.print(X_value);
  Serial.print("\t");

  Serial.print("VRY_value=");
  int Y_value=analogRead(26);
  Serial.print(Y_value);
  Serial.print("\t");

  Serial.print("Switch_value=");
  int switch_value=digitalRead(SW);
  Serial.print(switch_value);
  Serial.println("\t");

  delay(2000);
  

}