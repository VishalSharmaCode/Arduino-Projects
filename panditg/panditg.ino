#include <LiquidCrystal_I2C.h>

#include <Keypad.h>
LiquidCrystal_I2C lcd(0x27,16,2);

int relay=33;
#define ROW_NUM     4  // four rows
#define COLUMN_NUM  4  // four columns
//int RELAY_PIN= 19;

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte pin_rows[ROW_NUM]      = {13, 12, 14, 27}; 
byte pin_column[COLUMN_NUM] = {26, 25, 32, 35 };   

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );


const String password_1 = "1234"; // change your password here
const String password_2 = "5678";  // change your password here
const String password_3 = "5454";  // change your password here
String input_password;

void setup() 
{
  Serial.begin(115200);
  input_password.reserve(32); // maximum input characters is 32
  pinMode(relay, OUTPUT); 
  digitalWrite(relay, HIGH);
  lcd.init();
                      
  lcd.backlight();
  lcd.print("Setting Lock");// lock the door
}

void loop()
{
  char key = keypad.getKey();
  
  if (key) 
  {
    Serial.println(key);

    if (key == '*') 
    {
      input_password = ""; // reset the input password
    }
    else if (key == '#')
    {
      if (input_password == password_1 || input_password == password_2 || input_password == password_3) {
        Serial.println("Valid Password => Door unlock");
        digitalWrite(relay, LOW); 
        lcd.clear();
        lcd.print("Door Unlock");  // unlock the door for 10 seconds
        delay(10000);
        lcd.clear();
        lcd.print("Door Lock");
        lcd.clear();
        digitalWrite(relay, HIGH); // lock the door
      } 
      else 
      {
        Serial.println("Invalid Password => Try again");
      }

      input_password = ""; // reset the input password
    }
    else 
    {
      input_password += key; // append new character to input password string
    }
  }
}
