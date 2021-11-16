#include <SPI.h>
#include <MFRC522.h>

String uidString;
int buzzer=2;
int infrared=7;
int kunci=0;
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);
void setup() {
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  pinMode(infrared,INPUT);
  SPI.begin();//initiate spi buzz
  mfrc522.PCD_Init();
  Serial.println("tempelkan kartu");

}

void loop() {
  //baca data
  int readinfrared=digitalRead(infrared);//sensor
  if (mfrc522.PICC_IsNewCardPresent()and kunci==0) {
    readRFID();
    Serial.print("Tag.UID: ");
    Serial.println(uidString);
    
  if(uidString=="A732894B"){
    bunyibuzzeroke();
    kunci=1;
    Serial.println("BERHASIL");
    delay(1000);
    Serial.println("Silakan masuk");
   
  }else{
    kunci=0;
    Serial.println("GAGAL");
    bunyibuzzergagal();
  }
  }
  if(readinfrared== 0 and kunci ==1){
    Serial.print("ketutup");
      bunyibuzzergagal();
      delay(1000);
      kunci=0;
  }
}


void readRFID(){
mfrc522.PICC_ReadCardSerial();
//pembatas bisa diubah sesuia keinginan
uidString = String(mfrc522.uid.uidByte[0],HEX) + "" +
            String(mfrc522.uid.uidByte[1],HEX) + "" +
            String(mfrc522.uid.uidByte[2],HEX) + "" +
            String(mfrc522.uid.uidByte[3],HEX);
            uidString.toUpperCase();
  }
  
void bunyibuzzeroke(){
digitalWrite(buzzer,HIGH);
delay(150);
digitalWrite(buzzer,LOW);
delay(150);

}

void bunyibuzzergagal(){
digitalWrite(buzzer,HIGH);
delay(150);
digitalWrite(buzzer,LOW);
delay(150);
}
