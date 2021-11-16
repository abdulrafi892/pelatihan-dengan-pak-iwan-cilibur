//INISIALISIS  
  int pinLDR    =A0;
  int pinBuzzer =5;
  int pinLED    =3;

void setup() {
  Serial.begin(9600);
  pinMode(pinBuzzer,OUTPUT);
  
}

void loop() {
 //BACADATA
 int bacaLDR=analogRead(pinLDR);
     bacaLDR=map(bacaLDR,0,1024,0,255);
 //PRINTSEERIAL
 Serial.print("Nilai LDR : ");
 Serial.print(bacaLDR);
 Serial.println();
//lOGIKA
if(bacaLDR){
analogWrite(pinLED,bacaLDR);
}
  
//else{
//  digitalWrite(pinLED,pinLED
}
