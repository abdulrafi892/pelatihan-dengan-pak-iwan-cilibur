//inisialisi
//UNTUK TOMBOL
int tombol1=2;
int tombol2=3;
int tombol3=4;

//UNTUK LED
int R=5;
int Y=6;
int G=7;

void setup() {
Serial.begin(9600);
pinMode(tombol1,INPUT);
pinMode(tombol2,INPUT);
pinMode(tombol3,INPUT);
pinMode(R,OUTPUT);
pinMode(Y,OUTPUT);
pinMode(G,OUTPUT);

}
void loop() {
  int bacaTombol1=digitalRead(tombol1);
  int bacaTombol2=digitalRead(tombol2);
  int bacaTombol3=digitalRead(tombol3);

  //SERIAL PRINT
  Serial.print("kondisi Tombol1");Serial.print(bacaTombol1);
  Serial.print(" | kondisi Tombol2");Serial.print(bacaTombol2);
  Serial.print(" | kondisi Tombol3");Serial.print(bacaTombol3);
  Serial.println();

  //LOGIKA
  //START TOMBOL1
  if(bacaTombol1==1){
    digitalWrite(R,HIGH);
  }else{
    digitalWrite(R,LOW);
  }
  //END TOMBOL1

  //START TOMBOL2
  if(bacaTombol1==1){
    digitalWrite(Y,HIGH);
  }else{
    digitalWrite(Y,LOW);
  }
  //END TOMBOL2

  //START TOMBOL3
  if(bacaTombol3==1){
    digitalWrite(G,HIGH);
  }else{
    digitalWrite(G,LOW);
  }
  //END TOMBOL3
}
