//Download dan masukan Library 
#include <Servo.h>
//Inisialisasi pembuatan variable
int outServo=5; //Pin untuk Servo
Servo myservo;
void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(9600); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 myservo.attach(outServo); 
}
void loop() {
 //Program yang akan dijalankan berulang-ulang
 myservo.write(0); //0-180
 delay(1000); //Jeda waktu perulagan seama 500 mili detik
 myservo.write(120); //0-180
 delay(1000); //Jeda waktu perulagan seama 500 mili detik
}
