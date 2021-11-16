//inisialisi
#include <NewPing.h>

int echo =11;
int trig =12;
int batas =200; //Maksimal 400 cm
int buzzer =2;
int R=8;
int Y=9;
int G=10;


NewPing cm(trig,echo,batas);

void setup() {
 Serial.begin(9600);
 pinMode(buzzer,OUTPUT);
 pinMode(R,OUTPUT);
 pinMode(Y,OUTPUT);
 pinMode(G,OUTPUT);
}

void loop() {
//baca sensor
 int bacaJarak=cm.ping_cm();
 //Print ke Serial Monitor
 Serial.print("Data jarak:");
 Serial.print(bacaJarak);
 Serial.print(" cm");
 Serial.println();
 delay(500); //Jeda waktu perulagan seama 500 mili detik
 



//logika
//parkir mobil
if (bacaJarak <=20 && bacaJarak !=0){
digitalWrite(buzzer,HIGH);
digitalWrite(R,HIGH);
digitalWrite(Y,LOW);
digitalWrite(G,LOW);
Serial.println("berhenti");

}else if(bacaJarak >=21 && bacaJarak <=70){
digitalWrite(buzzer,HIGH);
digitalWrite(Y,HIGH);
digitalWrite(R,LOW);
digitalWrite(G,LOW);
Serial.println("BAHAYA!!!");

}else if (bacaJarak >=71){
  digitalWrite(buzzer,LOW);
  digitalWrite(G,HIGH);
digitalWrite(R,LOW);
  digitalWrite(Y,LOW);
Serial.println("aman");
 }
 }
