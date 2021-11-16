//INISIALISIS  
  int pinFLAME    =A1;
  int pinBuzzer   =5;
bvnbn  int pinLED      R=5;
  int pinLED      Y=6;
  int pinLED      G=7;
void setup() {
  Serial.begin(9600);
  pinMode(pinFLAME,INPUT);
  pinMode(pinBuzzer,OUTPUT);
  
}

void loop() {
 //BACADATA
 int bacaFLAME=analogRead(pinFLAME);
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


 
  
}
//else{
//  digitalWrite(pinLED,pinLED
