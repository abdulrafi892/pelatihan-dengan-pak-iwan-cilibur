//inisialisi
//UNTUK TOMBOL
int tombol1=2;
int tombol2=3;
int tombol3=4;
int kunci1=0;
int kunci2=0;
int kunci3=0;

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
  Serial.println("kondisi Tombol1:" + String (bacaTombol1));
  Serial.println("kondisi Tombol3:" + String (bacaTombol2));
  Serial.println("kondisi Tombol3:" + String (bacaTombol3));
  Serial.println();
  

  //LOGIKA
  //START TOMBOL1
  if(bacaTombol1==1 );
  //END TOMBOL1

}
