#include <Servo.h>
#include<SPI.h>
#include<MFRC522.h>
#include <LiquidCrystal_I2C.h>

//Inisialisasi pembuatan variable
String uidString;

int buzzer=2;
int infrared=3;
int outServo=5;
int kunci=0;

#define SS_PIN 10
#define RST_PIN 9
Servo myservo;
MFRC522 mfrc522(SS_PIN, RST_PIN);  //Create MRFC522 Instance
LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  pinMode(infrared,INPUT);
  myservo.attach(outServo);
  SPI.begin();
  mfrc522.PCD_Init();
  lcd.begin();
  lcd.clear();
  lcd.setCursor(0,0); lcd.print("TEMPELKAN KARTU");
  delay(1000);
  }

void loop() {
  int bacaIR=digitalRead(infrared);
  int bacaservo=digitalRead(outServo);
  if(mfrc522.PICC_IsNewCardPresent() and kunci==false){
  readRFID();
  Serial.print("tag UID; ");
  Serial.println(uidString);
  if(uidString=="A7-32-89-4B"){
  kunci=true;
  bunyiBuzzer();
  lcd.clear(); //Untuk Menghapus karakter pada LCD
  lcd.setCursor(4,0); lcd.print("BERHASIL");
  delay(1000);
  lcd.setCursor(0,0); lcd.print("SILAHKAN MASUK ");
  delay(1000);
  lcd.setCursor(0,0); lcd.print("PLANG DIBUKA   ");
  delay(1000);
  myservo.write(90); //0-120
  delay(1000); //Jeda waktu perulagan seama 500 mili detik

  }else{
  kunci=false;
  bunyiBuzzerGagal();
  lcd.clear();
  lcd.setCursor(0,0); lcd.print("GAGAL");
  delay(1000);
  lcd.setCursor(0,0); lcd.print("TEMPELKAN KARTU");
  delay(1000);
  
    }
  }

if(bacaIR==false && kunci==true){
  kunci=false;
  bunyiBuzzer();
  lcd.setCursor(0,0); lcd.print("SUDAH MASUK    ");
  delay(1000);
  myservo.write(0); //0-120
  delay(1000); //Jeda waktu perulagan seama 500 mili detik
  lcd.setCursor(0,0); lcd.print("PLANG DITUTUP  ");
  delay(1000);
  lcd.setCursor(0,0); lcd.print("TEMPELKAN KARTU  ");
  delay(1000);
  }
  
}
