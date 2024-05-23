#include <Wire.h>

void setup() {
  Wire.begin(0x08);  // Initialize I2C communication as a slave with address 0x08 (match with Arduino)
  Wire.onReceive(receiveEvent); // Set the receive event handler
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  // Your ESP32 code logic goes here
}

void receiveEvent(int byteCount) {
  while (Wire.available()) {
    int b=Wire.read();
    Serial.print(b);
//    char c = Wire.read(); // Read the data received from Arduino
//    Serial.print(c);      // Print the received data to the serial monitor
  }
}
