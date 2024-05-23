#include <SoftwareSerial.h>

SoftwareSerial Arduino_SoftSerial(15,14); //RX, TX

//Below is Global Variable Data
char c;
String dataIn;
int8_t  indexOfA, indexOfB, indexOfC, indexOfD, indexOfE, indexOfF, 
        indexOfG, indexOfH, indexOfI, indexOfJ, indexOfK, indexOfL;

String  data1, data2, data3, data4, data5, data6,
        data7, data8, data9, data10, data11, data12;


void setup() {
  // put your setup code here, to run once:

    //Open Serial Communication (Arduino-PC)
    Serial.begin(195200);

    //Open Serial Communication (Arduino-NodeMcu)
    Arduino_SoftSerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

    while(Arduino_SoftSerial.available()>0)
      {
          c = Arduino_SoftSerial.read();

          if(c=='\n') {break;}
          else        {dataIn+=c;}
      }

    if(c=='\n')
      {
          Parse_the_Data();

          //Show All Data to Serial Monitor
          Serial.println("Data1 = " + data1);
          Serial.println("Data2 = " + data2);
          Serial.println("Data3 = " + data3);
          Serial.println("Data4 = " + data4);
          Serial.println("Data5 = " + data5);
          Serial.println("Data6 = " + data6);
          Serial.println("Data7 = " + data7);
          Serial.println("Data8 = " + data8);
          Serial.println("Data9 = " + data9);
          Serial.println("Data10 = " + data10);
          Serial.println("Data11 = " + data11);
          Serial.println("Data12 = " + data12);
          Serial.println("==========================================");

          //Reset the Variable
          c=0;
          dataIn="";
      }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Parse_the_Data()
{
    indexOfA = dataIn.indexOf("A");
    indexOfB = dataIn.indexOf("B");
    indexOfC = dataIn.indexOf("C");
    indexOfD = dataIn.indexOf("D");
    indexOfE = dataIn.indexOf("E");
    indexOfF = dataIn.indexOf("F");
    indexOfG = dataIn.indexOf("G");
    indexOfH = dataIn.indexOf("H");
    indexOfI = dataIn.indexOf("I");
    indexOfJ = dataIn.indexOf("J");
    indexOfK = dataIn.indexOf("K");
    indexOfL = dataIn.indexOf("L");

    data1  = dataIn.substring (0, indexOfA);
    data2  = dataIn.substring (indexOfA+1, indexOfB);
    data3  = dataIn.substring (indexOfB+1, indexOfC);
    data4  = dataIn.substring (indexOfC+1, indexOfD);
    data5  = dataIn.substring (indexOfD+1, indexOfE);
    data6  = dataIn.substring (indexOfE+1, indexOfF);
    data7  = dataIn.substring (indexOfF+1, indexOfG);
    data8  = dataIn.substring (indexOfG+1, indexOfH);
    data9  = dataIn.substring (indexOfH+1, indexOfI);
    data10 = dataIn.substring (indexOfI+1, indexOfJ);
    data11 = dataIn.substring (indexOfJ+1, indexOfK);
    data12 = dataIn.substring (indexOfK+1, indexOfL);
}
