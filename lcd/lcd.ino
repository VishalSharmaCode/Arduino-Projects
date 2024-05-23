// #include <Wire.h>           
// #include <LiquidCrystal_I2C.h>   
//  LiquidCrystal_I2C lcd(0x27,16,2);   
// // if lcd is not print then use this 0x27..  
// void setup()  
//  {  
//   lcd.begin();      
//   lcd.backlight();  
//  }  
// void loop()   
//  {  
//   lcd.setCursor(0,0);  
//   lcd.print("   Helo  ");  
//   lcd.setCursor(0,1);  
//   lcd.print("  Friend ");  
//  }  
#include <LiquidCrystal_I2C.h>

// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;

// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

void setup(){
  // initialize LCD
//  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
}

void loop(){
  // set cursor to first column, first row
  lcd.setCursor(0, 0);
  // print message
  lcd.print("Hello, World!");
  delay(1000);
  // clears the display to print new message
  lcd.clear();
  // set cursor to first column, second row
  lcd.setCursor(0,1);
  lcd.print("Hello, World!");
  delay(1000);
  lcd.clear(); 
}
