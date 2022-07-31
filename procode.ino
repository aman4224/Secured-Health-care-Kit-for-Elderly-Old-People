#include <SoftwareSerial.h>
 #define LED 13
 int ecg=1;
 int tem=2;
 int eye=3;
 int gul=4;
 int b1;
SoftwareSerial iot(9,10);
SoftwareSerial mySerial(7, 8);
int b;
int c;
int d;
int d1;
int a;
int x;
void setup() {    
pinMode(ecg, INPUT);
pinMode(eye, INPUT);
pinMode(tem, INPUT);
pinMode(LED,OUTPUT);
Serial.begin(9600);
iot.begin(9600);
mySerial.begin(9600);
}
void loop() {
  x=(millis() / 1000);
  a=analogRead(gul);
  b=analogRead(ecg);
  c=analogRead(eye);
  d=analogRead(tem);
  d1=(d/2)-3;
if(c<300)
  {
    b1 = b1 + 1;  
    if (b1 > 1)
    {
   Serial.println("patient slept");
   Serial.println("");
  iot.println("patient slept");  
   mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
    delay(1000);  // Delay of 1000 milli seconds or 1 second
    mySerial.println("AT+CMGS=\"7984944418"); // Replace x with mobile number
    mySerial.write(0x22);
    mySerial.write(0x0D);  // hex equivalent of Carraige return
    mySerial.write(0x0A);  // hex equivalent of newline
    delay(2000);
    mySerial.println("patient slept");
    delay(500);
    mySerial.println((char)26);// ASCII code of CTRL+Z
    delay(1000);
   delay(5000);
}
  }
if (c>300)
  {
    b1 = 0;
  }
if(a>600)
  {
   Serial.println("LOW GLUCOSE LEVEL");
   Serial.println("");
  iot.println("*LOW GLUCOSE LEVEL#"); 
   mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
    delay(1000);  // Delay of 1000 milli seconds or 1 second
    mySerial.println("AT+CMGS=\"7984944418"); // Replace x with mobile number
    mySerial.write(0x22);
    mySerial.write(0x0D);  // hex equivalent of Carraige return
    mySerial.write(0x0A);  // hex equivalent of newline
    delay(2000);
    mySerial.println("LOW GLUCOSE LEVEL");
    delay(500);
    mySerial.println((char)26);// ASCII code of CTRL+Z
    delay(1000); 
   delay(5000);
}
if(b<700)
  { 
   Serial.println("ECG LEVEL LOW");
   Serial.println("");
  iot.println("*ECG LEVEL LOW#"); 
   mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
    delay(1000);  // Delay of 1000 milli seconds or 1 second
    mySerial.println("AT+CMGS=\"7984944418"); // Replace x with mobile number
    mySerial.write(0x22);
    mySerial.write(0x0D);  // hex equivalent of Carraige return
    mySerial.write(0x0A);  // hex equivalent of newline
    delay(2000);
    mySerial.println("ECG LEVEL LOW");
    delay(500);
    mySerial.println((char)26);// ASCII code of CTRL+Z
    delay(1000); 
   delay(5000);
}
if(d1>40)
    {
   Serial.println("HIGH TEMPERATURE");
   Serial.println("");
  iot.println("*HIGH TEMPERATURE#"); 
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
    delay(1000);  // Delay of 1000 milli seconds or 1 second
    mySerial.println("AT+CMGS=\"7984944418"); // Replace x with mobile number
    mySerial.write(0x22);
    mySerial.write(0x0D);  // hex equivalent of Carraige return
    mySerial.write(0x0A);  // hex equivalent of newline
    delay(2000);
    mySerial.println("HIGH TEMPERATURE");
    delay(500);
    mySerial.println((char)26);// ASCII code of CTRL+Z
    delay(1000);  
   delay(5000);
}
 if(x>10)
  {
  Serial.print("TEMPERATURE=");
  Serial.println(d1);
   Serial.println("");
  delay(2000);
  }

}

