int relay=33;
void setup() {
  pinMode(relay,OUTPUT);
}

void loop() {
  digitalWrite(relay,HIGH);
  delay(2000);
  digitalWrite(relay,LOW);
  delay(2000);
}
