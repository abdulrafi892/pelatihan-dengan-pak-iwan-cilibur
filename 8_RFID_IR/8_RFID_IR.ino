//Download dan masukan Library MFRC522
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int Buzzer=2;
int infra=7;
//Inisialisasi pembuatan variable
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); 
void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(9600);
 SPI.begin(); 
 mfrc522.PCD_Init(); 
 pinMode(Buzzer,OUTPUT);
 pinMode(infra,INPUT);

}
void loop() {
 //Program yang akan dijalankan berulang-ulang
 if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
 // Select one of the cards
 if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
 
 //Show UID on serial monitor
 Serial.print("UID tag :");
 String content= "";
 byte letter;
 for (byte i = 0; i < mfrc522.uid.size; i++) 
 {
 Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
 Serial.print(mfrc522.uid.uidByte[i], HEX);
 content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : ""));
 content.concat(String(mfrc522.uid.uidByte[i], HEX));
 }
 Serial.println();
 Serial.print("Message : ");
 content.toUpperCase();
 if (content== "A732894B") //Sesuaikan dengan ID kartu anda
 {
 digitalWrite(Buzzer,HIGH);
 delay(150);
 Serial.println("Selamat datang rafi !!!");
 delay(2000);
 digitalWrite(Buzzer,LOW);
 delay(150);
 }else if(content== "04422D3A906180"){
 digitalWrite(Buzzer,HIGH);
 delay(150);
 Serial.println("Selamat datang BINTANG !!!");
 delay(2000);
 digitalWrite(Buzzer,LOW);
 delay(150);
 
 }else{
 Serial.println("Kartu Belum Terdaftar!");
 digitalWrite(Buzzer,HIGH);
 delay(150);
 digitalWrite(Buzzer,LOW);
delay(50);
 }
 Serial.println("Tempelkan Kartu!");
 delay(500);
  
}
 
