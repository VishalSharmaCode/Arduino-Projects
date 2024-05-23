#include <LiquidCrystal.h>
#include<Wire.h>
LiquidCrystal
LiquidCrystal lcd(0*27, 16, 2);
int sensorPin=A0;
float volt;
float ntu;
void setup()
{
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
}
void loop()
{
  volt =0;
  for(int i=0;i<800;i++)
  {
    volt+=((float)analogRead(sensorPin)/1023)*5;
  }
  volt=volt/800;
  volt=round_to_dp(volt,2);
  if(volt<2.5)
  {
    ntu=3000;
  }
  else
  {
   ntu=-1120.4*square(volt)+5742.3*volt-4353.8; 
  }
  lcd.clear;
  lcd.setCursor(0,0);
  lcd.print(volt);
  lcd.print("V");

  lcd.setCursor(0,1);
  lcd.print(ntu);
  lcd.print("NTU");
  delay(10);
}
