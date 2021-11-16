//inisialisi
#include <OneWire.h>
#include <DallasTemperature.h>

int sensorsuhu =2;
int buzzer =5;
int R=8;
int G=9;
OneWire oneWire (sensorsuhu);
DallasTemperature sensors(&oneWire);
void setup() {
 Serial.begin(9600);
 sensors.begin();
 pinMode(buzzer,OUTPUT);
 pinMode(R,OUTPUT);
 pinMode(G,OUTPUT);
}

void loop() {
//baca sensor
 sensors.requestTemperatures();
 float bacaSuhu = sensors.getTempCByIndex(0);
 //printserial
 Serial.print("suhu :");
 Serial.print(bacaSuhu);
 Serial.print(" c");
 Serial.println();//enter
 

//logika
 if ("bacaSuhu <=30");
 digitalWrite(buzzer,HIGH);
 digitalWrite(R,HIGH);
 }else}("bacaSuhu >=29");
 digitalWrite(buzzer,LOW);
 digitalWrite(G,LOW);
 
 
}
