#include <Wire.h>

void setup() {
  Wire.begin();        // Initialize I2C communication as a master
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  Wire.beginTransmission(0x08); // Start communication with the ESP32 (replace with the correct I2C address of your ESP32)
  Wire.write("Hello, ESP32!");// Send data
  Wire.endTransmission();       // End the transmission

  delay(1000); // Wait for a second before sending data again
}
