#include <OneWire.h>
#include <DallasTemperature.h>//for temperature sensor
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);  
DallasTemperature sensors(&oneWire);
void setup()
{
  sensors.begin();
  Serial.begin(9600); 
}
void loop()
{
  sensors.requestTemperatures();
  Serial.print("Temperature: ");
  Serial.print(sensors.getTempCByIndex(0));
  Serial.print((char)176);
  Serial.print("C  |  ");//temperature in celcius
  Serial.println("C");
 
  delay(500);
}
