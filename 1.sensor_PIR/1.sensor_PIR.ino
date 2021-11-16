//INISIALISIS  
  int pinPIR    =2;
  int pinBuzzer =5;

void setup() {
  Serial.begin(9600);
  pinMode(pinPIR,INPUT);
  pinMode(pinBuzzer,OUTPUT);
  
}

void loop() {
 //BACADATA
 int bacaPIR=digitalRead(pinPIR);

 //PRINTSEERIAL
 Serial.print("Nilai PIR : ");
 Serial.print(bacaPIR);
 Serial.println();
//lOGIKA
if (bacaPIR==1){
  digitalWrite(pinBuzzer,HIGH);
  delay(100);
  digitalWrite(pinBuzzer,LOW);
  delay(100);
  Serial.println("ADA MALING!!");
}else{
  digitalWrite(pinBuzzer,LOW);
  
}
}
