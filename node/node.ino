#include <SoftwareSerial.h>

SoftwareSerial NodeMcu_SoftSerial(1,2); //RX, TX

int data1, data2, data3, data4;
float data5, data6, data7, data8;
String data9, data10, data11, data12;

void setup() {
  // put your setup code here, to run once:

    //Open Serial Communication (NodeMcu-PC)
    Serial.begin(57600);

    //Open Serial communication (NodeMcu-Arduino)
    NodeMcu_SoftSerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

    data1 = 800;
    data2 = 900;
    data3 = 1000;
    data4 = 10000;

    data5 = 12.12345;
    data6 = 123.1234;
    data7 = 1234.123;
    data8 = 12345.12;
    
    data9 = "Thanks";
    data10 = "For";
    data11 = "Watching";
    data12 = "Guys!";

    NodeMcu_SoftSerial.print(data1);      NodeMcu_SoftSerial.print("A");
    NodeMcu_SoftSerial.print(data2);      NodeMcu_SoftSerial.print("B");
    NodeMcu_SoftSerial.print(data3);      NodeMcu_SoftSerial.print("C");
    NodeMcu_SoftSerial.print(data4);      NodeMcu_SoftSerial.print("D");
    NodeMcu_SoftSerial.print(data5, 5);   NodeMcu_SoftSerial.print("E");
    NodeMcu_SoftSerial.print(data6, 4);   NodeMcu_SoftSerial.print("F");
    NodeMcu_SoftSerial.print(data7, 3);   NodeMcu_SoftSerial.print("G");
    NodeMcu_SoftSerial.print(data8, 2);   NodeMcu_SoftSerial.print("H");
    NodeMcu_SoftSerial.print(data9);      NodeMcu_SoftSerial.print("I");
    NodeMcu_SoftSerial.print(data10);     NodeMcu_SoftSerial.print("J");
    NodeMcu_SoftSerial.print(data11);     NodeMcu_SoftSerial.print("K");
    NodeMcu_SoftSerial.print(data12);     NodeMcu_SoftSerial.print("L");
    NodeMcu_SoftSerial.print("\n");

    delay(500);

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
