//inisialisi
int tombol1=2;
int tombol2=3;
int tombol3=4;

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
  Serial.print("kondisi Tombol1");
  Serial.print(bacaTombol1);
  Serial.println();

  if(bacaTombol1==1){
    digitalWrite(R,HIGH);
  }else{
    digitalWrite(R,LOW);
  }
  int bacaTombol2=digitalRead(tombol2);
  Serial.print("kondisi Tombol2");
  Serial.print(bacaTombol2);
  Serial.println();

  if(bacaTombol2==2){
    digitalWrite(Y,HIGH);
  }else{
    digitalWrite(Y,LOW);
  }
  int bacaTombol3=digitalRead(tombol3);
  Serial.print("kondisi Tombol3");
  Serial.print(bacaTombol3);
  Serial.println();

  if(bacaTombol3==3){
    digitalWrite(G,HIGH);
  }else{
    digitalWrite(G,LOW);
}
}
