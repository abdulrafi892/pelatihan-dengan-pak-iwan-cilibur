  int LED=2;
  int PIR=3;
  int LDR=A0;
  int FLAME=A1;
  int Buzzer=5;

  
void setup() {
  pinMode(LED,OUTPUT);
  pinMode(Buzzer,OUTPUT);
  pinMode(PIR,INPUT); 
  pinMode(LDR,INPUT);
  pinMode(FLAME,INPUT);
  

}

void loop() {
 //BACADATA
 int bacaFLAME=analogRead(FLAME);
 //maping
     bacaFLAME=map(bacaFLAME,1000,20,0,100);
     //Tampung=merubah data(tampung,dataawal sensor,dataakhir sensor,nilai)
 //PRINTSEERIAL
 Serial.print("Nilai FLAME : ");
 Serial.print(bacaFLAME);
 Serial.println();
//lOGIKA
if(bacaFLAME<=20){
  Serial.println("AMAN");
  delay(1000);
}else if(bacaFLAME>=21 and bacaFLAME<=80){
  Serial.println("WARNING");
}else{
  Serial.println("WASPADA");
}  

 //BACADATA
 int bacaPIR=digitalRead(PIR);

 //PRINTSEERIAL
 Serial.print("Nilai PIR : ");
 Serial.print(bacaPIR);
 Serial.println();
//lOGIKA
if (bacaPIR==1){
  digitalWrite(Buzzer,HIGH);
  delay(100);
  digitalWrite(Buzzer,LOW);
  delay(100);
  Serial.println("ADA MALING!!");
}else{
  digitalWrite(Buzzer,LOW);
  
}
 //BACADATA
 int bacaLDR=analogRead(LDR);
     bacaLDR=map(bacaLDR,0,1024,0,255);
 //PRINTSEERIAL
 Serial.print("Nilai LDR : ");
 Serial.print(bacaLDR);
 Serial.println();
//lOGIKA
if(bacaLDR){
analogWrite(LED,bacaLDR);
}
}
  
