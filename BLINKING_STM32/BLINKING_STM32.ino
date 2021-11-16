#include <STM32ADC.h>

//INISIALISI
int R=PA0;
int Y=PA1;
int G=PA2;
int buzzer=PA3;
int tombol1=PA4;
int tombol2=PA5;
int tombol3=PA6;

void setup() {
  //BAACA DATA
 pinMode(R,OUTPUT);
 pinMode(Y,OUTPUT);
 pinMode(G,OUTPUT);
 pinMode(buzzer,OUTPUT);
 pinMode(tombol1,INPUT);
 pinMode(tombol2,INPUT);
 pinMode(tombol3,INPUT);



}

void loop() {
 //baca sensor
  int bacaTombol1=digitalRead(tombol1);
  int bacaTombol2=digitalRead(tombol2);
  int bacaTombol3=digitalRead(tombol3);
  //serial print
  Serial.println("kondisi Tombol1:" + String (bacaTombol1));
  Serial.println("kondisi Tombol3:" + String (bacaTombol2));
  Serial.println("kondisi Tombol3:" + String (bacaTombol3));
  Serial.println();
  
  //LOGIKA
  if(bacaTombol1==1){
    digitalWrite(R,HIGH);
  }else{
    digitalWrite(R,LOW);
  }
 
  if(bacaTombol2==1){
    digitalWrite(Y,HIGH);
  }else{
    digitalWrite(Y,LOW);
  }

  if(bacaTombol3==1){
    digitalWrite(G,HIGH);
  }else{
    digitalWrite(G,LOW);
}
}
  
