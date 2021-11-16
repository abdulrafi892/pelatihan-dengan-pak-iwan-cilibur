//inisialisi
int R=PA0;
int Y=PA1;
int G=PA2;
int tombol1=PA3;
int tombol2=PA4;
int tombol3=PA5;
int flag=0;


void setup() {
  Serial.begin(9600);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(tombol1,INPUT);
  pinMode(tombol2,INPUT);
  pinMode(tombol3,INPUT);

}

void loop() {
//BACA DATA
  int bacaTombol1=digitalRead(tombol1);
  int bacaTombol2=digitalRead(tombol2);
  int bacaTombol3=digitalRead(tombol3);

//serial print
Serial.print("kondisiTombol1:" + String ("bacatombol1"));
Serial.print("kondisitombol2:" + String ("bacatombol2"));
Serial.print("kondisiTombol3:" + String ("bacatombol3"));
Serial.println();

//LOGIKA
//if(bacaTombol1==1){
//digitalWrite(R,HIGH);
//}else
//digitalWrite(R,LOW);

//if(bacaTombol2==1){
//digitalWrite(Y,HIGH);
//}else
//digitalWrite(Y,LOW);

//if(bacaTombol3==1){
//digitalWrite(G,HIGH);
//}else
//digitalWrite(G,LOW);

//}

//START TOMBOL1
  if(bacaTombol1==1 && flag ==0){
    flag =1;
    digitalWrite(R,HIGH);
    delay(500);
    Serial.println("ON");
  }else if (bacaTombol1==1 && flag ==1){
    flag=0;
    digitalWrite(R,LOW);
    delay(500);
    Serial.println("led OFF");
    //START TOMBOL2
   if(bacaTombol2==1 && flag ==0){
    flag =1;
    digitalWrite(Y,HIGH);
    delay(500);
    Serial.println("ON");
  }else if (bacaTombol2==1 && flag ==1){
    flag=0;
    digitalWrite(Y,LOW);
    delay(500);
    Serial.println("led OFF");
   }
    
  }
}
