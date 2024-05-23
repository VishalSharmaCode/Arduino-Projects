#include<Wire.h>
#include<MPU6050.h>
MPU6050 mpu;
void setup()
{
  Serial.begin(115200);
  Serial.println("initilization");
  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    Serial.println("could not valid");
    delay(500);
    }
}
void loop()
{
  Vector rawGyro=mpu.readRawGyro();
  vector normGyro=mpu.readNormalizeGyro();
  Serial.print("xraw=");
  Serial.print(rawGyro.XAxis);
  Serial.print("yraw=");
  Serial.print(rawGyro.YAxis);
  Serial.print("Zraw=");
  Serial.print(rawGyro.ZAxis);
  
}
