#include<WiFi.h>
#include <IOXhop_FirebaseESP32.h>
char ssid[] = "Redmi9";
char password[] = "panditvishal";
char firebaseHost[] = "https://agriculture-cf703-default-rtdb.asia-southeast1.firebasedatabase.app";
char firebaseKey[] = "AIzaSyCkhmLh-aT4JITYlSkxJPLY_BPH4TwXxOo";
int _moisture,sensor_analog;
const int sensor_pin = 36; 
//Water lavel
#define SIGNAL_PIN 39 // ESP32 pin GIOP36 (ADC0) connected to sensor's signal pin
#define SENSOR_MIN 0
#define SENSOR_MAX 521
int value = 0; // variable to store the sensor value
int level = 0;
void setup() {
  Serial.begin(9600);
    WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
    Serial.print("*");
    delay(500);
  }
  Serial.println("WiFi Connected");
  Firebase.begin(firebaseHost, firebaseKey);
  Serial.println("Firebase Connected");
}

void loop()  {
  sensor_analog = analogRead(sensor_pin);
_moisture = ( 100 - ( (sensor_analog/4095.00) * 100 ) );
 Serial.print("Moisture = ");
 Serial.print(_moisture);
 Serial.println("%");
    Firebase.setFloat("Moisture",_moisture ); 
    value = analogRead(SIGNAL_PIN);
 Serial.println(value);   
    if( value>500)
    {
     Firebase.setBool("water_lavel", true);
            }
           else{
             Firebase.setBool("water_lavel", false);
           }        
            
    Serial.println();
  }
