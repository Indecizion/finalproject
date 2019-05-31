#include <Servo.h>
int TL;
int TR;
int BL;
int BR;
int T = 1;
Servo Xservo;
Servo Yservo;
int Xloc;
int Yloc;

void setup() 
{
  Xservo.attach(9);
  Yservo.attach(10); 
  Serial.begin(9600);
}

void loop() {
  TL = analogRead(A0);
  TR = analogRead(A1);
  BL = analogRead(A2);
  BR = analogRead(A3);
  Xloc = Xservo.read();
  Yloc = Yservo.read();
  while(true)
  {
  Serial.println("Top left, top right, bottom left, bottom right, location of x, location of y:");
  Serial.println(TL, DEC);
  Serial.println(TR, DEC);
  Serial.println(BL, DEC);
  Serial.println(BR, DEC);
  Serial.println(Xloc, DEC);
  Serial.println(Yloc, DEC);
  delay(1000);
  }
  if (TL > TR) {
    Xloc = Xloc + 5;
    Xservo.write(Xloc);
    delay(T);
  }
  if (BL > BR) {
    Xloc = Xloc + 5;
    Xservo.write(Xloc);
    delay(T);
  }
  if (TL < TR) {
    Xloc = Xloc - 5;
    Xservo.write(Xloc);
    delay(T);
  }
  if (BL < BR) {
    Xservo.write(Xloc);
    delay(T);
  }
  if (TL > BL) {
    Yloc = Yloc - 5;
    Yservo.write(Yloc);
    delay(T);
  }
  if (TR > TL) {
    Yloc = Yloc - 5;
    Yservo.write(Yloc);
    delay(T);
  }
  if (TL < BL) {
    Yloc = Yloc + 5;
    Yservo.write(Yloc);
    delay(T);
  }
  if (TR < BR) {
    Yloc = Yloc + 5;
    Yservo.write(Yloc);
    delay(T);
  }
}

/* 
ORIGINAL CODE
 
int TL;
int TR;
int BL;
int BR;
int T = 1;

void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  TCCR1A = 0;
  TCCR1A = (1 << COM1A1) | (1 << COM1B1) | (1 << WGM11);
  TCCR1B = 0;
  TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS11);
  ICR1 = 40000;
  OCR1A = 3000;
  OCR1B = 3600;
}

void loop() {
  TL = analogRead(A0);
  TR = analogRead(A1);
  BL = analogRead(A2);
  BR = analogRead(A3);

  if (TL > TR) {
    OCR1A = OCR1A + 1;
    delay(T);
  }
  if (BL > BR) {
    OCR1A = OCR1A + 1;
    delay(T);
  }
  if (BL < TR) {
    OCR1A = OCR1A - 1;
    delay(waittime);
  }
  if (BL < BR) {
    OCR1A = OCR1A - 1;
    delay(T);
  }
  if (OCR1A > 4000) {
    OCR1A = 4000;
  }
  if (OCR1A < 2000) {
    OCR1A = 2000;
  }
  if (TL > BL) {
    OCR1B = OCR1B - 1;
    delay(T);
  }
  if (TR > BR) {
    OCR1B = OCR1B - 1;
    delay(T);
  }
  if (TL < BL) {
    OCR1B = OCR1B + 1;
    delay(T);
  }
  if (TR < BR) {
    OCR1B = OCR1B + 1;
    delay(T);
  }
  if (OCR1B > 4200) {
    OCR1B = 4200;
  }
  if (OCR1B < 3000) {
    OCR1B = 3000;
  }
}



*/
