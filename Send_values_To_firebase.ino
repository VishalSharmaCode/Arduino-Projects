#include<WiFi.h>
#include<IOXhop_FirebaseESP32.h>//https://github.com/ArtronShop/IOXhop_FirebaseESP32

char ssid[]="Redmi9";
char password[]="vishalsharmaji";
char firebaseHost[]="https://kuj-bhi-deeeb-default-rtdb.asia-southeast1.firebasedatabase.app/";
char firebaseKey[]="AIzaSyBaq8eSJwsmQZdbaEdcfWjuEhx31lT5pKQ";

void setup(){
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print("*");
    delay(500);
  }
  Serial.println("WiFi Connected");
  Firebase.begin(firebaseHost,firebaseKey);
  Serial.println("Firebase Connected");
}
void loop(){
  int randomValue = random(0, 100);
  Serial.println(randomValue);
  Firebase.setFloat("randomvalue",randomValue);
 

 
//  Serial.println("Enter a value:");
//  while (Serial.available() == 0) {
//  }
//  int input = Serial.parseInt();
//  Serial.print("You entered: ");
//  Serial.println(input);
//  Firebase.setInt("Input",input);
//  if (input<=50){
//    Firebase.setBool("myName",false);
//  }
//  else
//  {
//  Firebase.setBool("myName",true);
//  }

}
