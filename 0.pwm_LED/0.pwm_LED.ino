int R=2;
int Y=3;
int G=4;

void setup() {
Serial.begin(9600);
for (int i=2; i<=4; i++){
pinMode(i,OUTPUT);
}

}
 
void loop() {
  for (int i=2; i<=255; i++){
 analogWrite(3,i);
 //float volt=map(i,0,255,0,5);
 float volt=(5.0/255.0); ////Konversi Nilai PWM ke Volt dari 0-255 menjadi 0-5
 float hasil = i*volt;
 Serial.print("volt :");
 Serial.println(hasil);
 delay(10);
  }
  for (int i=255; i>=0; i--){
 analogWrite(3,i);
//float volt=map(i,0,255,0,5);
 float volt=(5.0/255.0); ////Konversi Nilai PWM ke Volt dari 0-255 menjadi 0-5
 float hasil = i*volt;
 Serial.print("volt :");
 Serial.println(hasil);
 delay(10);
 }
  
}
