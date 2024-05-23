
int x,y;
float TIME=0,FREQUENCY=0,WATER=0,TOTAL=0,LS=0;
const int flow=14;
void setup()
{
  pinMode(flow,0);
  Serial.begin(9600); 
}
void loop()
{
  x=pulseIn(flow,1);
  y=pulseIn(flow,0);
  TIME=x+y;
  FREQUENCY=1000000/TIME;
  WATER=FREQUENCY/7.5;
  LS=WATER/60;
  if(FREQUENCY>=0)
  {
    if(isinf(FREQUENCY))
    {
      Serial.println("VOL. :0.00");
      Serial.println("TOTAL: ");
      Serial.print(TOTAL);
    }
    else
    {
      TOTAL=TOTAL+LS;
      Serial.println(FREQUENCY);
      Serial.println("Vol.: ");
      Serial.print(WATER);
      Serial.print(" L/M");
      Serial.println("TOTAL: ");
      Serial.print(TOTAL);
      Serial.print(" L");
     }
  }
  
}
